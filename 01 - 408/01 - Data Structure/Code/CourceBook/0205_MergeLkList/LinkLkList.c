#include "MergeLkList.h"



// 合并有序链表
void MergeLkList(LinkList* La, LinkList* Lb, LinkList* Lc) {
	LinkList pa, pb, pc;
	pa = (*La)->next;
	pb = (*Lb)->next;
	pc = *Lc = *La;		// 将La的头结点作为Lc的头结点


	while (pa && pb) {
		// pc 指向小的那个
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	// 哪个剩余接哪个
	pc->next = (pa ? pa : pb);

	// 释放Lb的头结点
	free(*Lb);
	*La = NULL;
	*Lb = NULL;
}