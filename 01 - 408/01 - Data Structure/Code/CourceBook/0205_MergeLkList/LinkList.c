#include "LinkList.h"

// 初始化链表
Status InitListLk(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(LNode));

	if (*L == NULL) {
		// 内存配失败
		exit(OVERFLOW);
	}
	(*L)->next = NULL;

	return OK;
}

// 销毁链表
Status DestroyListLk(LinkList* L) {
	// 确保链表存在
	if (L == NULL || *L == NULL) {
		return ERROR;
	}

	// 头结点
	LinkList p = *L;


	// 将每个节点都释放内存
	while (p != NULL) {
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}

	*L = NULL;
	return OK;
}


// 置空链表(将非头结点的节点释放)
Status ClearListLk(LinkList L) {
	// 确保链表存在
	if (L == NULL) {
		return ERROR;
	}

	LinkList pre, p;

	p = L->next;

	// 释放p及以后的节点
	while (p != NULL) {
		pre = p;
		p = p->next;
		free(pre);
	}
	L->next = NULL;

	return OK;
}

// 链表判空
Status LkListEmpty(LinkList L) {
	if (L != NULL && L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}


// 链表长度
int LkListLength(LinkList L) {
	// 确保链表存在
	if (L == NULL || L->next == NULL) {
		return 0;
	}

	LinkList p = L->next;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->next;
	}

	return i;
}

// 获取链表第i个元素,并存储到到e中
Status GetLkElem(LinkList L, int i, ElemType* e) {
	// 确保链表存在且不为空
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}

	LinkList p = L;
	int j = 0;

	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	// 未找到或i的值不合法
	if (p->next == NULL || j > i - 1) {
		return ERROR;
	}

	*e = p->next->data;
	return OK;
}


// 返回链表中首个与e满足compare的元素
int LocateLkElem(LinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
	// 确保链表不为空
	if (L == NULL || L->next == NULL) {
		return 0;
	}

	LinkList p = L->next;
	int i = 1;

	// 不满足就后移，直到表尾
	while (p != NULL && !Compare(p->data, e)) {
		p = p->next;
		i++;
	}
	return p == NULL ? 0 : i;
}

// 链表前驱
Status PriorLkElem(LinkList L, ElemType cur_e, ElemType* pre_e) {
	// 确保链表存在
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}

	LinkList pre, next;

	// pre指向第一个元素
	pre = L->next;
	// 第一个元素没有前驱
	if (pre->data == cur_e) {
		return ERROR;
	}
	next = pre->next;

	// 没有找到就后移，直至表尾
	if (next != NULL && next->data != cur_e) {
		pre = next;
		next = next->next;
	}

	// 没有找到
	if (next == NULL) {
		return ERROR;
	}

	*pre_e = pre->data;
	return OK;
}


// 链表后继
Status NextLkElem(LinkList L, ElemType cur_e, ElemType* next_e) {
	// 确保链表存在且不为空
	if (L == NULL && L->next == NULL) {
		return ERROR;
	}

	LinkList pre, next;
	pre = L->next;       //第一个元素
	next = pre->next;

	// 没找到就后移，直至表尾
	if (next != NULL && pre->data != cur_e) {
		pre = next;
		next = next->next;
	}

	// 没找到或是最后一个
	if (next == NULL) {
		return ERROR;
	}

	*next_e = next->data;
	return OK;
}

// 链表插入
Status LkListInsert(LinkList L, int i, ElemType e) {
	// 确保链表存在
	if (L == NULL) {
		return ERROR;
	}

	LinkList p, s;

	p = L;
	int j = 0;

	while (p && j < i - 1) {
		p = p->next;
		j++;
	}

	// i值小于1或i的值大于表长度+1，则为非法
	if (!p || j > i - 1) {
		return ERROR;
	}

	// 生成新的节点
	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL) {
		exit(OVERFLOW);
	}
	// 将节点插入
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}


// 链表删除
Status LkListDelete(LinkList L, int i, ElemType* e) {
	// 确保链表存在且不为空
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}
	LinkList p, q;
	int j = 0;

	p = L;

	// 没找到就后移，直至表尾
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}

	// 未找到或i不合法
	if (!p->next || j > i - 1) {
		return ERROR;
	}

	// 删除元素
	*e = p->next->data;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

// 链表遍历
void LkListTraverse(LinkList L, void(Visit)(ElemType)) {
	// 确保链表存在且不为空
	if (L == NULL || L->next == NULL) {
		return;
	}

	LinkList p = L->next;
	while (p) {
		Visit(p->data);
		p = p->next;
	}
}

// 头插法，需逆序输入
Status CreateLsitLk_Head(LinkList* L, int n, char* path) {
	LinkList p;
	int i;
	FILE* fp;
	fp = fopen(path, "r");
	if (!fp) {
		// 文件打卡失败
		return ERROR;
	}
	// 建立头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;

	for (i = 1; i <= n; i++) {
		// 生成新的节点
		p = (LinkList)malloc(sizeof(LNode));
		// 读取数据
		fscanf(fp, "%d", &(p->data)); //这里的测试数据都是用int 
		p->next = (*L)->next;
		(*L)->next = p;
	}
	fclose(fp);
	return OK;
}


// 尾插法
Status CreateListLk_Tail(LinkList* L, int n, char* path) {
	LinkList p, q;
	FILE* fp;
	int i;
	fp = fopen(path, "r");
	if (!fp) {
		// 打开失败
		return ERROR;
	}
	// 创建头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;

	for (i = 0, q = *L; i < n; i++) {
		// 创建新的节点
		p = (LinkList)malloc(sizeof(LNode));
		fscanf(fp, "%d", &(p->data));

		// 插入到链表中
		q->next = p;
		q = q->next;
	}
	q->next = NULL;
	fclose(fp);

	return OK;
}