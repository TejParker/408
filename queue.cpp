//
// Created by 0527 on 2025/7/29.
//

#include "function.h"

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

void EnQueue(LinkQueue &Q, ElemType e) {
    LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
    pnew->data = e;
    pnew->next = NULL;
    Q.rear->next = pnew;
    Q.rear = pnew;
}

bool DeQueue(LinkQueue &Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    }
    LinkNode *p = Q.front->next;//拿到第一个节点，存取p
    e = p->data;//获取出队的元素值
    Q.front->next = p->next;//队头断链
    // 队中只有一个元素时，出队后，队尾要指向队头
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}