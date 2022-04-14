#include "WordList.h"


// 主函数
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

// 初始化索引表
void InitIdxList(IdxListType* idexlist) {
	char chars[] = "关键词          书号索引";
	IdxTermType e;

	AssignHString(&(e.key), chars, strlen(chars));
	InitELinkList($(e.bnolist));

	idexlist->item[0] = e;
	idexlist->last = 0;
}


// 读取数目信息
void GetLine(FILE* f) {
	fgets(gBuf, MAXLINELEN, f);
}


// 提取关键词
void ExtractKeyWord(ElemType* bno) {
	char delim[] = { '-', ' ', '\r', '\n', '\t' };
	char* title;
	char* token;

	*bno = (int)strtol(gBuf, &title, 10);
	// 书名小写
	strlwr(title);

	gWdList.last = 0;
	// 分割字符串
	for (token = strtok(title, delim); token != NULL; token = strtok(NULL, delim)) {
		if (isCommonWords(token)) {
			continue;
		}
		gWdList.item[gWdList.last++] = token;
	}
}


// 插入索引表
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

// 返回关键词
void GetWord(int i, HString* wd) {
	if (i<0 || i>gWdList.last - 1) {
		AssignHString(wd, "", 0);
	} else {
		AssignHString(wd, gWdList.item[i], strlen(gWdList.item[i]));
	}
}

// 查找
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


// 插入关键词
void InsertNewKey(IdxListType* idxlist, int i, HString wd) {
	int j;
	for (j = idxlist->last; j >= i; j--) {  // i后面的元素后移
		idxlist->item[j + 1] = idxlist->item[j];
	}
	HStringCopy(&(idxlist->item[i].key), wd);  // 插入元素
	InitELinkList(&(idxlist->item[i].bnolist)); // 给书号索引初始化
	idxlist->last++;
}



// 插入书籍序号
Status InsertBook(IdxListType* idxlist, int i, int bno) {
	ELink p;
	if (!MakeNode(&p, bno)) {
		exit(OVERFLOW);  // 内存分配失败
	}

	ELinkListAppend(&(idxlist->item[i].bnolist), p);
	return OK;
}


// 输出信息
void PutText(FILE* g, IdxListType idxlist) {
	int i, j, m, n;
	ELink p;
	HString S;
	ELinkList L;

	if (idxlist.last <= 0) {
		return;
	}

	// 输出表头
	S = idxlist.item[0].key;
	for (m = 0; m <= S.length; m++) {
		fprintf(g, "%c", S.ch[m]);
	}
	fprintf(g, "\n");

	// 输出索引信息
	for (i = 0; i <= idxlist.last; i++) {
		// 输出关键词
		S = idxlist.item[i].key;
		for (m = 0; m <= S.length; m++) {
			fprintf(g, "%c", S.ch[m]);
		}


		// 输出空格
		for (j = 1; j <= 18 - idxlist.item[i].key.length; j++) {
			fprintf(g, " ");
		}

		// 输出索引号
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


// 判断是否为常用的
static Status isCommonWords(char* str) {
	int i;

	WordListType words = {{"a", "an", "the", "of", "and", "is", "to", "as", "in", "for"}, 10};
	for (i = 0; i < words.last; i++) {
		if (strcmp(str, words.item[i] == 0)) {  // 忽略大小写比较
			return TRUE;
		}
	}
	return FALSE;
}


