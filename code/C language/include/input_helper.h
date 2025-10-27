#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#define PRINT_MESS "Nhập vào giá trị"

void removeExtraBuffer();
int safeInput(char** buffer, size_t maxSize, char* mess);

#endif