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

// 前序遍历也叫：深度优先遍历
void PreOrder(BiTree p) {
    if (p == NULL) {
        return;
    }
    printf("%c",p->data);
    PreOrder(p->lc);//打印左子树
    PreOrder(p->rc);//打印右子树
}
void InOrder(BiTree p) {
    if (p == NULL) {
        return;
    }
    //先打印左子数
    InOrder(p->lc);
    //再打印自己
    printf("%c",p->data);
    //打印右子树
    InOrder(p->rc);
}
void PostOrder(BiTree p) {
    if (p == NULL) {
        return;
    }
    PostOrder(p->lc);
    PostOrder(p->rc);
    printf("%c",p->data);
}

void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);//树根入队
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);// 出队当前节点并打印
        printf("%c",p->data);
        if (p->lc != NULL) {
            //入队左孩子
            EnQueue(Q, p->lc);
        }
        if (p->rc != NULL) {
            // 入队右孩子
            EnQueue(Q, p->rc);
        }
    }
}

int main() {
    BiTree pnew; //存储树新分配的节点指针
    BiTree tree = NULL;
    BiElemType c;
    ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur=NULL;
    //abcdefghij
    while (scanf("%c", &c)) {
        if (c=='\n') {
            break;
        }
        // pnew = (BiTree)malloc(sizeof(BiTNode));
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->data = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t)); //队列节点申请空间
        listpnew->p = pnew;
        //如果是树的第一个节点，
        if (tree==NULL) {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;// 指向要进入树的父节点
        } else {
            ptail->next = listpnew;
            ptail = listpnew;
            if (pcur->p->lc==NULL) {
                pcur->p->lc = pnew;
            } else if (pcur->p->rc==NULL) {
                pcur->p->rc = pnew;
                pcur = pcur->next;
            }
        }
    }
    printf("----------- Pre Order --------------\n");
    PreOrder(tree);
    printf("\n");
    printf("----------- In  Order --------------\n");
    InOrder(tree);
    printf("\n");
    printf("----------- Post Order --------------\n");
    PostOrder(tree);
    printf("\n");
    printf("----------- Level Order --------------\n");
    LevelOrder(tree);
    return 0;
}

