//
// Created by changwang on 1/18/20.
//
// Code from 《Understanding and using Pointers in C》 chapter 8
//
#include "apue.h"
#include <pthread.h>

typedef struct {
    double *vectorA;
    double *vectorB;
    double sum;
    int length;
} VectorInfo;

typedef struct {
    VectorInfo *info;
    int beginningIndex;
} Product;

pthread_mutex_t mutexSum;

void
dotProduct(void *prod)
{
    Product *product = (Product*) prod;
    VectorInfo *vectorInfo = product->info;
    int beginningIndex = product->beginningIndex;
    int endingIndex = beginningIndex + vectorInfo->length;
    double sum = 0;

    for(int i = beginningIndex; i < endingIndex; i++) {
        sum += (vectorInfo->vectorA[i] * vectorInfo->vectorB[i]);
    }

    pthread_mutex_lock(&mutexSum);
    vectorInfo->sum += sum;
    pthread_mutex_unlock(&mutexSum);

    pthread_exit((void*)0);
}

#define NUM_THREADS 4

int
main(void)
{
    VectorInfo vectorInfo;
    double vectorA[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
    double vectorB[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};

    vectorInfo.vectorA = vectorA;
    vectorInfo.vectorB = vectorB;
    vectorInfo.length = 4;

    pthread_t  threads[NUM_THREADS];

    void *status;
    pthread_attr_t attr;

    pthread_mutex_init(&mutexSum, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int returnValue;
    int threadNumber;

    for(threadNumber = 0; threadNumber < NUM_THREADS; threadNumber++) {
        Product *product = (Product*)malloc(sizeof(Product));
        product->beginningIndex = threadNumber * 4;
        product->info = &vectorInfo;

        returnValue = pthread_create(&threads[threadNumber], &attr, dotProduct, (void*)(void*)(product));
        if(returnValue) {
            err_sys("ERROR: unable to create thread: %d\n", returnValue);
        }
    }

    pthread_attr_destroy(&attr);

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &status);
    }

    pthread_mutex_destroy(&mutexSum);
    printf("Dot Product sum: %lf\n", vectorInfo.sum);
    pthread_exit(NULL);
}
