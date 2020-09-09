#include<stdio.h>

void qsort2(int *a, int n);
void printArray(int arr[], int size);
void swap(int *a, int *b);
int *partition(int *low, int *high);

int main () 
{
    int a[] = {100, 20, 4, 9, 0, 3, 10, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original: ");
    printArray(a,n);
    qsort2(a, n); 
    printf("Sorted: ");
    printArray(a,n);
}

int *partition(int *low, int *high){

    int *i = low;
    int *j = high;
    int pivot = *i;

    while (i < j){
        while (*i <= pivot && i < high){
            i++;
        }
        while(*j > pivot && j > low) {
            j--;
        }
        if (i < j){
            swap(i, j);
        }
    }
    swap(low, j);
    return j;
}

void qsort2(int *a, int n) 
{
    int *low = a;
    int *high = a + n - 1;
    int size = high - a;

    if (low < high){
        int *j = partition(low, high);
        qsort2(a, j-a);
        qsort2(j+1, high-j); 
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

