#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/model/string_type.h"
#include "../../include/model/array_type.h"

#include "../../include/code/error_code.h"

string newStr() {
    string s;
    s.value = malloc(sizeof(char) * BASE_STRING_LEN);
    s.len = 0;
    s.maxSize = BASE_STRING_LEN;

    return s;
}

string newStrWithSize(int size) {
    string s = newStr();
    reSizeString(&s, size);
}

string newString(const char* content) {
    string s = newStr();
    strcpy(s.value, content);
    s.len = strlen(content);

    return s;
}

void reSizeString(string* s, int size) {
    char* newValue = malloc(sizeof(char) * size);
    strcpy(newValue, s->value);
    free(s->value);
    s->value = newValue;
}


short isBlank(char c) {
    if (c == ' ')
        return true;
    return false;
}

short isEndl(char c) {
    if (c == '\n')
        return true;
    return false;
}

short isNumeric(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

short isAlpha(char c) {
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}


short isEmptyString(string s) {
    if (s.len == 0)
        return true;
    return false;
}

short isNumberString(string s) {
    if (s.len == 0)
        return false;

    for (int i = 0; i < s.len; i++)
        if (!isNumeric(s.value[i]))
            return false;

    return true;
}

short isAlphaString(string s) {
    if (s.len == 0)
        return false;

    for (int i = 0; i < s.len; i++) {
        char c = s.value[i];
        if (!isAlpha(c) && !isBlank(c) && !isEndl(c))
            return false;
    }

    return true;
}

short hasContent(string s) {
    if (isEmptyString(s))
        return false;

    for (int i = 0; i < s.len; i++)
        if (s.value[i] < 32 || s.value[i] > 126)
            return false;

    return true;
}


string trimUp(string s) {
    if (s.len == 0)
        return s;

    char* newValue = malloc(sizeof(char) * s.len);

    short ignore = (s.value[0] == ' ') ? 1 : 0;
    for (int i = 0; i < s.len; i++) {

    }

}

string toUppercase(string s) {
    for (int i = 0; i < s.len; i++)
        if (s.value[i] >= 'a' && s.value[i] <= 'z')
            s.value[i] -= 32;
}

string toLowercase(string s) {
    for (int i = 0; i < s.len; i++)
        if (s.value[i] >= 'A' && s.value[i] <= 'Z')
            s.value[i] += 32;
}


void freeStr(string s) {
    if (s.value != NULL)
        free(s.value);
}

void freeStrArr(stringArr arr) {
    if (arr.data)
        return;

    for (int i = 0; i < arr.arrSize; i++)
        freeStr(arr.data[i]);
}