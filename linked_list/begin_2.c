#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int num;
    struct Node* next;
}Node;

Node* makeNode(int n){
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->num = n;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node*h, int n){
    if(h == NULL){
        h = makeNode(n);
    }
    else{
        Node* p = makeNode(n);
        p->next = h;
        h = p;
    }
}

void insertLast(Node*p, int n){
    if(p == NULL){
        p = makeNode(n);
    }
    else{
        Node *cur = p;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = makeNode(n);
    }

}

Node* removeFirst(Node*h, int n){
    Node*p = h;
    if(p == NULL){
        printf("Danh sach rong!");
        return p;
    }
    if(p-> num == n){
        h = p->next;
        return p;
    }
    else{
        while(p->next->next != NULL){
            if (p->next->num == n){
                p-> next = p->next->next;
                return p;
            }
            else{
                p = p->next;
            }
        }
        if (p->next->num == n){
            p->next = NULL;
        } return p;
    }
}

// Node* removeAll(Node*h, int n){
//     Node* current = h;
//     Node* previous = NULL;
//     if(current == NULL){
//         printf("Danh sach rong!");
//         return current;
//     }
//     while(current != NULL){
//         if(current != NULL && current->num != n){
//             previous = current;
//             current = current->next;
//         }
//         if(previous == NULL){
//             printf("Xuân cu\n");
//             return current->next;
//         }
//         else{
//             previous->next = current->next;
//             free(current);
//             current = previous->next;
//         }
//     }
//     return current;
// }

void removeAll(Node**h, int v){
    Node* current = *h;
    Node* previous = NULL;
    if(current == NULL){
        printf("Danh sach rong!");
        return;
    }
    while(current != NULL){
        if(current->num == v && previous == NULL){
            *h = current-> next;
            free(current);
            current = *h;
        }
        else if (current->num == v && previous != NULL){
            previous->next = current->next;
            free(current);
            current = previous->next;

        }
        else{
            previous = current;
            current = current->next;
        }
    }
}

Node* removeAllrecur (Node*h, int v){
    if(h == NULL) return NULL;
    if(h->num == v){
        Node*tmp = h;
        h = h-> next;
        free(tmp);
        h=removeAllrecur(h,v);
        return h;
    }
    h->next = removeAllrecur(h->next, v);
    return h;
}

void printList(Node*h){
    while(h != NULL){
        printf("%d ", h->num);
        h = h->next;
    }
    printf("\n");
}

void count(Node*h){
    int cnt = 0;
    while(h != NULL){
        cnt++;
        h = h->next;
    }
    printf("So luong phan tu la %d!\n", cnt);
    return;
}

int main(){
    Node* number = NULL;
    for(int i = 1; i < 11; i++){
        insertLast(number, i);
    }

    printList(number);
    // removeFirst(number,10);
    // removeAll3(number, 10);
    insertFirst(number,100);
    printList(number);
    // count(number);
    return 0;
}


