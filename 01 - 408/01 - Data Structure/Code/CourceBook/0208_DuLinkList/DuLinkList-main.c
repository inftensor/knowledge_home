#include "DuLinkList.h"

// e1�Ƿ����e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// ��ӡԪ��
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	DuLinkList L;
	int i;
	ElemType e;

	// ��ʼ������
	printf("��ʼ��...\n");
	InitDuLinkList(&L);

	// �пղ���
	printf("L�Ƿ�Ϊ��?%d\n", DuLinkListEmpty(L));

	// �������
	for (i = 1; i < 13; i++) {
		DuLinkListInsert(L, i, i * i);
	}
	printf("L = ");
	DuLinkListTraverse(L, PrintElem);

	// �����Ȳ���
	printf("������:%d\n", DuLinkListLength(L));

	// ��ȡԪ�ز���
	GetDuLinkListElem(L, 3, &e);
	printf("��%d��Ԫ����%d\n", 3, e);

	// compare����
	printf("��һ����%d���λ����%d\n", 99, LocateDuLinkListElem(L, 99, CmpGreater));

	// ǰ������
	PriorDuLinkListElem(L, 100, &e);
	printf("%d��ǰ����%d\n", 100, e);
	PriorDuLinkListElem(L, 1, &e);
	printf("%d��ǰ����%d\n", 1, e);   // ��һ��û��ǰ��
	PriorDuLinkListElem(L, 33, &e);
	printf("%d��ǰ����%d\n", 33, e);  // û��,e�������ı�

	// ��̲���
	NextDuLinkListElem(L, 100, &e);
	printf("%d�ĺ����%d\n", 100, e);
	NextDuLinkListElem(L, 144, &e);
	printf("%d�ĺ����%d\n", 144, e); // ���һ��û�к��
	NextDuLinkListElem(L, 33, &e);
	printf("%d�ĺ����%d\n", 33, e); // �����ڣ�e�������ı�

	// ɾ������
	DuLinkListDelete(L, 3, &e);
	printf("ɾ���˵�%d��λ�õ�%d\n", 3, e);
	printf("L = ");
	DuLinkListTraverse(L, PrintElem);

	// �ÿղ���
	printf("\nL�Ƿ�Ϊ��?%d\n", DuLinkListEmpty(L));
	ClearDuLinkList(L);
	printf("L�Ƿ�Ϊ��?%d\n", DuLinkListEmpty(L));
}