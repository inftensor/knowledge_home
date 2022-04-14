#include "LString.h"

/*
    这个目前先不搞，太繁琐，利用价值低。
*/

// 初始化
Status AssignLString(LString* T, const char* words, int len_words) {
    // 空字符串
    if (len_words == 0) {
        T->head = T->tail = NULL;
        T->curlen = 0;
        return OK;
    }

    int i, count;
    int m;  // 需要填满的块数    
    int n;  // 如果未填满，则计算有效数
    Chunk* r;

    m = len_words / CHUNKSIZE;
    n = len_words % CHUNKSIZE;

    if (!n) { // 不是整除，需要加一块
        m++;
    }

    // 创建块
    for (i=1; i<=m; i++) {
        // 创建块
        r = (Chunk*)malloc(sizeof(Chunk));
        if (!r) {
            exit(OVERFLOW);
        }
        r->next = NULL;
        if (i==1) {
            T->head = T->tail = r;
        } else {
            T->tail->next = r;
            T->tail = r;
        }
    }

    // 将内容写进块里面
    r = T->head;
    i = 0;
    count =0;

    while (count <len_words) {
        r->ch[i] = words[count];
        i = (i+1) % CHUNKSIZE;
        if (!i) { // 已经填满一个，进入下一个块
            r = r->next;
        } 
        count++;
    }

    // 将没有存满信息的块填充
    if (n) {
        while (i < CHUNKSIZE) {
            T->tail->ch[i] = '\0';
            i++;
        }
    }

    T->curlen = len_words;
    return OK;
}


// 置空
Status ClearLString(LString* S) {
    // 确保存在
    if (!S || !S->head) {
        return ERROR;
    }
    Chunk* p, *q;
    p = S->head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    S->head = S->tail = NULL;
    S->curlen = 0;
    return OK;
}


// 判空
Status LStringEmpty(LString S) {
    return S.curlen ? TRUE :FALSE;
}


// 长度
int LStringLength(LString S) {
    return S.curlen;
}

// 子串
Status SubLString(LString* Sub, LString S, int pos, int len) {
    // 判断是否合理
    if (pos<1 || pos>S.curlen || len<0 || pos+len-1 >S.curlen) {
        return ERROR;
    }
    // 如果len =0 ,不必创建
    if (len==0) {
        Sub->head = Sub->tail = NULL;
        Sub->curlen = 0;
        return OK;
    }

    // 这里代码复用，先把S的len个元素存到临时数组里，再调用上面的
    int count = 0;  // 计数
    int i = 0;      // 块内位置
    Chunk* p = S.head;
    char* tmp = (char*)malloc(sizeof(char)*len);
    int j = 0;     // 临时数组下标
    if (!tmp) {
        exit(OVERFLOW);
    }
    // 遍历S,把pos后len个元素存到tmp
    while (p && count < pos+len) {
        if (count >=pos-1 ) { // 是子串
            tmp[j++] = p->ch[i]; 
        }

        i = (i+1) % CHUNKSIZE;
        if (!i) { // 这个块已经用完了
            p = p->next;
        }
    }
    AssignLString(Sub, tmp, len);
    return OK;
}


// 首次出现(依赖子串)
int IndexOfLString(LString S, LString T, int pos) {
    // 确保合理
    if (pos<1 || pos>S.curlen || LStringEmpty(T)) {
        return ERROR;
    }

    int i, s,t;
    LString Sub;

    s = S.curlen;
    t = T.curlen;
    i = pos;
    while (i+t-1 <= s) {
        // 获取子串
        SubLString(&Sub, S, i, t);
        if (LStringCmp(Sub, T) != 0) {
            i++;
        }  else {
            return i;
        }
    }
    return 0;
}


// 插入
Status LStringInsert(LString* S, int pos, LString T) {
    
}