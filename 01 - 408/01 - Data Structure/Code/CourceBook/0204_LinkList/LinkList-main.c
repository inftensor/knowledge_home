#include "LinkList.h"

// e1�Ƿ����e2
Status CmpGreater(ElemType e1, ElemType e2) {
	return e1 > e2 ? TRUE : FALSE;
}

// ��ӡԪ��
void PrintElem(ElemType e) {
	printf("%d ", e);
}


int main(int argc, char** argv) {
	LinkList L;
	int i;
	ElemType e;

	// ��ʼ������
	printf("��ʼ��...\n");
	InitListLk(&L);

	// �пղ���
	printf("L�Ƿ�Ϊ��?%d\n", LkListEmpty(L));

	// �������
	for (i = 1; i < 13; i++) {
		LkListInsert(L, i, i * i);
	}
	printf("L = ");
	LkListTraverse(L, PrintElem);

	// �����Ȳ���
	printf("\n������:%d\n", LkListLength(L));

	// ��ȡԪ�ز���
	GetLkElem(L, 3, &e);
	printf("��%d��Ԫ����%d\n", 3, e);

	// compare����
	printf("��һ����%d���λ����%d\n", 99, LocateLkElem(L, 99, CmpGreater));

	// ǰ������
	PriorLkElem(L, 100, &e);
	printf("%d��ǰ����%d\n", 100, e);
	PriorLkElem(L, 1, &e);
	printf("%d��ǰ����%d\n", 1, e);   // ��һ��û��ǰ��
	PriorLkElem(L, 33, &e);
	printf("%d��ǰ����%d\n", 33, e);  // û��,e�������ı�

	// ��̲���
	NextLkElem(L, 100, &e);
	printf("%d�ĺ����%d\n", 100, e);
	NextLkElem(L, 144, &e);
	printf("%d�ĺ����%d\n", 144, e); // ���һ��û�к��
	NextLkElem(L, 33, &e);
	printf("%d�ĺ����%d\n", 33, e); // �����ڣ�e�������ı�

	// ɾ������
	LkListDelete(L, 3, &e);
	printf("ɾ���˵�%d��λ�õ�%d\n", 3, e);
	printf("L = ");
	LkListTraverse(L, PrintElem);

	// �ÿղ���
	printf("\nL�Ƿ�Ϊ��?%d\n", LkListEmpty(L));
	ClearListLk(L);
	printf("L�Ƿ�Ϊ��?%d\n", LkListEmpty(L));

	// ͷ�巨����
	LinkList h;
	CreateLsitLk_Head(&h, 6, "head.txt");
	printf("h = ");
	LkListTraverse(h, PrintElem);

	// β�巨����
	LinkList t;
	CreateListLk_Tail(&t, 6, "tail.txt");
	printf("\nt = ");
	LkListTraverse(t, PrintElem);
	return 0;
}