#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int partition(int arr[], int p, int r){

    int pivot = arr[r];
    int smaller = p;
    for(int i = p; i <r; i++){
        if (arr[i] <= pivot){
            int temp = arr[smaller];
            arr[smaller] = arr[i];
            arr[i] = temp;
            smaller = smaller +1;
        }
    }
    int temp2 = arr[smaller];
    arr[smaller] = arr[r];
    arr[r] = temp2;

    return smaller;
}

void quicksort(int arr[], int p, int r){
    int q;
    if(p<r)
    {
        q = partition(arr, p,r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
    
}

void rysuj(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    // int arr[] = {9,3,4,0,6,2,0,8,6,2,2,1,9,2,7};
    int sz = 100000;
    int arr[sz];

    // for(int i=0;i<sz;i++){
    //   arr[i]=rand()%100;
    // };

    // for(int i=sz-1;i>=0;i--){
    //   arr[i]=sz-i;
    // };

    for(int i=0;i<sz;i++){
      arr[i]=i;
    };

    int n = sizeof(arr) / 4;
    clock_t t;
    rysuj(arr, n);
    t = clock();
    quicksort(arr,0,n-1);
    t = clock() - t;
    rysuj(arr, n);
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Czas dzialania programu: %f", time_taken);
    return 0;
}

