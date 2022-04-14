#include <stdlib.h>
#include "DuLinkList.h"



// ��ʼ��
Status InitDuLinkList(DuLinkList* L) {
	*L = (DuLinkList)malloc(sizeof(DuLNode));

	if (!L) {
		// �ڴ����ʧ��
		exit(OVERFLOW);
	}

	(*L)->next = (*L)->prior = *L;
	return OK;
}

// ����
Status DestroyDuLinkList(DuLinkList* L) {
	// ȷ��ѭ���������
	if (!L || !(*L) ){
		return ERROR;
	}
	// �����������ڵ�
	ClearDuLinkList(*L);

	// ����ͷ���
	free(*L);
	*L = NULL;

	return OK;
}

// �ÿ�
Status ClearDuLinkList(DuLinkList L) {
	// ȷ��ѭ���������
	if (!L) {
		return ERROR;
	}

	DuLinkList p, q;
	p = L->next;

	// ɾ���ڵ㣬ֱ��Ϊ��
	while ( p != L ) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L->prior = L;
	return OK;
}


// �п�
Status DuLinkListEmpty(DuLinkList L) {
	if (L && L->next == L && L->prior == L) {
		return TRUE;
	}   else {
		return FALSE;
	}
}


// ��ȡ����
int DuLinkListLength(DuLinkList L) {
	// ȷ����Ϊ��
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


// ȡ��i��ֵ
Status GetDuLinkListElem(DuLinkList L, int i, ElemType* e) {
	// ȷ�������Ҳ�Ϊ��
	if (!L || L->next == L || L->prior == L) {
		return ERROR;
	}

	DuLinkList p = L;
	int j = 0;

	while (p->next != L && j < i - 1) {
		p = p->next;
		j++;
	}

	// iֵ���Ϸ�
	if (p->next == L || j > i - 1) {
		return ERROR;
	}

	*e = p->next->data;
	return OK;
}

// �����׸���e����Compare��λ��
int LocateDuLinkListElem(DuLinkList L, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
	// ȷ�������Ҳ�Ϊ��
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


// ǰ��
Status PriorDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* pre_e) {
	// ȷ�������Ҳ�Ϊ��
	if (!L || L->prior == L || L->next == L) {
		return ERROR;
	}
	DuLinkList cur = L;
	// ��һ���ڵ�û��ǰ��
	if (cur->next->data == cur_e) {
		return ERROR;
	}

	while (cur->next != L && cur->next->data != cur_e) {
		cur = cur->next;
	}

	// û�ҵ�
	if (cur->next == L) {
		return ERROR;
	}

	*pre_e = cur->data;
	return OK;
}

// ���
Status NextDuLinkListElem(DuLinkList L, ElemType cur_e, ElemType* next_e) {
	// ��֤��Ϊ��
	if (!L || L->prior == L || L->next == L) {
		return ERROR;
	}
	DuLinkList p = L->next;  // ��һ��Ԫ��

	while (p->next != L && p->data != cur_e) {
		p = p->next;
	}

	// ���һ���ڵ��û���ҵ�
	if (p->next == L) {
		return ERROR;
	}
	*next_e = p->next->data;

	return OK;
}

// ����
Status DuLinkListInsert(DuLinkList L, int i, ElemType e) {
	// ȷ������
	if (!L) {
		return ERROR;
	}

	DuLinkList p, q;
	p = L;
	int j = 0;

	if (!(p=GetDuLinkListElemP(L, i))) {
		return ERROR;
	}

	// �����µĽڵ�
	q = (DuLinkList)malloc(sizeof(DuLNode)); 
	if (!q) {
		// �ڴ����ʧ��
		exit(OVERFLOW);
	}
	q->data = e;
	q->prior = p->prior;
	p->prior->next = q;
	q->next = p;
	p->prior = q;
	return OK;
}

// ɾ��
Status DuLinkListDelete(DuLinkList L, int i, ElemType* e) {
	// ȷ�������Ҳ�Ϊ��
	if (!L || L->next == L || L->prior == L) {
		return ERROR;
	}

	int j = 0;
	DuLinkList p;

	if (!(p = GetDuLinkListElemP(L, i))) {
		return ERROR;	// û�ҵ�
	}

	*e = p->data;

	// ɾ��p
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return;
}

// ����
void DuLinkListTraverse(DuLinkList L, void(Visit)(ElemType e)) {
	// ȷ����Ϊ��
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



// ��ȡ��i��Ԫ�ص�����
static DuLinkList GetDuLinkListElemP(DuLinkList L, int i) {
	// ȷ��������i�Ϲ�
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
	// iֵ�Ƿ�Խ��
	if (j + 1 < i) {
		return NULL;
	}

	// ��������Ҫ��len+1ǰ���롣
	return L;
}