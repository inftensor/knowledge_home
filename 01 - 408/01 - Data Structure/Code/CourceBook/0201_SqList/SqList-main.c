#include <stdio.h>
#include "SqList.h"

// 判断元素是否大于
Status CmpGreater(ElemType e1, ElemType e2) {
    return e1 > e2 ? TRUE : FALSE;
}


// 为了测试，打印出元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char** argv) {
    SqList L;
    int i;
    ElemType e;

    // 初始化测试
    printf("InitList\n");
    InitListSq(&L);

    // 插入测试
    for (i = 0; i < 12; i++) {
        printf("向L的elem的第%d位插入%d\n", i + 1, i * i);
        SqListInsert(&L, i + 1, i * i);
    }
    printf("插入完成后，L的elem为:\n");
    SqListTraverse(L, PrintElem);
    printf("\n");
    // 删除测试
    SqListDelete(&L, 3, &e);
    printf("删除完成第%d个元素%d后,L的elem为:\n", 3, e);
    SqListTraverse(L, PrintElem);
    printf("\n");

    // 测试判空
    printf("L是否为空？%d\n", SqListEmpty(L));

    // Locate测试
    printf("L中第一个大于%d的位置是%d\n", 100, LocateSqElem(L,100, CmpGreater));
    printf("L中第一个大于%d的位置是%d\n", 200, LocateSqElem(L, 200, CmpGreater));

    // PriorSqElem测试
    PriorSqElem(L, 100, &e);
    printf("%d的前驱是%d\n", 100, e);
    PriorSqElem(L, 0, &e);
    printf("%d的前驱是%d\n", 1, e); // 没有改变 e

    // NextSqElem 测试
    NextSqElem(L, 100, &e);
    printf("%d的后继是%d\n", 100, e);
    NextSqElem(L, 121, &e);
    printf("%d的后继是%d\n", 121, e); // 不会改变 e

    // Clear测试
    ClearListSq(&L);
    printf("L是否为空？%d\n", SqListEmpty(L));
    return 0;

    // Destroy测试
    DestroyListSq(&L);
    printf("L的elem是否为空? %d\n", L.elem == NULL);

}