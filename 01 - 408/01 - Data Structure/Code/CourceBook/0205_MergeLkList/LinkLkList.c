#include "MergeLkList.h"



// �ϲ���������
void MergeLkList(LinkList* La, LinkList* Lb, LinkList* Lc) {
	LinkList pa, pb, pc;
	pa = (*La)->next;
	pb = (*Lb)->next;
	pc = *Lc = *La;		// ��La��ͷ�����ΪLc��ͷ���


	while (pa && pb) {
		// pc ָ��С���Ǹ�
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

	// �ĸ�ʣ����ĸ�
	pc->next = (pa ? pa : pb);

	// �ͷ�Lb��ͷ���
	free(*Lb);
	*La = NULL;
	*Lb = NULL;
}