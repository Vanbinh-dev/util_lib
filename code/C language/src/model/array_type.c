#include <stdio.h>
#include <stdlib.h>

#include "../../include/model/array_type.h"
#include "../../include/code/error_code.h"

numArr newArr(int size) {
    numArr arr;
    arr.data = malloc(sizeof(int) * size);
    arr.isNull = false;

}