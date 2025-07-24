//
// Created by 0527 on 2025/7/22.
//

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
} Node, *LinkList;

void list_insert(LinkList &L, ElemType x) {
    if (L == NULL) {
        L = (LinkList)malloc(sizeof(Node));
        L->next = nullptr;
    }
    LinkList q = (LinkList)malloc(sizeof(Node));
    q->data = x;
    q->next = L->next;
    L->next = q;
}
void list_tail_insert(LinkList &L, ElemType x) {
    // 如果头指针为空，先创建头节点
    if (L == NULL) {
        L = (LinkList)malloc(sizeof(Node));
        L->next = nullptr;
    }
    LinkList q = (LinkList)malloc(sizeof(Node));
    q->data = x;
    q->next = nullptr;
    // 定义一个尾指针
    LinkList p = L;
    while (nullptr != p -> next) {
        p = p->next;
    }
    p -> next = q;
}

// 根据位置返回对应节点
LinkList GetElem(LinkList L, int pos) {
    if (pos < 0) {
        return NULL;
    }
    int i=0;
    while (L && i < pos) {
        L = L->next;
        i = i + 1;
    }
    return L;
}

// 根据值查元素
LinkList LocateElem(LinkList L, ElemType x) {
    while (L) {
        if (L->data == x) {
            return L;
        }
        L = L->next;
    }
    return NULL;
}

bool InsertValueByPos(LinkList L, int pos, ElemType x) {
    if (pos <= 0) {
        return false;
    }
    LinkList preNode = GetElem(L, pos-1);
    if (preNode == nullptr) {
        return false;
    }
    LinkList p = (LinkList)malloc(sizeof(Node));
    p->data = x;
    p->next = preNode->next;
    preNode->next = p;
    return true;
}

void list_print(LinkList L) {
    if (NULL == L || NULL == L->next) {
        return;
    }
    LinkList q = L->next;
    while (NULL != q) {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int main() {
    LinkList L = NULL;
    ElemType val;
    for (int i = 1; i <= 5; i++) {
        scanf("%d", &val);
        // list_insert(L, val);
        list_tail_insert(L, val);
    }
    list_print(L);
    LinkList node = GetElem(L, 5);
    if (NULL != node) {
        printf("Succeed found element in position\n");
        printf("%d\n", node->data);
    }
    LinkList n = LocateElem(L, 6);
    if (NULL != n) {
        printf("Succeed found element value\n");
        printf("%d\n", n->data);
    }
    printf("=============\n");
    scanf("%d", &val);
    bool ret = false;
    ret = InsertValueByPos(L, 7, val);
    if (ret) {
        printf("Insert value successfully\n");
        list_print(L);
    } else {
        printf("Insert failed\n");
    }

    return 0;
}