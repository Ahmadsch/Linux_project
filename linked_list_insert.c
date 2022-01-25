#include "func.h"
#include <stdlib.h>
#include <stdio.h>


static void printList(List *node);

static void printRunTimeArrListSort(double timeSpentArrInsert, double timeSpentListInsert);

static void printRunTimeArrListInit(double timeSpentArrInit, double timeSpentListInit);

static void printBeforeSort(int arr[], List *head);

static void printAfterSort(int arr[], List *head);

static void copyArrayToList(const int arr[], int sizeOfArr, List **head);

static void insertSortLinkedList(List **headRef);

static void sortedInsert(List **headRef, List *newNode);

static void freeList(List *head);


#define SIZE_OF_LIST 5


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

static void copyArrayToList(const int arr[], int sizeOfArr, List **head) {
    List *temp = malloc(sizeof(List));
    temp->value = arr[0];
    temp->next = NULL;
    //assigning the temp to start of the list
    //everytime temp get assigned the head will hold all node which temp pointed to.
    (*head) = temp;
    for (int i = 1; i < sizeOfArr; i++) {
        List *newNode = malloc(sizeof(List));
        //assigning temp-> next to a new node
        temp->next = newNode;
        //initializing the values of the new node which temp is pointing to.
        newNode->value = arr[i];
        newNode->next = NULL;
        //now the new node becomes the temp node. in the next iteration this new node will point to another new node and so on..
        temp = newNode;
    }
}

static void printRunTimeArrListSort(double timeSpentArrInsert, double timeSpentListInsert) {
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

static void printRunTimeArrListInit(double timeSpentArrInit, double timeSpentListInit) {
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

static void printBeforeSort(int arr[], List *head) {
    printf("before sorting: Array size: %d\n\n", SIZE_OF_LIST);
    printArray(arr, SIZE_OF_LIST);
    printf("\n\n");
    printf("before sorting: List size: %d\n", SIZE_OF_LIST);
    printList(head);
    printf("\n\n\n");
}

static void printAfterSort(int arr[], List *head) {
    printf("After sorting: Array size: %d\n\n", SIZE_OF_LIST);
    printArray(arr, SIZE_OF_LIST);
    printf("\n\n");
    printf("After sorting: List size: %d\n", SIZE_OF_LIST);
    printList(head);
    printf("\n\n");
}

static void printList(List *node) {
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

static void insertSortLinkedList(List **headRef) {
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


static void sortedInsert(List **headRef, List *newNode) {
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


static void freeList(List *head) {
    List *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}