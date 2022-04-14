#include <stdio.h>
#include "SqList.h"

// �ж�Ԫ���Ƿ����
Status CmpGreater(ElemType e1, ElemType e2) {
    return e1 > e2 ? TRUE : FALSE;
}


// Ϊ�˲��ԣ���ӡ��Ԫ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char** argv) {
    SqList L;
    int i;
    ElemType e;

    // ��ʼ������
    printf("InitList\n");
    InitListSq(&L);

    // �������
    for (i = 0; i < 12; i++) {
        printf("��L��elem�ĵ�%dλ����%d\n", i + 1, i * i);
        SqListInsert(&L, i + 1, i * i);
    }
    printf("������ɺ�L��elemΪ:\n");
    SqListTraverse(L, PrintElem);
    printf("\n");
    // ɾ������
    SqListDelete(&L, 3, &e);
    printf("ɾ����ɵ�%d��Ԫ��%d��,L��elemΪ:\n", 3, e);
    SqListTraverse(L, PrintElem);
    printf("\n");

    // �����п�
    printf("L�Ƿ�Ϊ�գ�%d\n", SqListEmpty(L));

    // Locate����
    printf("L�е�һ������%d��λ����%d\n", 100, LocateSqElem(L,100, CmpGreater));
    printf("L�е�һ������%d��λ����%d\n", 200, LocateSqElem(L, 200, CmpGreater));

    // PriorSqElem����
    PriorSqElem(L, 100, &e);
    printf("%d��ǰ����%d\n", 100, e);
    PriorSqElem(L, 0, &e);
    printf("%d��ǰ����%d\n", 1, e); // û�иı� e

    // NextSqElem ����
    NextSqElem(L, 100, &e);
    printf("%d�ĺ����%d\n", 100, e);
    NextSqElem(L, 121, &e);
    printf("%d�ĺ����%d\n", 121, e); // ����ı� e

    // Clear����
    ClearListSq(&L);
    printf("L�Ƿ�Ϊ�գ�%d\n", SqListEmpty(L));
    return 0;

    // Destroy����
    DestroyListSq(&L);
    printf("L��elem�Ƿ�Ϊ��? %d\n", L.elem == NULL);

}