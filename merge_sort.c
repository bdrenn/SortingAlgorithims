#include<stdio.h>

void msort(int *a, int n);
void printArray(int arr[], int size);
void merge(int *a, int left, int middle, int right);

int main () 
{
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof(a) / sizeof(a[0]);

    printf("original: ");
    printArray(a,n);
    msort(a, n); 
    printf("sorted: ");
    printArray(a,n);
}

void merge(int *a, int left, int middle, int right)
{
    int i = 0;
    int j = 0;
    int k = left;

    int left_size = middle-left+1;
    int right_size = right - middle - 1;

    int L[left_size], R[right_size];

    for (int j=0; j <= right_size-1; j++){
        R[j] = a[j+middle+1];
    }

    for (int i=0; i <= middle; i++){
        L[i] = a[i];
    }

    while (i < left_size && j < right_size){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < right_size) {
        a[k] = R[j];
        j++;
        k++;
    }
}


void msort(int *a, int n) 
{
    int *left = a;
    int *right = a + n - 1;

    if (left < right){
        int middle_index = (right - a) / 2;
        int end = (right - a) - middle_index;
        int *middle = middle_index + a; 

        msort(left, middle_index+1);
        msort(middle+1, end); 
        merge(a, 0, middle_index, n);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

