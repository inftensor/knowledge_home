#include "SString.h"


// 初始化
Status AssignSString(SString T, const char* words, int len_words) {
    int i, len;
    len = len_words;
    
    // 是否过长
    if (len > MAXSTRLEN) { 
        return ERROR;
    }

    T[0] = len; // 第一位置存放长度
    for (i=1; i<=len; i++) {
        T[i] = words[i-1];
    }
    
    return OK;
}

// // 销毁
// Status DestorySString(SString S) { // 顺序串没有销毁
//     return OK;
// }

// 置空
Status ClearSString(SString S) {
    S[0] = 0;
    return OK;
}

// 判空
Status SStringEmpty(SString S) {
    return !S[0] ? TRUE : FALSE;
}

// 长度
int SStringLength(SString S) {
    return S[0];
}

// 子串
Status SubSString(SString Sub, SString S, int pos, int len) {
    // 先判断子串位置是否越界
    if (pos<1 || pos>S[0] || len <0 || pos+len-1>S[0]) {
        return ERROR;
    }

    int i;
    for (i=1; i<=len; i++) {
        Sub[i] = S[pos+i-1];
    }

    Sub[0] = len;
    return OK;
}


// 首次出现(依赖子串)
int IndexOfSString1(SString S, SString T, int pos) {
    // 查找失败情况
    if (pos <1 || pos > S[0] || SStringEmpty(T)) {
        return 0;
    }

    int i, m, n;
    SString Sub;

    n = SStringLength(S);
    m = SStringLength(T);
    i = pos;

    while (i<=n-m+1) {
        SubSString(Sub, S, i, m);  // 取出子串后比较
        if (SStringCmp(Sub, T) != 0) { // 不匹配
            i++;
        } else {
            return i;
        }
    }
    return 0;
}


// 首次出现(不依赖子串)
int IndexOfSString2(SString S, SString T, int pos) {
    // 查找失败情况
    if (pos < 1 || pos > S[0] || SStringEmpty(T)) {
        return 0;
    }

    int i, j;

    i = pos;
    j = 1;
    while (i<=S[0] && j<=T[0]) {
        if(S[i] == T[j]) { // 匹配上，直接后移
            i++;
            j++;
        } else { //不匹配，回退
            /* 
            因为此时移动的步数为j-1(j的初值为1)， 
            则i先退回原来的，有 i=i-(j-1);
            然后i后移一位,有: 
            i = [i-(j-1)] +1 => i = i-j+2;
            */
            i = i-j+2;    
            j = 1;
        }
    }

    if (j > T[0]) {
        return i-T[0];  // 返回 i-j+1也行
    } else {
        return 0;
    }
}

// 插入
Status SStringInsert(SString S, int pos, SString T) {
    // 确保插入位置合理
    if (pos <1 || pos > S[0]+1 || S[0] + T[0] > MAXSTRLEN) {
        return ERROR;
    }

    // 如果T为空,则直接返回
    if (SStringEmpty(T)) {
        return OK;
    }

    int i = pos;
    // 先将S的元素后移
    for (i=S[0]; i>=pos; i--) {
        S[i+T[0]] = S[i];
    }
    // 插入T元素
    for (i=pos; i<pos+T[0]; i++) {
        S[i] = T[i-pos+1];
    }

    S[0] += T[0];
    return OK;
}

// 删除
Status SStringDelete(SString S, int pos, int len) {
    // 确保删除合法
    if (pos < 1 || pos+len-1 > S[0] || len<0) {
        return ERROR;
    }

    // 如果len=0，直接返回
    if (!len) {
        return OK;
    }

    int i;
    for (i=pos; i<=S[0]-len; i++) {
        S[i] = S[i+len];
    }
    S[0] -= len;

    return OK;
}


// 比较串
int SStringCmp(SString S, SString T) {
    int i = 1;
    while (i<=S[0] && i<=T[0]) {
        if (S[i] != T[i]) {
            return S[i] - T[i];
        }
        i++;
    }
    return S[0] - T[0];  // 前i个一致，比较长度
}

// 复制
Status SStringCopy(SString T, SString S) {
    int i;
    
    for (i=0; i<S[0]; i++) {
        T[i] = S[i];
    }
    return OK;
}

// 替换
Status SStringReplace(SString S, SString T, SString V) {
    // 确保存在
    if (SStringEmpty(S) || SStringEmpty(T)) {
        return ERROR;
    }

    int i = IndexOfSString2(S, T, 1); // 寻找首次出现的位置
    while (i && S[0]-T[0]+V[0] <= MAXSTRLEN) { // 确保能插入
        SStringDelete(S, i, T[0]);  // 先删除找到的
        SStringInsert(S, i, V);

        i += SStringLength(V);
        i  = IndexOfSString2(S, T, i);  // 寻找后一个
    }

    return i ? FALSE : OK;  // i>0说明插不下了

}

// 连接
Status SStringConcat(SString T, SString S1, SString S2) {
   int i;
   if (S1[0] +S2[0] <= MAXSTRLEN) {
       // 不需要截断
       for (i=1;i<=S1[0]; i++) {
           T[i] = S1[i];
       }
       for (i=1; i<=S2[0]; i++) {
           T[i+S1[0]] = S2[i];
       }
       T[0] = S1[0]+S2[0];
       return TRUE;
   } else {
       for (i=1; i<S1[0]; i++) {
           T[i] = S1[i];
       }
       // 除非S1刚好全部占满，否则要插入部分S2
       if (S1[0] < MAXSTRLEN) {
           for (i=1; i<MAXSTRLEN-S1[0]+1; i++) {
               T[i+S1[0]] = S2[i];
           }
       }
       T[0] = MAXSTRLEN;
       return FALSE;  // 表示有截断
   }
}