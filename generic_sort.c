#include <stdio.h>
#include <stdbool.h>

void qsort2(int *a, int n, int(*compare)(void *x, void *y));
void printArray(int arr[], int size);
void swap(int *a, int *b);
int *partition(int *low, int *high, int(*compare)(void *x, void *y));
int compare_int(void *x, void *y);


int main () 
{
    int a[] = {100, 20, 4, 9, 0, 3, 10, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original: ");
    printArray(a,n);
    qsort2(a, n, compare_int); 
    printf("Sorted: ");
    printArray(a,n);
}

int compare_int(void *x, void *y){
    int *val1 = (int*)x;
    int *val2 = (int*)y;

    return *val1 <= *val2 ? 1 : -1;
}

int *partition(int *low, int *high, int(*compare)(void *x, void *y)) 
{ 

    int *i = low;
    int *j = high;
    int pivot = *i;

    printf("compare: %d\n", compare(i, j));
    printf("i: %d\n", *i);
    printf("j: %d\n", *j);

    while (i < j){
        while ((compare(i, &pivot)==1) && i < high){
            i++;
        }
        while((compare(j, &pivot)==-1) && j > low) {
            j--;
        }
        if (i < j){
            swap(i, j);
        }
    }
    swap(low, j);
    return j;
}

void qsort2(int *a, int n, int(*compare)(void *x, void *y)) 
{
    int *low = a;
    int *high = a + n - 1;
    int size = high - a;

    if (low < high){
        int *j = partition(low, high, compare);
        qsort2(a, j-a, compare);
        qsort2(j+1, high-j, compare); 
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

