#include "LinkList.h"

// ��ʼ������
Status InitListLk(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(LNode));

	if (*L == NULL) {
		// �ڴ���ʧ��
		exit(OVERFLOW);
	}
	(*L)->next = NULL;

	return OK;
}

// ��������
Status DestroyListLk(LinkList* L) {
	// ȷ���������
	if (L == NULL || *L == NULL) {
		return ERROR;
	}

	// ͷ���
	LinkList p = *L;


	// ��ÿ���ڵ㶼�ͷ��ڴ�
	while (p != NULL) {
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}

	*L = NULL;
	return OK;
}


// �ÿ�����(����ͷ���Ľڵ��ͷ�)
Status ClearListLk(LinkList L) {
	// ȷ���������
	if (L == NULL) {
		return ERROR;
	}

	LinkList pre, p;

	p = L->next;

	// �ͷ�p���Ժ�Ľڵ�
	while (p != NULL) {
		pre = p;
		p = p->next;
		free(pre);
	}
	L->next = NULL;

	return OK;
}

// �����п�
Status LkListEmpty(LinkList L) {
	if (L != NULL && L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}


// ������
int LkListLength(LinkList L) {
	// ȷ���������
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

// ��ȡ�����i��Ԫ��,���洢����e��
Status GetLkElem(LinkList L, int i, ElemType* e) {
	// ȷ����������Ҳ�Ϊ��
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}

	LinkList p = L;
	int j = 0;

	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	// δ�ҵ���i��ֵ���Ϸ�
	if (p->next == NULL || j > i - 1) {
		return ERROR;
	}

	*e = p->next->data;
	return OK;
}


// �����������׸���e����compare��Ԫ��
int LocateLkElem(LinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
	// ȷ������Ϊ��
	if (L == NULL || L->next == NULL) {
		return 0;
	}

	LinkList p = L->next;
	int i = 1;

	// ������ͺ��ƣ�ֱ����β
	while (p != NULL && !Compare(p->data, e)) {
		p = p->next;
		i++;
	}
	return p == NULL ? 0 : i;
}

// ����ǰ��
Status PriorLkElem(LinkList L, ElemType cur_e, ElemType* pre_e) {
	// ȷ���������
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}

	LinkList pre, next;

	// preָ���һ��Ԫ��
	pre = L->next;
	// ��һ��Ԫ��û��ǰ��
	if (pre->data == cur_e) {
		return ERROR;
	}
	next = pre->next;

	// û���ҵ��ͺ��ƣ�ֱ����β
	if (next != NULL && next->data != cur_e) {
		pre = next;
		next = next->next;
	}

	// û���ҵ�
	if (next == NULL) {
		return ERROR;
	}

	*pre_e = pre->data;
	return OK;
}


// ������
Status NextLkElem(LinkList L, ElemType cur_e, ElemType* next_e) {
	// ȷ����������Ҳ�Ϊ��
	if (L == NULL && L->next == NULL) {
		return ERROR;
	}

	LinkList pre, next;
	pre = L->next;       //��һ��Ԫ��
	next = pre->next;

	// û�ҵ��ͺ��ƣ�ֱ����β
	if (next != NULL && pre->data != cur_e) {
		pre = next;
		next = next->next;
	}

	// û�ҵ��������һ��
	if (next == NULL) {
		return ERROR;
	}

	*next_e = next->data;
	return OK;
}

// �������
Status LkListInsert(LinkList L, int i, ElemType e) {
	// ȷ���������
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

	// iֵС��1��i��ֵ���ڱ���+1����Ϊ�Ƿ�
	if (!p || j > i - 1) {
		return ERROR;
	}

	// �����µĽڵ�
	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL) {
		exit(OVERFLOW);
	}
	// ���ڵ����
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}


// ����ɾ��
Status LkListDelete(LinkList L, int i, ElemType* e) {
	// ȷ����������Ҳ�Ϊ��
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}
	LinkList p, q;
	int j = 0;

	p = L;

	// û�ҵ��ͺ��ƣ�ֱ����β
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}

	// δ�ҵ���i���Ϸ�
	if (!p->next || j > i - 1) {
		return ERROR;
	}

	// ɾ��Ԫ��
	*e = p->next->data;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

// �������
void LkListTraverse(LinkList L, void(Visit)(ElemType)) {
	// ȷ����������Ҳ�Ϊ��
	if (L == NULL || L->next == NULL) {
		return;
	}

	LinkList p = L->next;
	while (p) {
		Visit(p->data);
		p = p->next;
	}
}

// ͷ�巨������������
Status CreateLsitLk_Head(LinkList* L, int n, char* path) {
	LinkList p;
	int i;
	FILE* fp;
	fp = fopen(path, "r");
	if (!fp) {
		// �ļ���ʧ��
		return ERROR;
	}
	// ����ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;

	for (i = 1; i <= n; i++) {
		// �����µĽڵ�
		p = (LinkList)malloc(sizeof(LNode));
		// ��ȡ����
		fscanf(fp, "%d", &(p->data)); //����Ĳ������ݶ�����int 
		p->next = (*L)->next;
		(*L)->next = p;
	}
	fclose(fp);
	return OK;
}


// β�巨
Status CreateListLk_Tail(LinkList* L, int n, char* path) {
	LinkList p, q;
	FILE* fp;
	int i;
	fp = fopen(path, "r");
	if (!fp) {
		// ��ʧ��
		return ERROR;
	}
	// ����ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;

	for (i = 0, q = *L; i < n; i++) {
		// �����µĽڵ�
		p = (LinkList)malloc(sizeof(LNode));
		fscanf(fp, "%d", &(p->data));

		// ���뵽������
		q->next = p;
		q = q->next;
	}
	q->next = NULL;
	fclose(fp);

	return OK;
}