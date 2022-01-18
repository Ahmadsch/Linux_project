#include <time.h>
#include <stdio.h>
#include <string.h>
#include "func.h"

enum {
    ARRAY_SIZE_8 = 8,
    ARRAY_SIZE_32 = 32,
    ARRAY_SIZE_128 = 128,
    ARRAY_SIZE_512 = 512,
    ARRAY_SIZE_2048 = 2048,
    ARRAY_SIZE_8192 = 8192,
    ARRAY_SIZE_32768 = 32768
};

int array_8[ARRAY_SIZE_8];
int array_32[ARRAY_SIZE_32];
int array_128[ARRAY_SIZE_128];
int array_512[ARRAY_SIZE_512];
int array_2048[ARRAY_SIZE_2048];
int array_8192[ARRAY_SIZE_8192];
int array_32768[ARRAY_SIZE_32768];

double timeSpentQuick;
double timeSpentMerge;
double timeSpentInsert;
double timeSpentBubble;


//int array_100000[ARR_SIZE_100000];
//#define ARR_SIZE_100000 100000

void resetArrays();

double measureCpuRunTime(void (*pFunction)(int [], int, int), int arr[], int sizeOfArr, SORT_MODE sortMode);

void initArray(DATA_SET dataSet);

void printResults(int arraySize);

void initArray(DATA_SET dataSet) {
    createRandomNumber(ARRAY_SIZE_8, array_8, dataSet);
    createRandomNumber(ARRAY_SIZE_32, array_32, dataSet);
    createRandomNumber(ARRAY_SIZE_128, array_128, dataSet);
    createRandomNumber(ARRAY_SIZE_512, array_512, dataSet);
    createRandomNumber(ARRAY_SIZE_2048, array_2048, dataSet);
    createRandomNumber(ARRAY_SIZE_8192, array_8192, dataSet);
    createRandomNumber(ARRAY_SIZE_32768, array_32768, dataSet);
}

double measureCpuRunTime(void (*pFunction)(int [], int, int), int arr[], int sizeOfArr, SORT_MODE sortMode) {
    clock_t begin = clock();
    if (sortMode == MERGE_SORT || sortMode == QUICK_SORT) {
        int start = 0;
        (*pFunction)(arr, start, sizeOfArr);
    } else if (sortMode == INSERTION_SORT || sortMode == BUBBLE_SORT)
        (*pFunction)(arr, sizeOfArr, 0);
    clock_t end = clock();
    double timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
    return timeSpent;
}

void runMeasure_8() {
    int arrayQuick[ARRAY_SIZE_8];
    int arrayMerge[ARRAY_SIZE_8];
    int arrayInsert[ARRAY_SIZE_8];
    int arrayBubble[ARRAY_SIZE_8];

    for (int i = 0; i < ARRAY_SIZE_8; ++i) {
        arrayQuick[i] = array_8[i];
        arrayMerge[i] = array_8[i];
        arrayInsert[i] = array_8[i];
        arrayBubble[i] = array_8[i];
    }
    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_8, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_8, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_8, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_8, BUBBLE_SORT);

    printResults(ARRAY_SIZE_8);
}


void runMeasure_32() {
    int arrayQuick[ARRAY_SIZE_32];
    int arrayMerge[ARRAY_SIZE_32];
    int arrayInsert[ARRAY_SIZE_32];
    int arrayBubble[ARRAY_SIZE_32];

    for (int i = 0; i < ARRAY_SIZE_32; ++i) {
        arrayQuick[i] = array_32[i];
        arrayMerge[i] = array_32[i];
        arrayInsert[i] = array_32[i];
        arrayBubble[i] = array_32[i];
    }

    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_32, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_32, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_32, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_32, BUBBLE_SORT);

    printResults(ARRAY_SIZE_32);
}

void runMeasure_128() {
    int arrayQuick[ARRAY_SIZE_128];
    int arrayMerge[ARRAY_SIZE_128];
    int arrayInsert[ARRAY_SIZE_128];
    int arrayBubble[ARRAY_SIZE_128];

    for (int i = 0; i < ARRAY_SIZE_128; ++i) {
        arrayQuick[i] = array_128[i];
        arrayMerge[i] = array_128[i];
        arrayInsert[i] = array_128[i];
        arrayBubble[i] = array_128[i];
    }

    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_128, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_128, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_128, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_128, BUBBLE_SORT);

    printResults(ARRAY_SIZE_128);
}

