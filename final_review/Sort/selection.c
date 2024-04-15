#include<stdio.h>

void select_sort(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(A[min] > A[j]) min = j;
        }
        if(min != i){
            int tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
        }
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    select_sort(A,n);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}