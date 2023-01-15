#include <stdio.h>
#include <stdlib.h>


int binarySearchRecursion(int *vector, int size, int value) {
    int start = 0;
    int end = size - 1;
    int mid;
    if (start > end) {
        return -1;
    } else if (binarySearchRecursion(vector, size, value))
    return -1;
}

int main(){
    int vector[] = {3, 8, 15, 20, 13, 18, 21, 28, 29, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95};
    int size = sizeof(vector) / sizeof(vector[0]);
    int value = 40;
    int index = binarySearchRecursion(vector, size, value);
    if (index == -1) {
        printf("valor %d não encontrado\n", value);
    } else {
        printf("valor %d encontrado na posição %d\n", value, index);
    }
    return 0;
}
