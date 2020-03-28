#include "SeqString.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//��ʼ����
void InitHeapString(HString * str){
    str->ch = NULL;
    str->length = 0;
}
//Ϊ��str��ֵ  ֵΪ�ַ�������chars
int AssignHeapString(HString * str, char* chars){
    int len = strlen(chars);
    if(!len)    //���chars�ǿմ�����ô����-1.����ʧ��
        return -1;
    InitHeapString(str);
    str->ch = (char*)malloc(len * sizeof(char));     //Ϊstr�����ch�����ڴ�ռ� ԭ����chҲ��char*���͵�
    for(int i = 0; i < len; i++){
        str->ch[i] = chars[i];
    }
    str->length = len;
    return 1;   //���ȥ�˷���1 ����ɹ�
}
//��ӡ���ַ���
void PrintHeapString(HString * str){
    for(int i = 0; i < str->length; i++)
        printf("%c", str->ch[i]);
}
//����srcstr�����ݸ��Ƶ�deststr����
int StrCpyHeapString(HString * destStr, HString * srcStr){
    InitHeapString(destStr);
    if(IsHeapStringEmpty(srcStr)){
        printf("Ҫ���Ƶ��ַ�������Ϊ��");
        return 0;
    }
    destStr->ch = (char*)malloc(sizeof(char) * srcStr->length);
    for(int i = 0; i < srcStr->length; i++){
        destStr->ch[i] = srcStr->ch[i];
    }
    destStr->length = srcStr->length;
    return 1;

}
//�ж��ַ����Ƿ�Ϊ��
int IsHeapStringEmpty(HString * str){
    if(str->length == 0 || !str->ch)
        return 1;
    return 0;
}












