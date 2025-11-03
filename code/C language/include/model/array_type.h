#ifndef ARRAY_TYPE_H
#define ARRAY_TYPE_H

/**
 * @attention Self define int array!
 * @attention Can be null! Check field isNull before using!
 * @attention MUST be FREE after using! Call freeArr funciton!!!!
 * @attention call newIArr, newIArrs to use!
 */
typedef struct {
    int* data;
    int len;
    int capacity;
    short isNull;
    short isSorted;
} numArr;

numArr newArr(int size);

int addWithIndex(int index, int value);
int add(int value);

int removeValues(int value);
int removeValueWithIndex(int index, int value);

void printArr(numArr);

void resizeArr(numArr arr, int newSize);

/**
 * @attention Must call after using!!!
 */
void freeArr(numArr arr);

#endif