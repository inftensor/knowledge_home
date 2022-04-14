#include "SLinkList.h"

// 初始化备用表
void InitSpace(SLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE-1; i++) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;   // 默认0为头结点
}


// 申请空间,成功则返回索引
int Malloc(SLinkList space) {
	int i = space[0].cur;             
	if (space[0].cur) {
		space[0].cur = space[i].cur;  // s[0].dir 指明下一个可用的节点位置
	}
	return i;
}


// 回收空间
void Free(SLinkList space, int k) {
	// 将下标为k的空间节点回收
	space[k].cur = space[0].cur;
	space[0].cur = k;
}


// 静态链表初始化
Status InitSLinkList(SLinkList space, int* S) {
	int index;

	// 初始化备用空间
	InitSpace(space);
	// 申请头结点
	index = Malloc(space);

	if (!index) {
		// 空间已经满
		return ERROR;
	}

	space[index].cur = 0;

	// 记录头结点的位置
	*S = index;
	return OK;
}


// 销毁静态链表
Status DestroySLinkList(SLinkList space, int* S) {
	int cur;

	// 确保静态链表存在
	if (S == NULL || *S == 0) {
		return ERROR;
	}

	while (*S) {
		// 下一个节点的索引
		cur = space[*S].cur;
		// 释放当前节点
		Free(space, *S);
		// 节点后移
		*S = cur;
	}
	return OK;
}


// 释放非头结点的空间
Status ClearSLinkList(SLinkList space, int S) {
	// 确保静态链表存在
	if (S == 0) {
		return ERROR;
	}

	int p = space[S].cur;	// 头结点
	int cur;

	while (p) {
		// 下一个节点的索引
		cur = space[p].cur;
		// 回收当前节点
		Free(space, p);
		// 后移
		p = cur;
	}
	
	space[S].cur = 0;

	return OK;
}

// 判空
Status SLinkListEmpy(SLinkList space, int S) {
	if (S == 0 || space[S].cur == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 静态链表长度
int SLinkListLength(SLinkList space, int S) {
	// 确保静态链表存在
	if (S == 0 || space[S].cur == 0) {
		return 0;
	}

	int count = 0;
	S = space[S].cur;
	while (S) {
		count++;
		S = space[S].cur;
	}
	return count;
}

// 获取第i个元素,存储到e
Status GetSLinkElem(SLinkList space, int S, int i, ElemType* e) {
	// 确保静态链表存在
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}

	int count = 0;
	S = space[S].cur;

	while (S && count < i-1) {
		S = space[S].cur;
		count++;
	}

	// 未找到或i值不合法
	if (S == 0 || count > i-1) {
		return ERROR;
	}

	*e = space[S].data;
	return OK;
}

// 返回静态链表中首个和e满足Compare关系的元素位置
int LocateSLElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType e1, ElemType e2)) {
	// 确保静态链表存在
	if (S == 0 || space[S].cur == 0) {
		return 0;
	}
	
	int i = 1;
	S = space[S].cur;
	while (S && !Compare(space[S].data, e)) {
		S = space[S].cur;
		i++;
	}

	return S ? i : S;
}


// 静态链表前驱
Status PriorSLElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e) {
	// 确保静态链表存在
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	int pre, next;
	pre = space[S].cur;
	
	// 第一个元素没有前驱
	if (space[pre].data == cur_e) {
		return ERROR;
	}
	
	// 获取next
	next = space[pre].cur;

	while (next && space[next].data != cur_e) {
		pre = next;
		next = space[next].cur;
	}

	// 没有找到
	if (!next) {
		return ERROR;
	}  else {
		*pre_e = space[pre].data;
	}
	return OK;
}

// 静态链表后继
Status NextSLElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e) {
	// 确保静态链表存在
	if (!S || !space[S].cur) {
		return ERROR;
	}

	int p = space[S].cur;

	while (space[p].cur && space[p].data != cur_e) {
		p = space[p].cur;
	}

	// 未找到或是最后一个
	if (!space[p].cur) {
		return ERROR;
	}

	*next_e = space[space[p].cur].data;
	return OK;
}


// 静态链表插入
Status SLinkListInsert(SLinkList space, int S, int i, ElemType e) {
	// 确保静态链表存在
	if (S == 0) {
		return ERROR;
	}
	int p, q, j;

	p = S;
	j = 0;
	while (space[p].cur && j < i - 1) {
		p = space[p].cur;
		j++;
	}

	// i值不合法
	if (!p || j > i - 1) {
		return ERROR;
	}

	// 生成新的节点
	q = Malloc(space);
	if (!q) {
		// 没有申请到空间
		return ERROR; 
	}
	space[q].data = e;
	space[q].cur = space[p].cur;
	space[p].cur = q;

	return OK;
}

// 静态链表删除
Status SLinkListDelete(SLinkList space, int S, int i, ElemType* e) {
	// 确保静态链表存在
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	int p, q, j;
	p = S;
	j = 0;
	while (space[p].cur && j < i - 1) {
		p = space[p].cur;
		j++;
	}

	// 没找到或i不合法
	if (!space[p].cur || j > i - 1) {
		return ERROR;
	}

	// 要删除的节点
	q = space[p].cur;
	*e = space[q].data;
	space[p].cur = space[q].cur;
	Free(space, q);
	return OK;
}

// 遍历静态链表
Status SLinkListTraverse(SLinkList space, int S, void(Vist)(ElemType)) {
	// 确保静态链表存在
	if (!S || !space[S].cur) {
		return ERROR;
	}

	S = space[S].cur;
	while (S) {
		Vist(space[S].data);
		S = space[S].cur;
	}
	return OK;
}

// 图形化输出
void PrintList(SLinkList space, int S) {
	int i = 0;
	printf("---------备用空间----------");
	while (i < 20) {
		printf("%2d    |%2d    %2d    |\n", i, space[i].data, space[i].cur);
		i++;
	}
	i = S;
	printf("----------静态链表----------");
	
	while (i<20) {
		printf("%2d    |%2d    %2d    |\n", i, space[i].data, space[i].cur);
		i++;
	}
}