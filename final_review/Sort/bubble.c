#include<stdio.h>


int abc;

void bubble(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i] > A[j]){
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
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
    bubble(A,n);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}