void runMeasure_512() {
    int arrayQuick[ARRAY_SIZE_512];
    int arrayMerge[ARRAY_SIZE_512];
    int arrayInsert[ARRAY_SIZE_512];
    int arrayBubble[ARRAY_SIZE_512];

    for (int i = 0; i < ARRAY_SIZE_512; ++i) {
        arrayQuick[i] = array_512[i];
        arrayMerge[i] = array_512[i];
        arrayInsert[i] = array_512[i];
        arrayBubble[i] = array_512[i];
    }

    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_512, QUICK_SORT);
    //isSorted(ARRAY_SIZE_512,arrayQuick);
    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_512, MERGE_SORT);
    //isSorted(ARRAY_SIZE_512,arrayMerge);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_512, INSERTION_SORT);
    //isSorted(ARRAY_SIZE_512,arrayInsert);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_512, BUBBLE_SORT);
    //isSorted(ARRAY_SIZE_512,arrayBubble);

    printResults(ARRAY_SIZE_512);
}

void runMeasure_2048() {
    int arrayQuick[ARRAY_SIZE_2048];
    int arrayMerge[ARRAY_SIZE_2048];
    int arrayInsert[ARRAY_SIZE_2048];
    int arrayBubble[ARRAY_SIZE_2048];

    for (int i = 0; i < ARRAY_SIZE_2048; ++i) {
        arrayQuick[i] = array_2048[i];
        arrayMerge[i] = array_2048[i];
        arrayInsert[i] = array_2048[i];
        arrayBubble[i] = array_2048[i];
    }

    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_2048, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_2048, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_2048, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_2048, BUBBLE_SORT);

    printResults(ARRAY_SIZE_2048);
}

void runMeasure_8192() {
    int arrayQuick[ARRAY_SIZE_8192];
    int arrayMerge[ARRAY_SIZE_8192];
    int arrayInsert[ARRAY_SIZE_8192];
    int arrayBubble[ARRAY_SIZE_8192];

    for (int i = 0; i < ARRAY_SIZE_8192; ++i) {
        arrayQuick[i] = array_8192[i];
        arrayMerge[i] = array_8192[i];
        arrayInsert[i] = array_8192[i];
        arrayBubble[i] = array_8192[i];
    }

    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_8192, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_8192, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_8192, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_8192, BUBBLE_SORT);

    printResults(ARRAY_SIZE_8192);
}

void runMeasure_32768() {
    int arrayQuick[ARRAY_SIZE_32768];
    int arrayMerge[ARRAY_SIZE_32768];
    int arrayInsert[ARRAY_SIZE_32768];
    int arrayBubble[ARRAY_SIZE_32768];

    for (int i = 0; i < ARRAY_SIZE_32768; ++i) {
        arrayQuick[i] = array_32768[i];
        arrayMerge[i] = array_32768[i];
        arrayInsert[i] = array_32768[i];
        arrayBubble[i] = array_32768[i];
    }

    timeSpentQuick = measureCpuRunTime(quickSort, arrayQuick, ARRAY_SIZE_32768, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, arrayMerge, ARRAY_SIZE_32768, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, arrayInsert, ARRAY_SIZE_32768, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, arrayBubble, ARRAY_SIZE_32768, BUBBLE_SORT);

    printResults(ARRAY_SIZE_32768);
}


void callRunMeasureFunctions() {
    resetArrays();

    printf("accenting...\n");
    initArray(ASC);
    runMeasure_8();
    runMeasure_32();
    runMeasure_128();
    runMeasure_512();
    runMeasure_2048();
    runMeasure_8192();
    runMeasure_32768();
    printf("...\n");

    resetArrays();

    printf("decanting...\n");
    initArray(DEC);
    runMeasure_8();
    runMeasure_32();
    runMeasure_128();
    runMeasure_512();
    runMeasure_2048();
    runMeasure_8192();
    runMeasure_32768();

    printf("...\n");

    resetArrays();

    printf("random...\n");
    initArray(RAND);
    runMeasure_8();
    runMeasure_32();
    runMeasure_128();
    runMeasure_512();
    runMeasure_2048();
    runMeasure_8192();
    runMeasure_32768();
    printf("...\n");

}


void printResults(int arraySize) {

    printf("Array Size: %d\n", arraySize);
    printf("+------------+-----------+\n");
    printf("| Algorithm  |  run time |\n");
    printf("+------------+-----------+\n");

    printf("|   quick    | %-9.3f |\n", timeSpentQuick);
    printf("+------------+-----------+\n");
    printf("|   merge    | %-9.3f |\n", timeSpentMerge);
    printf("+------------+-----------+\n");
    printf("|   insert   | %-9.3f |\n", timeSpentInsert);
    printf("+------------+-----------+\n");
    printf("|   bubble   | %-9.3f |\n", timeSpentBubble);
    printf("+------------+-----------+\n\n");
}


