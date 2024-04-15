#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long M[1000][1000];
// int tohop(int k, int n){
//     if(k == 0 || k == n) return 1;
//     return tohop(k, n - 1) + tohop(k - 1, n - 1);
// }

// int main(){
//     int n,k;
//     scanf("%d%d", &k, &n);
//     printf("%d", tohop(k,n));
// }

long long tohop(long long k, long long n){
    if(k == 0 || k == n) M[k][n] = 1;
    else if(M[k][n] == 0) M[k][n] = tohop(k, n - 1) + tohop(k - 1, n - 1);
    return M[k][n];
}

int main(){
    long long n,k;
    memset(M, 0, sizeof(M));
    scanf("%lld%lld", &k, &n);
    printf("%lld", tohop(k,n) % 1000000007);
    return 0;
}

