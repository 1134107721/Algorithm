//˳���ַ��� Demo
//��������Ĵ���ʵ�� strlen() strcat() strcpy()��Щ����
#ifndef SEQSTRING_H_INCLUDED
#define SEQSTRING_H_INCLUDED


/*  ���ַ���������������ṹ���Ƕ����ģ�MAXSIZE����ȱ�����˷ѿռ�
typedef struct{     //˳��
    char ch[MAX_SIZE];  //�洢�ַ�������
    int length;     //���ĵ�ǰ����
}SString;
*/
typedef struct{     //�ѽṹ�洢
    char * ch;      //����Ƿǿմ�����ô����ָ�����ȷ����ڴ棬����ch��ָ��null
    int length;
}HString;
//��ʼ����
void InitHeapString(HString * str);
//Ϊ��str��ֵ  ֵΪ�ַ�������chars
int AssignHeapString(HString * str, char* chars);
//��ӡ���ַ���
void PrintHeapString(HString * str);


#endif // SEQSTRING_H_INCLUDED
