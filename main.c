#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "func.h"


static void readUserInput(char *userInput);

static void welcomeMenu(void);

#define USER_INPUT_SIZE 25


int main() {
    srand((unsigned int) time(NULL));

    char *userInput = malloc(sizeof(char) * USER_INPUT_SIZE);
    if (userInput == NULL) {
        perror("malloc:");
        exit(EXIT_FAILURE);
    }
    welcomeMenu();
    readUserInput(&userInput[0]);

    switch (*userInput) {
        case 'a':
            callSortFunctions();
            break;

        case 'b':
            callRunMeasureFunctions();
            break;
        case 'c':
            comparisonBubble();
            break;
        case 'd':
            comparisonArrayList();
            break;
        default:
            printf("invalid input.\n");
            break;
    }
    free(userInput);
}

static void welcomeMenu(void) {
    printf("welcome in our programm.\n");
    printf("choose a for 1.1 BASISIMPLEMENTIERUNG.\n");
    printf("choose b for 1.2 LEISTUNGSVERGLEICH.\n");
    printf("choose c for 1.3 VERGLEICHBARKEIT.\n");
    printf("choose d for 1.4 VERKETTE LISTEN.\n");
}

static void readUserInput(char *userInput) {
    if ((userInput = fgets(userInput, USER_INPUT_SIZE, stdin)) != NULL) {
        /* Clear input stream if not empty */
        if (strchr(userInput, '\n') == NULL) {
            int remainingInput;
            while ((remainingInput = getchar()) != '\n' && remainingInput != EOF) {
            }
        } else
            userInput[strcspn(userInput, "\n")] = 0;
    }
    if (userInput == NULL) {
        fprintf(stderr, "Error, while reading the user input");
        exit(EXIT_FAILURE);
    }
}

void createRandomNumber(int sizeOfArray, int arr[], DATA_SET dataSet) {
    if (dataSet == DEC) {
        for (int i = sizeOfArray; i > 0; --i) {
            arr[i] = i;
        }
    }
    for (int i = 0; i < sizeOfArray; ++i) {
        if (dataSet == RAND) {
            int randomNumber;
            randomNumber = (rand() % 65534 + (-32767));
            arr[i] = randomNumber;
        } else if (dataSet == ASC)
            arr[i] = i;
    }
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}