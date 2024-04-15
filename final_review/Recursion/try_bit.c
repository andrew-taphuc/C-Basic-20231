#include<stdio.h>

// int j = 1;
int n = 4;
int A[100];

void in(int A[], int n){
    for(int i = 1; i <= n; i++){
        printf("%d", A[i]);
    }
    printf("\n");
}



void try(int j){
    for(int i = 0; i <= 1; i++){
        A[j] = i;
        if(j == n) in(A, n);
        else try(j + 1);
    }
}

int main(){
    try(1);
    return 0;
}