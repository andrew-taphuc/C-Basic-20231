// #include<stdio.h>

// int main(){
//     int n = 0;
//     scanf("%d", &n);
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }
//     for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             int tmp = 0;
//             if(arr[i] > arr[j]){
//                 tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }

//     }
//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
// }

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() 
{ 
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d%d", &a, &b);
        int arr1[a];
        int arr2[b];
        
        for(int j = 0; j < a; j++){
            scanf("%d", &arr1[j]);
        }
        for(int j = 0; j < b; j++){
            scanf("%d", &arr2[j]);
        }
        if(a != b) printf("0\n");
        if(a == b){
            int cnt = 0;
            for(int j = 0; j < a; j++){
                if(arr1[j] != arr2[j]) cnt++;
            }
            if (cnt == 0) printf("1\n");
            else printf("0\n");
        }
    }
}