#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	int maxCap;
	int currCap;
	struct Node *next;
} Node;

int max(int tm[], int n){
    int max = 1000;
    for(int i = 0; i < n; i++){
        if(max > tm[i]) max = tm[i];
    }return max;
}

Node* makeNode(int currCap){
    Node* p = (Node*)malloc(sizeof(Node));
    p->currCap = currCap; p->next = NULL;
    return p;
}

void insertLast(Node**h, int num){
    Node* newNode = makeNode(num);

    if(*h == NULL){
        *h = newNode;
        return;
    }

    Node* last = *h;
    while(last->next != NULL){
        last = last-> next;
    }
    last->next = newNode;
}

int checkEmpty(Node*h){
    if (h == NULL){
        return 1;
    }
    return 0;
}

int checkFull(Node*h){
    int cnt = 0;
    while(h != NULL){
        cnt++;
        h = h-> next;
    }
    // printf("%d, ", cnt);
    if(cnt < 3) return 1;
    return 0;

}


int main(){
    int N = 0;
    scanf("%d", &N);
    Node* arr[N];
    for(int i = 0; i < N; i++){
        arr[i] = NULL;
    }

    int maxNode = 0;
    scanf("%d", &maxNode);
    int maxCaps[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &maxCaps[i]);
    }

    int allStuff = 0;
    scanf("%d", &allStuff);
    int stuffSize[allStuff];
    for(int i = 0; i < allStuff; i++){
        scanf("%d", &stuffSize[i]);
    }


//Them phan tu co kich thuoc thoa man vao queue
    for(int i = 0; i < allStuff; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++)
        {
            if (stuffSize[i] == maxCaps[j])
            {
            // printf("%d %d\n", maxCaps[j], stuffSize[i]);
            insertLast(&arr[j], stuffSize[i]);
            //them phan tu stuffSize vao Node cua maxCap
            cnt++;
            break;
            }
        }
        // Neu khong tim thay ngan xep co kich thuoc bang
        if(cnt == 0) //kiem tra cac ngan xep co dung tich lon hon stuff -> tim ham max
        {
            int posi[N];int check = 0;
            for(int k = 0; k < N; k++){
                if(maxCaps[k] > stuffSize[i])
                {   
                    posi[check] = maxCaps[k];
                    check++;
                    // printf("**%d %d\n", maxCaps[k], stuffSize[i]);
                }
            }
            if (check != 0)
            {
                //them phan tu stuffSize vao Node cua maxCap[max(posi[N], check)];
                insertLast(&arr[max(&posi[N], check)], stuffSize[i]);
            }
        }
    }

    int empty = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] == NULL) empty++;
    }

    int check_khong_full = 0;
    // printf("\n");
    for(int i = 0; i < N; i++){
        if(checkFull(arr[i])) check_khong_full++;
    }

    printf("%d", check_khong_full);

    // printf("\n\n");
    // for(int i = 0; i < N; i++){
    //     while(arr[i] != NULL){
    //         printf("%d ", arr[i]->currCap);
    //         arr[i] = arr[i]->next;
    //     }
    //     printf("\n");
    // }


}