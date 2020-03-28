#include "SeqString.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//初始化串
void InitHeapString(HString * str){
    str->ch = NULL;
    str->length = 0;
}
//为串str赋值  值为字符串常量chars
int AssignHeapString(HString * str, char* chars){
    int len = strlen(chars);
    if(!len)    //如果chars是空串，那么返回-1.代表失败
        return -1;
    InitHeapString(str);
    str->ch = (char*)malloc(len * sizeof(char));     //为str里面的ch申请内存空间 原因是ch也是char*类型的
    for(int i = 0; i < len; i++){
        str->ch[i] = chars[i];
    }
    str->length = len;
    return 1;   //插进去了返回1 代表成功
}
//打印堆字符串
void PrintHeapString(HString * str){
    for(int i = 0; i < str->length; i++)
        printf("%c", str->ch[i]);
}
//将串srcstr的内容复制到deststr里面
int StrCpyHeapString(HString * destStr, HString * srcStr){
    InitHeapString(destStr);
    if(IsHeapStringEmpty(srcStr)){
        printf("要复制的字符串不能为空");
        return 0;
    }
    destStr->ch = (char*)malloc(sizeof(char) * srcStr->length);
    for(int i = 0; i < srcStr->length; i++){
        destStr->ch[i] = srcStr->ch[i];
    }
    destStr->length = srcStr->length;
    return 1;

}
//判断字符串是否为空
int IsHeapStringEmpty(HString * str){
    if(str->length == 0 || !str->ch)
        return 1;
    return 0;
}












