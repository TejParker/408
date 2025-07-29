//
// Created by 0527 on 2025/7/29.
//
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
    return 0;
}

