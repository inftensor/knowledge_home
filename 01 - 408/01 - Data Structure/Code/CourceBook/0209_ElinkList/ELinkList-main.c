#include "ELinkList.h"

// e1�Ƿ����e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// ��ӡԪ��
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	ELink p;
	ELinkList L;
	int i;
	ElemType e;
	EPosition pos;

	// ��ʼ������
	printf("��ʼ��...\n");
	InitELinkList(&L);

	// �пղ���
	printf("L�Ƿ�Ϊ��?%d\n", ELinkListEmpty(L));

	// �������
	for (i = 1; i < 13; i++) {
		ELinkListInsert(&L, i, i * i);
	}
	printf("L = ");
	ELinkListTraverse(L, PrintElem);

	// �����Ȳ���
	printf("������:%d\n", ELinkListLength(L));

	// ��ȡԪ�ز���
	ELinkListLocatePos(L, 3, &p);
	printf("��%d��Ԫ����%d\n", 3, GetELinkListCurElem(p));

	// compare����
	printf("��һ����%d���Ԫ����%d\n", 99, GetELinkListCurElem(ELinkListLocate(L, 99, CmpGreater)));

	// ǰ������
	printf("%d��ǰ����%d\n", GetELinkListCurElem(p), GetELinkListCurElem(ELinkListPriorPos(L, p)));


	//// ��̲���
	printf("%d�ĺ����%d\n", GetELinkListCurElem(p), GetELinkListCurElem(ELinkListNextPos(L, p)));

	// ɾ������
	ELinkListDelete(&L, 3, &e);
	printf("ɾ���˵�%d��λ�õ�%d\n", 3, e);
	printf("L = ");
	ELinkListTraverse(L, PrintElem);

	// β������
	pos = GetElinkListTail(L);
	printf("β���Ϊ%d\n", pos->data);

	// ǰ������
	printf("%d��ǰ����%d\n", pos->data, ELinkListPriorPos(L, pos)->data);

	pos = L.head->next;
	// ��̲���
	printf("%d�ĺ����%d\n", pos->data, ELinkListNextPos(L, pos)->data);
	// �ÿղ���
	printf("\nL�Ƿ�Ϊ��?%d\n", ELinkListEmpty(L));
	ClearELinkList(&L);
	printf("L�Ƿ�Ϊ��?%d\n", ELinkListEmpty(L));
}
