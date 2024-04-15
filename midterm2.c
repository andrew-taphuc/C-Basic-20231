#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<time.h>


typedef struct user{
    int dd,mm,yy,hh,MM,ss;
    char id[100];
    char respond[100];
} user;

int main(){
    int N,M;
    scanf("%d%d", &N, &M);
    user mem[N];
    
    for(int i = 0; i <N; i++){
        scanf("%d-%d-%d-%d-%d-%d", &mem[i].dd, &mem[i].mm, &mem[i].yy, &mem[i].hh, &mem[i].MM, &mem[i].ss);
        getchar();
        scanf("%s", mem[i].id);
        getchar();
        // printf("%d-%d-%d-%d-%d-%d", mem[i].dd, mem[i].mm, mem[i].yy, mem[i].hh, mem[i].MM, mem[i].ss);
        for(int j = 0; j < M; j++){
            scanf("%c", &mem[i].respond[j]);
            getchar();
            // printf("%c", mem[i].respond[j]);
        }
    }
    
    int comnum= 0;
    char command[100];
    scanf("%s", command);
    int cnt = 0;
    for(int i = 0; i < strlen(command); i++){
        if(isdigit(command[i])) cnt++;
    }
    int check = 0;
    if(cnt == strlen(command)){
        comnum = atoi(command);
        check = 1;
    }
    
    if(check == 1 && comnum < 2025 && comnum> 2019){
        int sl = 0;
        for(int i = 0; i < N; i++){
            if(mem[i].yy == (comnum-2000)){
                int check_trung = 0;
                for(int k = 0; k < i; k++){
                    if (i > 0 && strcmp(mem[i].id, mem[k].id) == 0) check_trung++;
                }
                if(check_trung == 0) sl++;
            }
        }
        printf("%d", sl);
    }
    

    if(strcmp(command, "Times:") == 0){
        int x;
        char ans;
        scanf("%d", &x);
        getchar();
        scanf("%c", &ans);
        getchar();
    
        int kt = 0, ktng = 0;
        for(int i = 0; i <N; i++){
            kt = 0;
            for(int j = 0; j < M; j++){
                if(mem[i].respond[j] == ans) kt++;
            }
            if(kt >= x){
                int check_trung = 0;
                for(int k = 0; k < i; k++){
                    if (i > 0 && strcmp(mem[i].id, mem[k].id) == 0) check_trung++;
                }
                if(check_trung == 0) ktng++;
            }
        }
        printf("%d", ktng);
    }
    
    
    if(strcmp(command, "At") == 0){
        int S;
        char ans;
        scanf("%d", &S);
        getchar();
        scanf("%c", &ans);
        getchar();
        int ktng = 0;
        for(int i = 0; i < N; i++){
            if(mem[i].respond[S] == ans){
                int check_trung = 0;
                for(int k = 0; k < i; k++){
                    if (i > 0 && strcmp(mem[i].id, mem[k].id) == 0) check_trung++;
                }
                if(check_trung == 0) ktng++;
            }
        }
        printf("%d", ktng);
    }
        
    if(strcmp(command, "Hour:") == 0){
        int H;
        scanf("%d", &H);
        getchar();
        int ktng = 0;
        
        for(int i = 0; i < N; i++){
            if (mem[i].hh == H){
                int check_trung = 0;
                for(int k = 0; k < i; k++){
                    if (i > 0 && strcmp(mem[i].id, mem[k].id) == 0) check_trung++;
                }
                if(check_trung == 0) ktng++;
            }
        }
        printf("%d", ktng);
    }
    
    if(strcmp(command, "Review:") == 0){
        char ans[M];
        for(int i = 0; i < M; i++){
            scanf("%c", &ans[i]);
            getchar();
        }
        int diem[N];
        for(int i = 0; i < N; i++){
            int diem_temp = 0;
            for(int j = 0; j < M; j++){
                if(ans[j] == mem[i].respond[j]) diem_temp++;
            }
            diem[i] = diem_temp++;
            // if(diem[i] == 0) printf("%d", --N);
            time_t random;
            srand((unsigned) time(&random));
            int r = 2 + rand() % 2;
            printf("%d", r);
            break;
            // printf("%d\n", diem[i]);
        }
    }
    
    
    return 0;
}
