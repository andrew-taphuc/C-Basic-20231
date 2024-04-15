#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct code{
    int num;
    char txt[100];
    char txt_tach[100];
}code;

int compare(const void *a, const void *b) {
    return strcmp(((code*)a)->txt, ((code*)b)->txt);
}

int main(){
    int n = 0;
    scanf("%d", &n);
    code input[n];
    for(int i = 0; i < n; i++){
        scanf("%d%s", &input[i].num, input[i].txt);
    }

    qsort(input, n, sizeof(code), compare);

    for(int i = 0; i < n; i++){
        printf("%d %s\n", input[i].num, input[i].txt);
    }
    return 0;
}

