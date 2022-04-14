#include "Difference.h"

void PrintElem(ElemType e) {
	printf("%d ", e);
}

int main(int garc, char** argv) {
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 2, 4, 6, 8, 10 };
	SLinkList space;
	int S;

	Difference(space, &S, a, 5, b, 5);
	printf("(A-B)U(B-A)=");
	SLinkListTraverse(space, S, PrintElem);
}