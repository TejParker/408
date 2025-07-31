//
// Created by 0527 on 2025/7/31.
//
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct {
    ElemType *data;
    int len;
}SSTable;

void ST_INIT(SSTable & ST, int len) {
    ST.len = len + 1;
    ST.data = (ElemType *)malloc(sizeof(ElemType) * ST.len);
    int i;
    srand(time(NULL));
    for (i = 1; i < ST.len; i++) {
        ST.data[i] = rand() % 100;
    }
}

void ST_Print(SSTable  ST) {
    for (int i = 1; i < ST.len; i++) {
        printf("%d ", ST.data[i]);
    }
    printf("\n");
}

int SS_Search(SSTable ST, int key) {
    ST.data[0] = key; // 让零号元素作为哨兵
    int i;
    for (i = ST.len -1; ST.data[i] !=key; --i);
    return i;
}
int main() {
    SSTable ST;
    ST_INIT(ST, 10);
    ST_Print(ST);
    ElemType val;
    int pos;
    printf("Please input the value to search:\n");
    scanf("%d", &val);
    pos = SS_Search(ST, val);
    if (pos) {
        printf("find key: position= %d\n", pos);
    }else {
        printf("not find.\n");
    }
    return 0;

}
