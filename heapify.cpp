#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void rysuj(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void kopiec(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
   
    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        kopiec(arr, n, largest);
    }
}

void budujkopiec(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        kopiec(arr, n, i);
    }
}

void sortuj(int arr[], int n){

    budujkopiec(arr, n);

    for (int i = n - 1; i > 0; i--) {
        
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        budujkopiec(arr, i);
}
}

 
int main()
{
    
    int sz = 100000;
    int arr[sz];


    // for(int i=0;i<sz;i++){
    // arr[i]=rand()%100;
    // };

    // for(int i=sz-1;i>=0;i--){
    //   arr[i]=sz-i;
    // };

    for(int i=0;i<sz;i++){
      arr[i]=i;
    };

    int n = sizeof(arr) / 4;
    clock_t t;
    // rysuj(arr,n);
     t = clock();
    sortuj(arr, n);
    t = clock() - t;
    // rysuj(arr,n);
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Czas dzialania programu: %f", time_taken);
    return 0;

    
}