/*     printf("Array Size: %d\n",arraySize);
    printf("__________________________________________________________\n");
    printf("\t      |\tASC\t |\tDEC\t |\tRAND\t |\n");
    printf("______________|__________|_______________|_______________|\n");
    printf("     quick    |\t%f |\t%f |\t%f | \n", timeSpentQuick,timeSpentQuick,timeSpentQuick);
    printf("______________|__________|_______________|_______________|\n");
    printf("     merge    |\t%f |\t%f |\t%f | \n", timeSpentMerge,timeSpentMerge,timeSpentMerge);
    printf("______________|__________|_______________|_______________|\n");
    printf("     insert   |\t%f |\t%f |\t%f | \n", timeSpentInsert,timeSpentInsert,timeSpentInsert);
    printf("______________|__________|_______________|_______________|\n");
    printf("     bubble   |\t%f |\t%f |\t%f | \n", timeSpentBubble,timeSpentBubble,timeSpentBubble);
    printf("______________|__________|_______________|_______________|\n");
    printf("\n");*/



void resetArrays() {
    memset(array_8, 0, sizeof(array_8));
    memset(array_32, 0, sizeof(array_32));
    memset(array_128, 0, sizeof(array_128));
    memset(array_512, 0, sizeof(array_512));
    memset(array_2048, 0, sizeof(array_2048));
    memset(array_8192, 0, sizeof(array_8192));
    memset(array_32768, 0, sizeof(array_32768));
}


/*double measureCpuRunTimeInsert(void (*pFunction)(int [], int),int sizeOfArr) {
    initArray();
    int start = 0;
    clock_t begin = clock();
    (*pFunction) (array_8192,sizeOfArr);
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}*/


/*
 *  timeSpentQuick = measureCpuRunTime(quickSort, array_32, ARRAY_SIZE_32, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, array_32, ARRAY_SIZE_32, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, array_32, ARRAY_SIZE_32, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, array_32, ARRAY_SIZE_32, BUBBLE_SORT);

    printResults(timeSpentQuick, timeSpentMerge, timeSpentInsert, timeSpentBubble, ARRAY_SIZE_32);

    timeSpentQuick = measureCpuRunTime(quickSort, array_128, ARR_SIZE_128, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, array_128, ARR_SIZE_128, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, array_128, ARR_SIZE_128, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, array_128, ARR_SIZE_128, BUBBLE_SORT);

    printResults(timeSpentQuick, timeSpentMerge, timeSpentInsert, timeSpentBubble, ARR_SIZE_128);

    timeSpentQuick = measureCpuRunTime(quickSort, array_512, ARRAY_SIZE_512, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, array_512, ARRAY_SIZE_512, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, array_512, ARRAY_SIZE_512, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, array_512, ARRAY_SIZE_512, BUBBLE_SORT);

    printResults(timeSpentQuick, timeSpentMerge, timeSpentInsert, timeSpentBubble, ARRAY_SIZE_512);

    timeSpentQuick = measureCpuRunTime(quickSort, array_2048, ARRAY_SIZE_2048, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, array_2048, ARRAY_SIZE_2048, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, array_2048, ARRAY_SIZE_2048, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, array_2048, ARRAY_SIZE_2048, BUBBLE_SORT);

    printResults(timeSpentQuick, timeSpentMerge, timeSpentInsert, timeSpentBubble, ARRAY_SIZE_2048);

    timeSpentQuick = measureCpuRunTime(quickSort, array_8192, ARRAY_SIZE_8192, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, array_8192, ARRAY_SIZE_8192, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, array_8192, ARRAY_SIZE_8192, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, array_8192, ARRAY_SIZE_8192, BUBBLE_SORT);

    printResults(timeSpentQuick, timeSpentMerge, timeSpentInsert, timeSpentBubble, ARRAY_SIZE_8192);

    timeSpentQuick = measureCpuRunTime(quickSort, array_32768, ARRAY_SIZE_32768, QUICK_SORT);

    timeSpentMerge = measureCpuRunTime(mergeSort, array_32768, ARRAY_SIZE_32768, MERGE_SORT);

    timeSpentInsert = measureCpuRunTime((void *) insertSort, array_32768, ARRAY_SIZE_32768, INSERTION_SORT);

    timeSpentBubble = measureCpuRunTime((void *) bubbleSort, array_32768, ARRAY_SIZE_32768, BUBBLE_SORT);

    printResults(timeSpentQuick, timeSpentMerge, timeSpentInsert, timeSpentBubble, ARRAY_SIZE_32768);

*/