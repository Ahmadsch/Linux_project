#include "func.h"
#include <stdlib.h>
#include <stdio.h>


void printList(List *node);

void printRunTimeArrListSort(double timeSpentArrInsert, double timeSpentListInsert);

void printRunTimeArrListInit(double timeSpentArrInit, double timeSpentListInit);

void printBeforeSort(int arr[], List *head);

void printAfterSort(int arr[], List *head);

void insertSortLinkedList(List **headRef);

void sortedInsert(List **headRef, List *newNode);

void freeList(List *head);


#define SIZE_OF_LIST 50000


void copyArrayToList(const int arr[], int sizeOfArr, List **head) {
    List *temp = malloc(sizeof(List));
    temp->value = arr[0];
    temp->next = NULL;
    (*head) = temp;
    for (int i = 1; i < sizeOfArr; i++) {
        List *temp2 = malloc(sizeof(List));
        temp->next = temp2;
        temp2->value = arr[i];
        temp2->next = NULL;
        temp = temp2;
    }
}

void comparisonArrayList() {
    double timeSpentArrInsert;
    double timeSpentListInsert;
    double timeSpentArrInit;
    double timeSpentListInit;

    int arrayInsert[SIZE_OF_LIST];
    List *head = NULL;

    timeSpentArrInit = measureCpuRunTimeInitArr(createRandomNumber, arrayInsert, SIZE_OF_LIST, RAND);
    timeSpentListInit = measureCpuRunTimeInitList(copyArrayToList, arrayInsert, SIZE_OF_LIST, &head);
    printBeforeSort(arrayInsert, head);

    timeSpentArrInsert = measureCpuRunTime((void *) insertSort, arrayInsert, SIZE_OF_LIST, INSERTION_SORT);
    timeSpentListInsert = measureCpuRunTimeLinkedList(insertSortLinkedList, &head);

    printAfterSort(arrayInsert, head);

    printRunTimeArrListInit(timeSpentArrInit, timeSpentListInit);
    printRunTimeArrListSort(timeSpentArrInsert, timeSpentListInsert);

    freeList(head);
}

void printRunTimeArrListSort(double timeSpentArrInsert, double timeSpentListInsert) {
    printf("comparisonBubble Array and Linked list Insertion sort run time\n");
    printf("+-------------+-----------+\n");
    printf("| Array       |  run time |\n");
    printf("+-------------+-----------+\n");
    printf("|             | %-9.4f |\n", timeSpentArrInsert);
    printf("+-------------+-----------+\n");
    printf("| Linked list |  run time |\n");
    printf("+-------------+-----------+\n");
    printf("|             | %-9.4f |\n", timeSpentListInsert);
    printf("+-------------+-----------+\n");

}

void printRunTimeArrListInit(double timeSpentArrInit, double timeSpentListInit) {
    printf("comparisonBubble Array and Linked list initializing run time\n");
    printf("+-------------+-----------+\n");
    printf("| Array       |  run time |\n");
    printf("+-------------+-----------+\n");
    printf("|             | %-9.4f |\n", timeSpentArrInit);
    printf("+-------------+-----------+\n");
    printf("| Linked list |  run time |\n");
    printf("+-------------+-----------+\n");
    printf("|             | %-9.4f |\n", timeSpentListInit);
    printf("+-------------+-----------+\n\n");

}

void printBeforeSort(int arr[], List *head) {
    printf("before sorting: Array size: %d\n\n", SIZE_OF_LIST);
    printArray(arr, SIZE_OF_LIST);
    printf("\n\n");
    printf("before sorting: List size: %d\n", SIZE_OF_LIST);
    printList(head);
    printf("\n\n\n");
}

void printAfterSort(int arr[], List *head) {
    printf("After sorting: Array size: %d\n\n", SIZE_OF_LIST);
    printArray(arr, SIZE_OF_LIST);
    printf("\n\n");
    printf("After sorting: List size: %d\n", SIZE_OF_LIST);
    printList(head);
    printf("\n\n");
}

void printList(List *node) {
    int i = 0;
    while (node != NULL) {
        if ((i % 15) == 0)
            printf("\n");
        printf("%d\t", node->value);
        node = node->next;
        i++;
    }
    printf("\n");
}

void insertSortLinkedList(List **headRef) {
    List *sorted = NULL;
    List *current = *headRef;

    while (current != NULL) {
        // Store next for next iteration
        List *next = current->next;

        // insert current in sorted linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }
    *headRef = sorted;
}


void sortedInsert(List **headRef, List *newNode) {
    List *current;
    /* Special case for the head end */
    if (*headRef == NULL || (*headRef)->value >= newNode->value) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        /* Locate the node before the point of insertion */
        current = *headRef;
        while (current->next != NULL && current->next->value < newNode->value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void freeList(List *head) {
    List *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}