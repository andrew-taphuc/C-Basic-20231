#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define max 1000
 
int head=100000;
int tail=-1;
int kq[200000];
 
void push(int x,int k){
    if(tail==-1)tail=head,kq[head]=x;
    else
    {
        if(!k)tail++,kq[tail]=x;
        else head--,kq[head]=x;
    }
    return;
}
 
int kiemtra(int x){
for(int i=head;i<=tail;i++)
    if(kq[i]==x)return 1;
return 0;
}
 
void pop(int z){
    if(!z)
        for(int i=head; i<=tail; i++)
            printf("%d ",kq[i]);
    else
    {
        for(int i=head; i<=tail; i++)
            if(kq[i]%2==0)
                printf("%d ",kq[i]);
        for(int i=head; i<=tail; i++)
            if(kq[i]%2==1)
                printf("%d ",kq[i]);
    }
    return;
}
 
void slove(){
	char ch[100];
    int x;
    while(1){
        scanf("%s", ch);
        if(strcmp(ch,"Print")==0)
        {
            scanf("%d",&x);
            if(x==0)pop(0);
            else pop(1);
            break;
        }
        scanf("%d",&x);
        if(x<0||kiemtra(x))continue;
        if(strcmp(ch,"InsertTail")==0)
            push(x,0);
            else push(x,1);
    }
}
int main(){
    slove();
    return 0;
}