#include "SLinkList.h"

// e1�Ƿ����e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// ��ӡԪ��
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	SLinkList space;
	int i;
	ElemType e;
	int S;
	// ��ʼ������
	InitSLinkList(space, &S);
	// �������
	for (i = 1; i < 14; i++) {
		SLinkListInsert(space, S, i, i*i);
	}
	printf("���� = ");
	SLinkListTraverse(space, S, PrintElem);
	
	// �пճ�ɶ
	printf("\n�����Ƿ�Ϊ��%d\n", SLinkListEmpy(space, S));

	// ���Ȳ���
	printf("������%d\n", SLinkListLength(space, S));

	// ȡ������
	GetSLinkElem(space, S, 3, &e);
	printf("����ĵ�%d��Ԫ����%d\n", 3, e);
	GetSLinkElem(space, S, -1, &e);
	printf("����ĵ�%d��Ԫ����%d\n", -1, e);

	// Compare����
	printf("��һ������%d������λ��Ϊ%d\n", 99, LocateSLElem(space, S, 99, CmpGreater));
	printf("��һ������%d������λ��Ϊ%d\n", 200, LocateSLElem(space, S, 200, CmpGreater));
	
	// ǰ������
	PriorSLElem(space, S, 100, &e);
	printf("%d��ǰ��Ϊ%d\n", 100, e);
	PriorSLElem(space, S, 33, &e);
	printf("%d��ǰ��Ϊ%d\n", 33, e);

	// ��̲���
	NextSLElem(space, S, 100, &e);
	printf("%d�ĺ��Ϊ%d\n", 100, e);
	NextSLElem(space, S, 99, &e);
	printf("%d�ĺ��Ϊ%d\n", 99, e);

	// ɾ������
	SLinkListDelete(space, S, 3, &e);
	printf("ɾ����%d����%d��\n", 3, e);
	printf("����Ϊ:");
	SLinkListTraverse(space, S, PrintElem);

	// ���ٲ���
	ClearSLinkList(space, S);
	printf("\n�Ƿ�Ϊ��?%d\n", SLinkListEmpy(space, S));
}