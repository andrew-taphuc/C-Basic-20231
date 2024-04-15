#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000

int small(int a, int b){
    if(a < b) return a;
    return b;
}
int large(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    int N=0, M=0;
    scanf("%d%d", &N, &M);

    int emo[N]; int ads[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &emo[i]);
        scanf("%d", &ads[i]);
    }

    int time_ads[M];
    for(int i = 0; i < M; i++){
        scanf("%d", &time_ads[i]);
    }

    int human[N][M+1];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M+1; j++){
            scanf("%d", &human[i][j]);
        }
    }

    int same_time[N];
    // for(int i = 0; i < N; i++){
    //     same_time[i] = dichung(time_ads, human, i, M);
    // }    

    for(int p = 0; p < N; p++){
        int chung = 0;//thoi gian di chung
        for(int i = 0; i < M; i++)//xet tung doan duong
        {   if (human[p][i + 1] == 0 && (i + 1) > human[p][0]) break;//Neu khong di doan duong i+1 thi break
            int sum_nguoi = 0, sum_xe = 0;
            for(int k = 0; k < i; k++){
                sum_xe += time_ads[k]; //thoi gian xe vao doan duong
                sum_nguoi += human[p][k+1]; //thoi gian nguoi vao doan duong
            }
            int start = large(sum_nguoi, sum_xe);
            int end = small((sum_nguoi + human[p][i+1]), (sum_xe + time_ads[i]));
            int lech = end - start; //thoi gian chenh lech
            if (lech > 0) chung += lech;    
        }
        same_time[p] = chung;
    }

    // for(int i = 0; i < N; i++){
    //     printf("%d ", same_time[i]);
    // }

    int menu = 0;
    scanf("%d", &menu);

    if(menu == -2){
        int menu_2 = 0;
        for(int i = 0; i < N; i++){
            if(emo[i] == -1 && ads[i] == -1) menu_2 += same_time[i];
        }
        printf("%d", menu_2);
    }
    if(menu == -1){
        int menu_1 = 0;
        for(int i = 0; i < N; i++){
            if(emo[i] == -1 && ads[i] == -0 || emo[i] == 0 && ads[i] == -1) menu_1 += same_time[i];
        }
        printf("%d", menu_1);
    }

    if(menu == 0){
        int menu_0 = 0;
        for(int i = 0; i < N; i++){
            if(emo[i] == -1 && ads[i] == 1 || emo[i] == 1 && ads[i] == -1 || emo[i] == 0 && ads[i] == 0) menu_0 += same_time[i];
        }
        printf("%d", menu_0);
    }

    if(menu == 1){
        int menu1 = 0;
        for(int i = 0; i < N; i++){
            if(emo[i] == 0 && ads[i] == 1 || emo[i] == 1 && ads[i] == 0 || emo[i] == 2 && ads[i] == -1) menu1 += same_time[i];
        }
        printf("%d", menu1);
    }

    if(menu == 2){
        int menu1 = 0;
        for(int i = 0; i < N; i++){
            if(emo[i] == 1 && ads[i] == 1 || emo[i] == 2 && ads[i] == 0) menu1 += same_time[i];
        }
        printf("%d", menu1);
    }

    if(menu == 3){
        int menu1 = 0;
        for(int i = 0; i < N; i++){
            if(emo[i] == 2 && ads[i] == 1) menu1 += same_time[i];
        }
        printf("%d", menu1);        
    }

    if(menu == 4){
        int menu1 = 0;
        for(int i = 0; i < N; i++){
            if((emo[i] == 1 || emo[i] == 2) && ads[i] == 1) menu1 += same_time[i];
        }
        printf("%d", menu1);
    }


    if(menu == 5){
        int menu1 = 0;
        for(int i = 0; i < N; i++){
            if(ads[i] == -1) menu1 += same_time[i];
        }
        printf("%d", menu1);
    }

    if(menu == 6){
        int menu1 = 0;
        for(int i = 0; i < N; i++){
            if(ads[i] == -1) menu1 += same_time[i];
        }
        printf("100");
    }





}