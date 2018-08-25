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
    for(int j = 1; j < n; j++){
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] > key){
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }

    printArr(a, n);
}

void printArr(int * b, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
}
