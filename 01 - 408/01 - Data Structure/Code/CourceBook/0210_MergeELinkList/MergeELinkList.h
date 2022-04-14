#ifndef MERGELINKLIST_H
#define MERGELINKLIST_H

#include "ELinkList.h"

Status MergeElinkList(ELinkList* La, ELinkList* Lb, ELinkList* Lc, int(Compare)(ElemType e1, ElemType e2));

#endif // !MERGELINKLIST_H
