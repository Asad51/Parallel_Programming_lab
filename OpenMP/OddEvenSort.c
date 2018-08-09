#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int thread_count = strtol(argv[1], NULL, 10);
    /*printf("\nEnter Array Elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }*/

    for(int i=0; i<n; i++){
        arr[i] = rand()%n;
    }
   
    printf("\nBefore Sorting :\n");
   
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int j;
    for(int i=0; i<n; i++)
    {   
        if(i%2 == 0)
        {
            #pragma omp parallel for num_threads(thread_count) private(j) shared(arr)
            for(j=0; j<n-1; j+=2)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
        else
        {
            #pragma omp parallel for num_threads(thread_count) private(j) shared(arr)
            for(j=1; j<n-1; j+=2)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
       
    }

    printf("\nAfter Sorting :\n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}