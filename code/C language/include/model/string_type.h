#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include "array_type.h"

/**
 * @attention: String base max len = 256 character
 * @attention: When using string s = newString() to use!
 * @attention: must be freed after using!!!!
 */
typedef struct {
    char* value;
    int len;
    int maxSize;
} string;

typedef struct {
    string* data;
    int arrSize;
} stringArr;

#define BASE_STRING_LEN 256

string newStr();
string newString(const char* content);
string newStrWithSize(int size);

void reSizeString(string* s, int size);

stringArr newStrArr();
stringArr stringSplit(string s, char delimiter);

short isBlank(char c);
short isEndl(char c);
short isNumeric(char c);
short isAlpha(char c);

short isEmptyString(string c);
short isNumberString(string s);
short isAlphaString(string s);

short hasContent(string s);
short hasAppend(string s, ...);
short hasAppends(string s, ...);


string toUppercase(string s);
string toLowercase(string s);
string trimUp(string s);

string join(string s, ...);

/**
 * @attention Call after using!
 */
void freeStrArr(stringArr arr);

/**
 * @attention Call after finish using!
 */
void freeStr(string s);

#endif