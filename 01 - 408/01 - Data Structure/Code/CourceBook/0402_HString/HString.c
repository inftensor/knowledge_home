#include "HString.h"

// 初始化
Status AssignHString(HString* T, const char* words, int len_words) {
    int i;
    if (len_words <= 0) {
        // 表示建立空的
        T->ch = NULL;
        T->length = 0;
        return OK;
    } 
    T->ch = (char*)malloc(len_words*sizeof(char));
    if (!T->ch) {
        // 内存分配失败
        exit(OVERFLOW);
    }
    T->length = len_words;
    for (i=0; i<len_words; i++) {
        T->ch[i] = words[i];
    }
    return OK;
}

// 置空
Status ClearHString(HString* S) {
    // 确保存在
    if (!S) {
        return ERROR;
    }
    if (S->length) {
        free(S->ch);
        S->ch = NULL;
        S->length = 0;
    }
    return OK;
}


// 判空
Status HStringEmpty(HString S) {
    return S.length ? FALSE: TRUE;
}

// 长度
int HStringLength(HString S) {
    return S.length;
}

// 子串
Status SubHString(HString* Sub, HString S, int pos, int len) {
    // 保证存在
    if (pos < 1|| pos>S.length || len <0 || pos+len-1>S.length) {
        return ERROR;
    }
    // len = 0 , 则返回空串
    if (len==0) {
        Sub->ch = NULL;
        Sub->length = 0;
        return OK;
    }
    int i;
    Sub->ch = (char*) malloc(len*sizeof(char));
    Sub->length = len;
    for (i=0; i<len; i++) {
        Sub->ch[i] = S.ch[pos-1+i];
    }
    return OK;
}


// 首次出现
int IndexOfHString(HString S, HString T, int pos) {
    // 确保pos合理
    if (pos<1 || pos>S.length || S.length <=0 || T.length <=0) {
        return 0;
    }

    char *i, *j;
    // i,j分别指向S和T
    i = S.ch;
    j = T.ch;
    while (i-S.ch< S.length && j-T.ch < T.length) {
        if (*i == *j) { // 匹配就后移
            i++;
            j++;
        } else { // 不匹配就回退
            i = i - (j-T.ch)+1;
            j = T.ch;
        }
    }

    if (j-T.ch == T.length) { // 说明整个j都匹配上了
        /* 
            目前i是匹配的末尾,距离匹配的首地址相差 = j与T.ch的距离 
        */
        return (i-S.ch) - (j- T.ch) + 1;   
    } else {
        return 0;
    }
}

// 插入
Status HStringInsert(HString* S, int pos, HString T) {
    // 确保存在且插入合理
    if (!S || pos<1||pos>S->length+1) {
        return ERROR;
    }
    // 如果插入的是空，直接返回
    if (HStringEmpty(T)) {
        return OK;
    }

    int i;
    // 重新分配空间给S的ch
    S->ch = (char*)realloc(S->ch, (S->length+T.length)*sizeof(char));
    if (!S->ch) {
        exit(OVERFLOW);  // 内存分配失败
    }
    // 插入之后的元素后移
    for (i=S->length-1; i>=pos-1; i--) {
        S->ch[i+T.length] = S->ch[i];
    }
    // 插入T元素
    for (i=0; i<T.length; i++) {
        S->ch[pos+i-1] = T.ch[i];
    }
    S->length = S->length+T.length;
    return OK;
}

// 删除
Status HStringDelete(HString* S, int pos, int len) {
    // 确保存在且合法
    if (!S || S->length<=0 || pos<1 || pos+len-1>S->length) {
        return ERROR;
    }
    // 如果删除长度为0，直接返回
    if (len==0) {
        return OK;
    }

    int i;
    // 将后面的元素前移
    for (i=0; i<(S->length-len); i++) {
        S->ch[pos+i-1] = S->ch[pos+i-1+len];
    }
    S->length -= len;
    // 缩减空间
    S->ch = (char*) realloc (S->ch, S->length*sizeof(char));

    return OK;
}

// 比较串
int HStringCmp(HString S, HString T) {
    int i = 0;
    while (i<S.length && i<T.length) {
        if (S.ch[i] != T.ch[i]) { // 不同则比较字符大小
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

// 复制
Status HStringCopy(HString* T, HString S) {
    int i;
    if (HStringEmpty(S)) {
        T->ch = NULL;
        T->length = 0;
    } else {
        // 分配空间
        T->ch = (char*) malloc (S.length*sizeof(char));
        if (!T->ch) {
            exit(OVERFLOW);
        }

        // 复制元素
        for (i=0; i<S.length; i++) {
            T->ch[i] = S.ch[i];
        }
    }
    return OK;
}


// 替换
Status HStringReplace(HString* S, HString T, HString V) {
    int i;

    if (HStringEmpty(*S) || HStringEmpty(T)) {
        return ERROR;
    }
    i = IndexOfHString(*S, T, 1);
    while (i) {
        HStringDelete(S, i, T.length);
        HStringInsert(S, i, V);
        i += V.length;
        i = IndexOfHString(*S, T, i);
    }
    return OK;
}

// 连接
Status HStringConcat(HString* T, HString S1, HString S2) {
    int i;
    T->length = S1.length + S2.length;
    T->ch = (char*) malloc (T->length*sizeof(char));

    // 复制S1的元素
    for (i=0; i<S1.length ; i++) {
        T->ch[i] = S1.ch[i];
    }

    // 复制S2的元素
    for (i=0; i<S2.length; i++) {
        T->ch[S1.length+i] = S2.ch[i];
    }

    return OK;
