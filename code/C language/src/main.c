#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#include "../include/input_helper.h"
#include "../include/error_code.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char* name;
    int code = safeInput(&name, 10, PRINT_MESS);

    if (code == SUCCESS)
        printf("\nNhập thành công!");
    else if (code == EXTRA_INPUT)
        printf("\nNhập thừa giá trị!");
    else if (code == MALLOC_ERROR)
        printf("\nLỗi ngay lúc malloc!");

    return 0;
}