#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct device{
    char type[1000];
    char device[1000];
    int price;
}device;

typedef struct user{
    int id_gd;
    int day, month, year, hour, min;
    char id_khach[1000];
    char name[1000];
    char id_sp[1000];
    char type[1000];
    int spend;
    int stt;
}user;

int main(){
    int n,m;
    scanf("%d%d", &m, &n);
    device dev[n];
    for(int i = 0; i < m; i++){
        scanf("%s", dev[n].type);
        scanf("%s", dev[n].device);
        scanf("%d", &dev[n].price);
        // printf("1\n");
    }

    user nd[m];
    for(int i = 0; i < n; i++){
        scanf("%d", &nd[i].id_gd);
        scanf("%d-%d-%d-%d-%d", &nd[i].day, &nd[i].month, &nd[i].year, &nd[i].hour, &nd[i].min);
        scanf("%s", nd[i].id_khach);
        scanf("%s", nd[i].name);
        scanf("%s", nd[i].id_sp);
        scanf("%s", nd[i].type);
        scanf("%d%d", &nd[i].spend, &nd[i].stt);
        // printf("2\n");

    }
    int menu = 0;
    scanf("%d", &menu);
    
    if(menu == 0){
        int max = nd[0].spend;
        int id = 0;
        for(int i = 1; i < n; i++){
            if(nd[i].spend > max){
                max = nd[i].spend;
                id = i;
            }
        }
        printf("%s", nd[id].name);
    }
    // printf("0");
    
    if(menu == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(strcmp(dev[j].type, nd[i].type) != 0){
                    printf("1\n");
                    printf("%s\n", dev[j].type);
                    printf("%s\n", nd[i].type);
                }
                
                break;
            }
        }
    }
}





