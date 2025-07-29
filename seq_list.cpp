//
// Created by 0527 on 2025/7/25.
//

#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SeqList;

void InitList(SeqList *L) {
    for (int i = 0; i < MaxSize; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
}
void PrintList(SeqList *L) {
    for (int i = 0; i<MaxSize; i++) {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    SeqList L;
    PrintList(&L);
    InitList(&L);
    PrintList(&L);

    return 0;

}
