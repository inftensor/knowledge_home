#include <stdlib.h>
#include "DuLinkList.h"



// 初始化
Status InitDuLinkList(DuLinkList* L) {
	*L = (DuLinkList)malloc(sizeof(DuLNode));

	if (!L) {
		// 内存分配失败
		exit(OVERFLOW);
	}

	(*L)->next = (*L)->prior = *L;
	return OK;
}

// 销毁
Status DestroyDuLinkList(DuLinkList* L) {
	// 确保循环链表存在
	if (!L || !(*L) ){
		return ERROR;
	}
	// 先清零其他节点
	ClearDuLinkList(*L);

	// 销毁头结点
	free(*L);
	*L = NULL;

	return OK;
}

// 置空
Status ClearDuLinkList(DuLinkList L) {
	// 确保循环链表存在
	if (!L) {
		return ERROR;
	}

	DuLinkList p, q;
	p = L->next;

	// 删除节点，直到为空
	while ( p != L ) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L->prior = L;
	return OK;
}


// 判空
Status DuLinkListEmpty(DuLinkList L) {
	if (L && L->next == L && L->prior == L) {
		return TRUE;
	}   else {
		return FALSE;
	}
}


// 获取长度
int DuLinkListLength(DuLinkList L) {
	// 确保不为空
	if (L == NULL || L->next==L || L->prior==L) {
		return 0;
	}

	DuLinkList p = L->next;
	int i = 0;

	while (p != L) {
		p = p->next;
		i++;
	}

	return i;
}


// 取第i个值
Status GetDuLinkListElem(DuLinkList L, int i, ElemType* e) {
	// 确保存在且不为空
	if (!L || L->next == L || L->prior == L) {
		return ERROR;
	}

	DuLinkList p = L;
	int j = 0;

	while (p->next != L && j < i - 1) {
		p = p->next;
		j++;
	}

	// i值不合法
	if (p->next == L || j > i - 1) {
		return ERROR;
	}

	*e = p->next->data;
	return OK;
}

// 返回首个和e满足Compare的位置
int LocateDuLinkListElem(DuLinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
	// 确保存在且不为空
	if (!L || L->next == L || L->prior == L) {
		return 0;
	}

	int i = 0;
	DuLinkList p = L;
	while (p->next != L && !(Compare(p->next->data, e))) {
		p = p->next;
		i++;
	}

	return p->next == L ? 0 : i;
}


// 前驱
Status PriorDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* pre_e) {
	// 确保存在且不为空
	if (!L || L->prior == L || L->next == L) {
		return ERROR;
	}
	DuLinkList cur = L;
	// 第一个节点没有前驱
	if (cur->next->data == cur_e) {
		return ERROR;
	}

	while (cur->next != L && cur->next->data != cur_e) {
		cur = cur->next;
	}

	// 没找到
	if (cur->next == L) {
		return ERROR;
	}

	*pre_e = cur->data;
	return OK;
}

// 后继
Status NextDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* next_e) {
	// 保证不为空
	if (!L || L->prior == L || L->next == L) {
		return ERROR;
	}
	DuLinkList p = L->next;  // 第一个元素

	while (p->next != L && p->data != cur_e) {
		p = p->next;
	}

	// 最后一个节点或没有找到
	if (p->next == L) {
		return ERROR;
	}
	*next_e = p->next->data;

	return OK;
}

// 插入
Status DuLinkListInsert(DuLinkList L, int i, ElemType e) {
	// 确保存在
	if (!L) {
		return ERROR;
	}

	DuLinkList p, q;
	p = L;
	int j = 0;

	if (!(p=GetDuLinkListElemP(L, i))) {
		return ERROR;
	}

	// 创建新的节点
	q = (DuLinkList)malloc(sizeof(DuLNode)); 
	if (!q) {
		// 内存分配失败
		exit(OVERFLOW);
	}
	q->data = e;
	q->prior = p->prior;
	p->prior->next = q;
	q->next = p;
	p->prior = q;
	return OK;
}

// 删除
Status DuLinkListDelete(DuLinkList L, int i, ElemType* e) {
	// 确保存在且不为空
	if (!L || L->next == L || L->prior == L) {
		return ERROR;
	}

	int j = 0;
	DuLinkList p;

	if (!(p = GetDuLinkListElemP(L, i))) {
		return ERROR;	// 没找到
	}

	*e = p->data;

	// 删除p
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return;
}

// 遍历
void DuLinkListTraverse(DuLinkList L, void(Visit)(ElemType e)) {
	// 确保不为空
	if (!L || L->next==L || L->prior==L) {
		return;
	}
	DuLinkList p = L;
	while (p->next != L) {
		Visit(p->next->data);
		p = p->next;
	}
	printf("\n");
}



// 获取第i个元素的引用
static DuLinkList GetDuLinkListElemP(DuLinkList L, int i) {
	// 确保存在且i合规
	if ( !L || i<1 ) {
		return NULL;
	}
	DuLinkList p = L;
	int j = 0;

	while (p->next != L && j < i) {
		p = p->next;
		j++;
	}
	if (j == i) {
		return p;
	}
	// i值是否越界
	if (j + 1 < i) {
		return NULL;
	}

	// 以下是需要在len+1前插入。
	return L;
}