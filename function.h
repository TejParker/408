//
// Created by 0527 on 2025/7/29.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include<stdio.h>
#include <stdlib.h>
typedef char BiElemType;
typedef struct BiTNode {
    BiElemType data;
    struct BiTNode *lc;
    struct BiTNode *rc;
}BiTNode, *BiTree;

// tag结构体是辅助队列使用的，用来建队
typedef struct Tag {
    BiTree p;//树某个节点的地址
    struct Tag *next;
}tag_t, *ptag_t;
////////////////////////////

typedef BiTree ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct {
    LinkNode *front, *rear;//队列头和队尾
}LinkQueue;
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q, ElemType e);
bool DeQueue(LinkQueue &Q, ElemType &e);

#endif //FUNCTION_H
