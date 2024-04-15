#include<stdio.h>

int a[100];
int n = 5;
int k = 3;

void try(int i){
    for(int j = a[i-1] + 1; j < n - k + i + 1; j++){
        a[i] = j;
        if(i == k){
            for(int p = 1; p <= k; p++){
                printf("%d", a[p]);
            }
            printf("\n");
        }
        else try(i + 1);
    }
}

int main(){
    a[0] = 0;
    try(1);
    return 0;
}