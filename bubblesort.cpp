
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void sortowanie_babelkowe(int tab[],int n)
{
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){ //pętla wewnętrzna{
		if(tab[j-1]>tab[j]){
			int temp = tab[j-1];
        	tab[j-1] = tab[j];
        	tab[j] = temp;
}}}}

int main()
{
	
	int sz = 100000;
    int arr[sz];

    //  for(int i=0;i<sz;i++){
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

    t = clock();
    sortowanie_babelkowe(arr,n);
    t = clock() - t;
    
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Czas dzialania programu: %f", time_taken);
    return 0;

}