#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#include "../include/input_helper.h"
#include "../include/error_code.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int num = completeIntInput(10);
    printf("Giá trị của num! Num = %d", num);

    return 0;
}