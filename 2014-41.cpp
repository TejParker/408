//
// Created by 0527 on 2025/7/29.
//
#include <stdio.h>
#include <stdlib.h>
typedef int BiElemType;
typedef struct BiTNode {
    BiElemType weight;// 使用字符的accii值作为weight值
    struct BiTNode *lc;
    struct BiTNode *rc;
}BiTNode, *BiTree;

// tag结构体是辅助队列使用的，用来建队
typedef struct Tag {
    BiTree p;//树某个节点的地址
    struct Tag *next;
}tag_t, *ptag_t;
// 前序遍历也叫：深度优先遍历
//deep代表路径长度
// int wpl = 0;
int WPLPreOrder(BiTree p, int deep) {
    static int wpl = 0; //静态局部变量和全局变量一样，只会初始化一次，区别是只在函数内部有效
    if (p != NULL) {
        if (p->lc == NULL && p->rc == NULL) {
            //当是叶节点时，将叶子节点的weight和deep相乘，再加到wpl上
            wpl = wpl + deep*p->weight;
        }
        WPLPreOrder(p->lc, deep+1);//递归子树，deep+1
        WPLPreOrder(p->rc, deep+1);//递归子树，deep+1
    }
    return wpl;
}

int WPL(BiTree T) {
    return WPLPreOrder(T, 0);
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
        pnew->weight = c;
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
    printf("WPL value: %d\n", WPL(tree));
    return 0;
}


