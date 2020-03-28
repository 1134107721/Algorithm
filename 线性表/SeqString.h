//顺序字符串 Demo
//用最基础的代码实现 strlen() strcat() strcpy()这些东西
#ifndef SEQSTRING_H_INCLUDED
#define SEQSTRING_H_INCLUDED


/*  这种方法是用数组存贮结构，是定长的（MAXSIZE）。缺点是浪费空间
typedef struct{     //顺序串
    char ch[MAX_SIZE];  //存储字符的数组
    int length;     //串的当前长度
}SString;
*/
typedef struct{     //堆结构存储
    char * ch;      //如果是非空串，那么按照指定长度分配内存，否则ch就指向null
    int length;
}HString;
//初始化串
void InitHeapString(HString * str);
//为串str赋值  值为字符串常量chars
int AssignHeapString(HString * str, char* chars);
//打印堆字符串
void PrintHeapString(HString * str);


#endif // SEQSTRING_H_INCLUDED
