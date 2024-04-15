#include<stdio.h>
int i = 0;

void thap(int n, char a, char b, char c){
    if(n == 1) printf("Chuyen %d dia tu %c sang %c\n", n, a, b);
    else{
        thap(n - 1, a, c, b);
        thap(1, a, b, c);
        thap(n - 1, c, b, a);
    }
}

int main(){
    char a = 'A';
    char b = 'B';
    char c = 'C';
    thap(3,a,b,c);
}