#ifndef LINUX_PROJECT_FUNC_H
#define LINUX_PROJECT_FUNC_H

typedef enum {
    MERGE_SORT, QUICK_SORT, BUBBLE_SORT, INSERTION_SORT
} SORT_MODE;

typedef enum {
    ASC, DEC, RAND
} DATA_SET;

typedef struct list_ {
    int value;
    struct list_ *next;
} List;


//merge sort
void mergeSort(int arr[], int start, int end);


//quick sort
void quickSort(int arr[], int low, int high);


//insertion sort
void insertSort(int arr[], int sizeOfElem);


//bubble sort
void bubbleSort(int arr[], int sizeOfElem);


//main func
void swap(int *x, int *y);

void createRandomNumber(int sizeOfArray, int arr[], DATA_SET dataSet);


//call_sort_func.c
void callSortFunctions();

void printArray(const int arr[], int arraySize);


//measure_run_time.c
void callRunMeasureFunctions();

double measureCpuRunTime(void (*pFunction)(int [], int, int), int arr[], int sizeOfArr, SORT_MODE sortMode);

double measureCpuRunTimeLinkedList(void (*pFunction)(List **), List **start);

double measureCpuRunTimeInitArr(void (*pFunction)(int, int [], DATA_SET), int arr[], int sizeOfArr, DATA_SET dataSet);

double
measureCpuRunTimeInitList(void (*pFunction)(const int[], int, List **), const int arr[], int sizeOfArr, List **head);


//comparisonBubble.c
void comparisonBubble();


//linked_list_insert.c
void comparisonArrayList();

//



#endif //LINUX_PROJECT_FUNC_H
