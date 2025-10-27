#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/input_helper.h"
#include "../../include/error_code.h"

void removeExtraBuffer() {
    int c;
    while ((c = getchar() != '\n') && c != EOF);
}

int safeInput(char** buffer, size_t maxLen, char* mess) {
    maxLen++;

    char* tempBuffer = malloc(sizeof(char) * (maxLen));

    if (tempBuffer == NULL)
        return NULL_CATCH;

    printf("Nhập: ");
    fgets(tempBuffer, maxLen, stdin);

    printf("Chạy đến đây!\n");

    if (strlen(tempBuffer) + 1 == maxLen) {
        removeExtraBuffer();
        free(tempBuffer);
        return EXTRA_INPUT;
    }

    printf("Chạy qua điều kiện!\n");

    *buffer = tempBuffer;

    return 1;
}