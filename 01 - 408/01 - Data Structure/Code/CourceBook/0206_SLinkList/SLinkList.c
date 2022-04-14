#include "SLinkList.h"

// ��ʼ�����ñ�
void InitSpace(SLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE-1; i++) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;   // Ĭ��0Ϊͷ���
}


// ����ռ�,�ɹ��򷵻�����
int Malloc(SLinkList space) {
	int i = space[0].cur;             
	if (space[0].cur) {
		space[0].cur = space[i].cur;  // s[0].dir ָ����һ�����õĽڵ�λ��
	}
	return i;
}


// ���տռ�
void Free(SLinkList space, int k) {
	// ���±�Ϊk�Ŀռ�ڵ����
	space[k].cur = space[0].cur;
	space[0].cur = k;
}


// ��̬�����ʼ��
Status InitSLinkList(SLinkList space, int* S) {
	int index;

	// ��ʼ�����ÿռ�
	InitSpace(space);
	// ����ͷ���
	index = Malloc(space);

	if (!index) {
		// �ռ��Ѿ���
		return ERROR;
	}

	space[index].cur = 0;

	// ��¼ͷ����λ��
	*S = index;
	return OK;
}


// ���پ�̬����
Status DestroySLinkList(SLinkList space, int* S) {
	int cur;

	// ȷ����̬�������
	if (S == NULL || *S == 0) {
		return ERROR;
	}

	while (*S) {
		// ��һ���ڵ������
		cur = space[*S].cur;
		// �ͷŵ�ǰ�ڵ�
		Free(space, *S);
		// �ڵ����
		*S = cur;
	}
	return OK;
}


// �ͷŷ�ͷ���Ŀռ�
Status ClearSLinkList(SLinkList space, int S) {
	// ȷ����̬�������
	if (S == 0) {
		return ERROR;
	}

	int p = space[S].cur;	// ͷ���
	int cur;

	while (p) {
		// ��һ���ڵ������
		cur = space[p].cur;
		// ���յ�ǰ�ڵ�
		Free(space, p);
		// ����
		p = cur;
	}
	
	space[S].cur = 0;

	return OK;
}

// �п�
Status SLinkListEmpy(SLinkList space, int S) {
	if (S == 0 || space[S].cur == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ��̬������
int SLinkListLength(SLinkList space, int S) {
	// ȷ����̬�������
	if (S == 0 || space[S].cur == 0) {
		return 0;
	}

	int count = 0;
	S = space[S].cur;
	while (S) {
		count++;
		S = space[S].cur;
	}
	return count;
}

// ��ȡ��i��Ԫ��,�洢��e
Status GetSLinkElem(SLinkList space, int S, int i, ElemType* e) {
	// ȷ����̬�������
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}

	int count = 0;
	S = space[S].cur;

	while (S && count < i-1) {
		S = space[S].cur;
		count++;
	}

	// δ�ҵ���iֵ���Ϸ�
	if (S == 0 || count > i-1) {
		return ERROR;
	}

	*e = space[S].data;
	return OK;
}

// ���ؾ�̬�������׸���e����Compare��ϵ��Ԫ��λ��
int LocateSLElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
	// ȷ����̬�������
	if (S == 0 || space[S].cur == 0) {
		return 0;
	}
	
	int i = 1;
	S = space[S].cur;
	while (S && !Compare(space[S].data, e)) {
		S = space[S].cur;
		i++;
	}

	return S ? i : S;
}


// ��̬����ǰ��
Status PriorSLElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e) {
	// ȷ����̬�������
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	int pre, next;
	pre = space[S].cur;
	
	// ��һ��Ԫ��û��ǰ��
	if (space[pre].data == cur_e) {
		return ERROR;
	}
	
	// ��ȡnext
	next = space[pre].cur;

	while (next && space[next].data != cur_e) {
		pre = next;
		next = space[next].cur;
	}

	// û���ҵ�
	if (!next) {
		return ERROR;
	}  else {
		*pre_e = space[pre].data;
	}
	return OK;
}

// ��̬������
Status NextSLElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e) {
	// ȷ����̬�������
	if (!S || !space[S].cur) {
		return ERROR;
	}

	int p = space[S].cur;

	while (space[p].cur && space[p].data != cur_e) {
		p = space[p].cur;
	}

	// δ�ҵ��������һ��
	if (!space[p].cur) {
		return ERROR;
	}

	*next_e = space[space[p].cur].data;
	return OK;
}


// ��̬�������
Status SLinkListInsert(SLinkList space, int S, int i, ElemType e) {
	// ȷ����̬�������
	if (S == 0) {
		return ERROR;
	}
	int p, q, j;

	p = S;
	j = 0;
	while (space[p].cur && j < i - 1) {
		p = space[p].cur;
		j++;
	}

	// iֵ���Ϸ�
	if (!p || j > i - 1) {
		return ERROR;
	}

	// �����µĽڵ�
	q = Malloc(space);
	if (!q) {
		// û�����뵽�ռ�
		return ERROR; 
	}
	space[q].data = e;
	space[q].cur = space[p].cur;
	space[p].cur = q;

	return OK;
}

// ��̬����ɾ��
Status SLinkListDelete(SLinkList space, int S, int i, ElemType* e) {
	// ȷ����̬�������
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	int p, q, j;
	p = S;
	j = 0;
	while (space[p].cur && j < i - 1) {
		p = space[p].cur;
		j++;
	}

	// û�ҵ���i���Ϸ�
	if (!space[p].cur || j > i - 1) {
		return ERROR;
	}

	// Ҫɾ���Ľڵ�
	q = space[p].cur;
	*e = space[q].data;
	space[p].cur = space[q].cur;
	Free(space, q);
	return OK;
}

// ������̬����
Status SLinkListTraverse(SLinkList space, int S, void(Vist)(ElemType)) {
	// ȷ����̬�������
	if (!S || !space[S].cur) {
		return ERROR;
	}

	S = space[S].cur;
	while (S) {
		Vist(space[S].data);
		S = space[S].cur;
	}
	return OK;
}

// ͼ�λ����
void PrintList(SLinkList space, int S) {
	int i = 0;
	printf("---------���ÿռ�----------");
	while (i < 20) {
		printf("%2d    |%2d    %2d    |\n", i, space[i].data, space[i].cur);
		i++;
	}
	i = S;
	printf("----------��̬����----------");
	
	while (i<20) {
		printf("%2d    |%2d    %2d    |\n", i, space[i].data, space[i].cur);
		i++;
	}
}