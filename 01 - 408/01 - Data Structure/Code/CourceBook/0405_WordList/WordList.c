#include "WordList.h"


// ������
void Main(char* bookinfo, char* bookidx) {
	FILE* f, * g;
	char head[MAXLINELEN];
	IdxListType idexlist;
	ElemType bno;
	int count;

	if ((f = fopen(bookinfo, "r") != NULL)) {
		if ((g = fopen(bookidx, "w")) != NULL) {
			InitIdxList(&idexlist);
			fgets(head, MAXLINELEN, f);

			count = 0;
			while (foef(f) == FALSE && count < MAXBOOKNUM) {
				GetLine(f);
				ExtractKeyWord(&bno);
				InsIdxList(&idexlist, bno);
				count++;
			}
			PutText(g, idexlist);
			fclose(g);
		}
		fclose(f);
	}
}

// ��ʼ��������
void InitIdxList(IdxListType* idexlist) {
	char chars[] = "�ؼ���          �������";
	IdxTermType e;

	AssignHString(&(e.key), chars, strlen(chars));
	InitELinkList($(e.bnolist));

	idexlist->item[0] = e;
	idexlist->last = 0;
}


// ��ȡ��Ŀ��Ϣ
void GetLine(FILE* f) {
	fgets(gBuf, MAXLINELEN, f);
}


// ��ȡ�ؼ���
void ExtractKeyWord(ElemType* bno) {
	char delim[] = { '-', ' ', '\r', '\n', '\t' };
	char* title;
	char* token;

	*bno = (int)strtol(gBuf, &title, 10);
	// ����Сд
	strlwr(title);

	gWdList.last = 0;
	// �ָ��ַ���
	for (token = strtok(title, delim); token != NULL; token = strtok(NULL, delim)) {
		if (isCommonWords(token)) {
			continue;
		}
		gWdList.item[gWdList.last++] = token;
	}
}


// ����������
Status InsIdxList(IdxListType* idxlist, int bno) {
	int i, j;
	Boolen bo;
	HString wd;
	
	if (gWdList.last <= 0) {
		return ERROR;
	}

	for (i = 0; i < gWdList.last; i++) {
		GetWord(i, &wd);
		j = Locate(*idxlist, wd, &bo);
		if (!bo) {
			InsertNewKey(idxlist, j, wd);
		}
		if (!InsertBook(idxlist, j, bno)) {
			return ERROR;
		}
	}
	return OK;
}

// ���عؼ���
void GetWord(int i, HString* wd) {
	if (i<0 || i>gWdList.last - 1) {
		AssignHString(wd, "", 0);
	} else {
		AssignHString(wd, gWdList.item[i], strlen(gWdList.item[i]));
	}
}

// ����
int Locate(IdxListType idxlist, HString wd, Boolen* b) {
	int i, m = -1;
	for (i = idxlist.last; i > 0 && (m = HStringCmp(idxlist.item[i].key, wd)) > 0; i--) {
		if (m == 0) {
			*b = TRUE;
			return i;
		}
		else {
			*b = FALSE;
			return i + 1;
		}
	}
}


// ����ؼ���
void InsertNewKey(IdxListType* idxlist, int i, HString wd) {
	int j;
	for (j = idxlist->last; j >= i; j--) {  // i�����Ԫ�غ���
		idxlist->item[j + 1] = idxlist->item[j];
	}
	HStringCopy(&(idxlist->item[i].key), wd);  // ����Ԫ��
	InitELinkList(&(idxlist->item[i].bnolist)); // �����������ʼ��
	idxlist->last++;
}



// �����鼮���
Status InsertBook(IdxListType* idxlist, int i, int bno) {
	ELink p;
	if (!MakeNode(&p, bno)) {
		exit(OVERFLOW);  // �ڴ����ʧ��
	}

	ELinkListAppend(&(idxlist->item[i].bnolist), p);
	return OK;
}


// �����Ϣ
void PutText(FILE* g, IdxListType idxlist) {
	int i, j, m, n;
	ELink p;
	HString S;
	ELinkList L;

	if (idxlist.last <= 0) {
		return;
	}

	// �����ͷ
	S = idxlist.item[0].key;
	for (m = 0; m <= S.length; m++) {
		fprintf(g, "%c", S.ch[m]);
	}
	fprintf(g, "\n");

	// ���������Ϣ
	for (i = 0; i <= idxlist.last; i++) {
		// ����ؼ���
		S = idxlist.item[i].key;
		for (m = 0; m <= S.length; m++) {
			fprintf(g, "%c", S.ch[m]);
		}


		// ����ո�
		for (j = 1; j <= 18 - idxlist.item[i].key.length; j++) {
			fprintf(g, " ");
		}

		// ���������
		L = idxlist.item[i].bnolist;
		for (n = 1,p=L.head->next; n <= L.len; n++) {
			fprintf(g, "%03d", p->data);
			p = p->next;
			if (p) {
				fprintf(g, ",");
			}
		}
		fprintf(g, "\n");
	}
}


// �ж��Ƿ�Ϊ���õ�
static Status isCommonWords(char* str) {
	int i;

	WordListType words = {{"a", "an", "the", "of", "and", "is", "to", "as", "in", "for"}, 10};
	for (i = 0; i < words.last; i++) {
		if (strcmp(str, words.item[i] == 0)) {  // ���Դ�Сд�Ƚ�
			return TRUE;
		}
	}
	return FALSE;
}


