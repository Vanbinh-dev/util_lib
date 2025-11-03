#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/helper/input_validation.h"
#include "../../include/code/error_code.h"

#include "../../include/model/string_type.h"

short canBeFormatToInt(char* num) {
    for (int i = 0; i < strlen(num); i++)
        if (!isNumeric(num[i]))
            return false;
    return true;
}

short canBeFormatToDouble(char* num) {
    short hasDot = false;

    for (int i = 0; i < strlen(num); i++) {
        if (num[i] == '.' && !hasDot) {
            hasDot = true;
            continue;
        }

        else if (!isNumeric(num[i]))
            return false;
    }

    return true;
}