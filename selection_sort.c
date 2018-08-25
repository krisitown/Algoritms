#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = -1;
    scanf("%d", &n);
    int a[n];

    //read array
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    //sort array
    for(int i = 0; i < n; i++){
        int minId = findSmallestIdInSubArr(a, i, n - i);
        int temp = a[i];
        a[i] = a[minId];
        a[minId] = temp;
    }

    printArr(a, n);
}

int findSmallestIdInSubArr(int *a, int start, int count){
    int min = 2000000;
    int minIndex = -1;
    for(int i = start; i < start + count; i++){
        if(a[i] < min){
            minIndex = i;
            min = a[i];
        }
    }
    return minIndex;
}

void printArr(int * b, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
}
