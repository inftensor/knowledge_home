#include "HString.h"

// ����
void PrintElme(HString S) {
	int i;
	for (i = 0; i <= S.length; i++) {
		printf("%c", S.ch[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	HString S, Sub, V;
	// ��ʼ������
	char words[] = "hello word!";
	AssignHString(&S, words, sizeof(words) / sizeof(char) - 1);
	PrintElme(S);
	char values[] = "or";
	AssignHString(&V, values, sizeof(values) / sizeof(char) - 1);

	// �пղ���
	printf("�Ƿ�Ϊ��?%d\n", HStringEmpty(S));

	// ���Ȳ���
	printf("����Ϊ%d\n", HStringLength(S));

	// �Ӵ�����
	SubHString(&Sub, S, 1, 5);
	printf("S%d��%d���Ӵ�Ϊ��", 1, 5);
	PrintElme(Sub);

	// �״γ��ֲ���
	printf("V��S���״γ���Ϊ%d\n", IndexOfHString(S, V, 1));

	// �������
	HStringInsert(&S, 1, V);
	printf("��ǰ��S = ");
	PrintElme(S);
	// ɾ������
	HStringDelete(&S, 1, 2);
	printf("��ǰ��S = ");
	PrintElme(S);

	// �滻����
	HStringReplace(&S, Sub, V);
	printf("�滻��,S = ");
	PrintElme(S);

	// ���Ӳ���
	printf("Sub = ");
	PrintElme(Sub);
	HStringConcat(&S, Sub, V);
	printf("���Ӻ�,S = ");
	PrintElme(S);

	// �ÿղ���
	ClearHString(&S);
	printf("�Ƿ�Ϊ��?%d\n", HStringEmpty(S));
}

