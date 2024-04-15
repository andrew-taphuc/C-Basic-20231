#include<stdio.h>

int a[100];

void try(int k, int n){
    for(int i = 0; i <= 1; i++){
        if(a[k-1] + i < 2){
                a[k] = i;
            if(k == n){
                for(int j = 1; j <= n; j++){
                    printf("%d", a[j]);
                }
                printf("\n");
            }
            else{
                try(k + 1, n);
            }
        }
    }
}
int main(){
    int n = 0;
    scanf("%d", &n);
    a[0] = 0;
    try(1, n);
    return 0;
}