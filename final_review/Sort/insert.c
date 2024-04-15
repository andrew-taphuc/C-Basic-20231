#include<stdio.h>

void insert_sort(int A[], int n){
    for(int i = 1; i < n; i++){
        int last = A[i];
        int j = i;
        while(j > 0 && A[j - 1] > last){
            A[j] = A[j - 1];
            j--;
        }
        A[j] = last;
            for(int k = 0; k < n; k++){
                printf("%d ", A[k]);
            }
            printf("\n");
    }
}


int main(){
    int n = 0;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    insert_sort(A,n);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}