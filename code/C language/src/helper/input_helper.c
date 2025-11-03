#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/helper/input_helper.h"
#include "../../include/helper/input_validation.h"

#include "../../include/code/error_code.h"

void removeExtraBuffer() {
    int c;
    while ((c = getchar() != '\n') && c != EOF);
}


int safeInput(char** buffer, size_t maxLen, char* mess) {
    maxLen++;

    char* tempBuffer = malloc(sizeof(char) * (maxLen));

    if (tempBuffer == NULL)
        return MALLOC_ERROR;

    printf("Enter: ");
    fgets(tempBuffer, maxLen, stdin);

    if (strlen(tempBuffer) + 1 == maxLen) {
        removeExtraBuffer();
        free(tempBuffer);
        return EXTRA_INPUT;
    }

    if (tempBuffer[strlen(tempBuffer) - 1] == '\n')
        tempBuffer[strlen(tempBuffer) - 1] = '\0';

    if (*buffer != NULL)
        free(*buffer);

    *buffer = tempBuffer;

    return SUCCESS;
}

int safeIntInput(size_t maxSize) {
    int num;
    char* buffer = NULL;

    int code = safeInput(&buffer, maxSize, PRINT_MESS);
    if (code != SUCCESS)
        return INT_FORMAT_ERROR;

    if (canBeFormatToInt(buffer) == false)
        return INT_FORMAT_ERROR;

    num = atoi(buffer);
    free(buffer);

    return num;
}

double safeDoubleInput(size_t maxSize) {
    double num;
    char* buffer = NULL;

    int code = safeInput(&buffer, maxSize, PRINT_MESS);
    if (code != SUCCESS)
        return DOUBLE_FORMAT_ERROR;

    if (canBeFormatToDouble(buffer) == false)
        return DOUBLE_FORMAT_ERROR;

    free(buffer);
    num = atof(buffer);

    return num;
}


char* completeInput(size_t maxSize) {
    char* buffer = malloc(sizeof(char) * maxSize);
    int returnCode;

    do {
        returnCode = safeInput(&buffer, maxSize, PRINT_MESS);
        if (returnCode != SUCCESS)
            printf("\nWRONG INPUT! MAYBE LENGHT SIZE TOO LONG!!\n");
        else
            break;
    } while (true);

    return buffer;
}

int completeIntInput(size_t maxSize) {
    int num;
    int returnCode;

    do {
        num = safeIntInput(maxSize);
        if (num == INT_FORMAT_ERROR)
            printf("\nINVALID NUMBER INPUT!\n");
        else
            break;
    } while (true);

    return num;
}

double completeDoubleInput(size_t maxSize) {
    double num;
    double returnCode;

    do {
        num = safeIntInput(maxSize);
        if (num == DOUBLE_FORMAT_ERROR)
            printf("\nINVALID NUMBER!!\n");
        else
            break;
    } while (true);

    return num;
}