#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void printArr(int arr[], int size);
int sumArr(int arr[], int size);
int hasElement(int arr[], int size, int value);
int findElement(int arr[], int size, int value);
void reverseArr(int arr[], int size);
void swap(int* a, int* b);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int arr[] = { 23, 4, 5, 64, 54, 3, 34 };
    int size = sizeof(arr) / sizeof(int);

    printArr(arr, size);
    reverseArr(arr, size);
    printArr(arr, size);

    return 0;
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int sumArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

int hasElement(int arr[], int size, int value) {
    if (findElement(arr, size, value) == -1)
        return 0;

    return 1;
}

int findElement(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i;

    return -1;
}

void reverseArr(int arr[], int size) {
    if (arr == NULL)    
        return;

    for (int i = 0; i < size / 2; i++)
        swap(&arr[i], &arr[size - 1 - i]);
}

void swap(int* a, int* b) {
    if (a == b)
        return;

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}