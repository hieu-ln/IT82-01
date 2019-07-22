#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef struct Node{
    int heso;
    int somu;
    Node* Next;
};
typedef Node* DaThuc;
 
void ktRong(DaThuc &dt){
    dt = (Node*)malloc(sizeof(Node));
    dt->Next = NULL;
}
void them(int hs,int sm, DaThuc &dt){
    if (hs==0)
        return;
 
    DaThuc p = dt;
 
    while(p->Next!=NULL){
        p=p->Next;
    }
 
    Node* t = (Node*)malloc(sizeof(Node));
    t->heso = hs;
    t->somu = sm;
    t->Next = NULL;
 
    p->Next = t;
 
}
void congDT(DaThuc dt1,DaThuc dt2, DaThuc &dt3){
    DaThuc p = dt1;
    DaThuc q = dt2;
    while(p->Next!=NULL && q->Next!=NULL){
        if (p->Next->somu > q->Next->somu){
            them(p->Next->heso,p->Next->somu,dt3);
            p=p->Next;
        }
        else   if (p->Next->somu < q->Next->somu){
            them(q->Next->heso,q->Next->somu,dt3);
            q=q->Next;
        }
        else{
            them(p->Next->heso + q->Next->heso,p->Next->somu,dt3);
            p=p->Next;
            q=q->Next;
        }
    }
    while(p->Next != NULL){
        them(p->Next->heso,p->Next->somu,dt3);
        p=p->Next;
    }
    while(q->Next != NULL){
        them(q->Next->heso,q->Next->somu,dt3);
        q=q->Next;
    }
}
void inDT(DaThuc dt){
    DaThuc p = dt->Next;
    while(p!=NULL){
 
        if (p->somu==1)
            printf("%dx",p->heso);
        else if (p->somu==0)
            printf("%d",p->heso);
        else
            printf("%dx^%d",p->heso,p->somu);
        p=p->Next;
        if (p!=NULL && p->heso>=0)
            printf("+");
 
    }
}
 
int main(){
 
    DaThuc dt1,dt2;
    ktRong(dt1);
    ktRong(dt2);
    them(4,6,dt1);
    them(3,5,dt1);
    them(-3,1,dt1);
    them(2,0,dt2);
    them(6,-4,dt2);
    printf("Da thuc 1: ");
    inDT(dt1);
    printf("\nDa thuc 2: ");
    inDT(dt2);
    DaThuc dt3;
    ktRong(dt3);
    congDT(dt1,dt2,dt3);
    printf("\nDa thuc 3: ");
    inDT(dt3);
    return 0;
}

