#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#define PRINT_MESS "Nhập vào giá trị"

#include <stdio.h>

void removeExtraBuffer();

int safeInput(char** buffer, size_t maxSize, char* mess);
int safeIntInput(size_t maxSize);
double safeDoubleInput(size_t maxSize);

char* completeInput(size_t maxSize);
int completeIntInput(size_t maxSize);
double completeDoubleInput(size_t maxSize);


#endif