#include "func.h"
#include <stdio.h>

typedef struct cell_ {
    double min;
    double max;
} Cell;

void bubbleSortComparison(const int arr[], int sizeOfElem);

Cell getMinAndMax(const double arr[], int sizeOfArray);

double calculateAvg(const double arr[], int sizeOfArray);

void printBubbleResult(int sizeOfArray, Cell values, double avg, const double arr[]);


#define ARRAY_SIZE_2000 2000
#define NUMBER_OF_LOOP 20

void comparison() {
    double timeSpentBubble;
    double avgBubble;
    double holdResults[NUMBER_OF_LOOP];
    int arrayBubble[ARRAY_SIZE_2000] = {0};

    createRandomNumber(ARRAY_SIZE_2000, arrayBubble, RAND);

    for (int i = 0; i < NUMBER_OF_LOOP; ++i) {
        timeSpentBubble = measureCpuRunTime((void *) bubbleSortComparison, arrayBubble, ARRAY_SIZE_2000, BUBBLE_SORT);
        holdResults[i] = timeSpentBubble;
    }

    Cell values = getMinAndMax((const double *) holdResults, NUMBER_OF_LOOP);
    avgBubble = calculateAvg((const double *) holdResults, NUMBER_OF_LOOP);

    printBubbleResult(NUMBER_OF_LOOP, values, avgBubble, (const double *) holdResults);
}

void printBubbleResult(int sizeOfArray, Cell values, double avg, const double arr[]) {
    printf("comparison Bubble Sort\n");
    printf("+-----------+-----------+\n");
    printf("| run order |  run time |\n");
    printf("+-----------+-----------+\n");

    for (int i = 0; i < sizeOfArray; ++i) {
        printf("| run %-5d | %-9.4f |\n", i + 1, arr[i]);
        printf("+-----------+-----------+\n");
    }
    printf("run time Min:%f\n",values.min);
    printf("run time Max:%f\n",values.max);
    printf("run time Average:%f\n",avg);
}

Cell getMinAndMax(const double arr[], int sizeOfArray) {
    Cell values;
    values.min = arr[0];
    values.max = arr[0];
    for (int i = 1; i < sizeOfArray; i++) {
        if (values.min > arr[i])
            values.min = arr[i];
        if (values.max < arr[i])
            values.max = arr[i];
    }
    return values;
}

double calculateAvg(const double arr[], int sizeOfArray) {
    double avg = 0;
    for (int i = 0; i < sizeOfArray; ++i) {
        avg += arr[i];
    }
    return (avg / (float) sizeOfArray);
}

void bubbleSortComparison(const int arr[], int sizeOfElem) {
    int tempArr[sizeOfElem];
    for (int i = 0; i < sizeOfElem; ++i) {
        tempArr[i] = arr[i];
    }
    for (int i = 1; i < sizeOfElem; ++i) {
        for (int j = 0; j < sizeOfElem - 1; ++j) {
            if (tempArr[j] > tempArr[j + 1])
                swap(&tempArr[j], &tempArr[j + 1]);
        }
    }
}