//
// Created by 0527 on 2025/7/24.
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node  {
    ElemType data;
    struct Node *next;
}NODE, *LinkList;

void list_tail_insert(LinkList &L) {
    //创建头节点
    L = (LinkList)malloc(sizeof(NODE));
    L->next = NULL;
    ElemType x;
    scanf("%d", &x); // 输入要插入的元素
    // s保存每次新分配的节点， r指向链表最后一个元素
    LinkList s, r = L;
    //遇到9999 结束链表插入
    while (x != 9999) {
        s = (LinkList)malloc(sizeof(NODE));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
}
void print_list(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}
// 使用双指针找到链表中间部分，并将原来的链表L截断，L2指向后半段
void find_middle(LinkList &L, LinkList &L2) {
    L2 = (LinkList)malloc(sizeof(NODE));
    //定义双指针,ppre每次走1步，pcur每次走2步
    LinkList ppre=L->next, pcur=L->next;
    while (pcur != NULL) {
        pcur = pcur->next;
        if (pcur == NULL) {
            break;
        }
        pcur = pcur->next;
        if (pcur == NULL) {
            break;
        }
        // ppre走一步
        ppre = ppre->next;
    }
    L2->next = ppre->next;
    ppre->next= NULL;
}
void reverse_list(LinkList &L) {
    // 如果链表为空，或者链表只有一个节点，那么直接返回
    if (L->next == NULL || L->next->next == NULL) {
        return;
    }
    // 定义3个指针，将链表原地反转
    LinkList r=L->next, s=L->next, t=L->next->next;
    while (t != NULL) {
        s->next = r;
        r = s;
        s = t;
        t = t->next;
        /*if (t == NULL) {
            s->next = r;
        }*/
    }
    s->next = r;
    L->next->next=NULL;
    L->next=s;
}
void merge_list(LinkList &L1, LinkList &L2) {
    // l1, l2分别指向各自的当前合并节点
    LinkList l1 = L1->next, l2 = L2->next;
    // 两个临时指针暂存两个链表的合并结点的下一个节点
    LinkList l1_temp, l2_temp;
    while (l1 != NULL && l2 != NULL) {
        l1_temp = l1->next;
        l2_temp = l2->next;
        l1->next = l2;
        l2->next = l1_temp;
        l1 = l1_temp;
        l2 = l2_temp;
    }
    if (l1_temp != NULL) {
        l1->next = l1_temp;
        l1_temp->next = NULL;
    }

}
// 由于合并链表不改变头节点，所以不用传递引用
void merge_list2(LinkList L1, LinkList L2) {
    // 判空，
    if (L1->next == NULL || L2->next == NULL) {
        return;
    }
    LinkList l1 = L1->next;
    LinkList l2 = L2->next;
    // tail指向合并后链表的最后一个节点
    LinkList tail = L1;
    // p1 p2用来暂存下一个要合并的节点
    LinkList p1, p2;
    while (l1 != NULL && l2 != NULL) {
        // 暂存下一个节点
        p1 = l1->next;
        p2 = l2->next;

        // 合并逻辑
        tail->next = l1;
        l1->next = l2;
        tail = l2;

        // 下一个节点分别再赋给L1 , L2
        l1 = p1;
        l2 = p2;

    }
    while (p1 != NULL) {
        tail->next = p1;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        tail->next = p2;
        p2 = p2->next;
    }
    // L2的头节点和第一个节点断开
    L2->next = NULL;

}
int main() {
    LinkList L;
    list_tail_insert(L);
    printf("Original List:\n");
    print_list(L);
    printf("-------------Find Middle-----------------\n");
    // 定义L2，指向原链表的后半段
    LinkList L2;
    find_middle(L, L2);
    print_list(L);
    print_list(L2);
    // 逆转链表
    reverse_list(L2);
    printf("Reversed List:\n");
    print_list(L2);
    // 合并两个链表
    merge_list2(L, L2);
    printf("Merged List:\n");
    print_list(L);
    // 打印验证合并后L2的内容
    printf("----------L2 After Merged--------");
    print_list(L2);
    return 0;
}
