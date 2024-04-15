#include <stdio.h>

int m[100];
int M[100];
int a[100];
int x[100];
int n = 3;

void TRY(int k){
    for(int i = 1; i <= n; i++){
        if(!M[i]){
            a[k] = i;
            M[i] = 1;
            if(k == n){
                for(int j = 1; j <= n; j++){
                    printf("%d", a[j]);
                }
                printf("\n");
            }
            else TRY(k + 1);
            M[i] = 0;
        }
    }
}

int main(){
    for(int i = 1; i <= n; i++)
        M[i] = 0;
    TRY(1);
}

// void TRY(int i){
//     for (int v = 1; v <= n; v++){
//         if (!m[v]){
//             x[i] = v;
//             m[v] = 1; // đánh dấu 
//             if(i == n){
//                 for(int j = 1; j <= n; j++){
//                     printf("%d", x[j]);
//                 }
//                 printf("\n");
//             }
            
//             else TRY(i + 1);
//             m[v] = 0; // khôi phục
//         }
//     }
// }
// int main()
// {
//     for (int v = 1; v <= n; v++)
//         m[v] = 0;
//     TRY(1);
// }