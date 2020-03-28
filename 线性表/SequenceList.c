#include "SequenceList.h"
/*
 *  ��ʼ��˳���
 *  @param seqList      Ҫ��ʼ����˳���
 *  @param elemArray    ��ʼ��ʱҪ��ӵ�����Ԫ������
 *  @param length       ��ʼ��ʱҪ��ӵ�Ԫ�ظ���
 */
void InitList(SeqList * seqList, ElementType * elemArray, int length)
{
    seqList->length = 0;
    //�ǵ��ڳ�ʼ��˳���ʱ����˳���������
    for(int i = 0; i < length; i++)
    {
        InsertElement(seqList, i, elemArray[i]);
    }
}


/*
 *  ��˳�����index�±��λ�ô�����ĳ��Ԫ��
 *  @param seqList      Ҫ��ʼ����˳���
 *  @param index        Ҫ������±�
 *  @param element      Ҫ�����Ԫ��
 */
 void InsertElement(SeqList * seqList, int index, ElementType element)
 {
     for(int i = seqList->length - 1; i >= index; i--)
     {
          seqList->datas[i + 1] = seqList->datas[i];
     }
     //��Ҫ�����ֵ����index��Ԫ��
     seqList->datas[index] = element;
     //˳�����ܳ��ȼ�һ �ǳ�����©����������
     seqList->length++;
 }

ElementType * DeleteElement(SeqList * seqList, int index)
{
   //1.�ҵ�Ҫɾ����Ԫ�أ����������Ա㷵�أ��������ֵ���ǵ�ַ���Ǹ�����
   ElementType * delElement = (ElementType*)malloc(sizeof(ElementType)); //��һ�ײ�������дһ����ʱ�ʼ��� ��ʱ�ʼǾ�������
   //�������岢���ò��Һ���������Ҫɾ��Ԫ�ص�ָ��
   *delElement = *GetElement(seqList,index);

   //2.��ָ��λ��ɾ��������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
   for(int i = index; i < seqList->length-1; i++)
   {
       seqList->datas[i] = seqList->datas[i + 1];
   }
   //3.˳�����ܳ���-1
   seqList->length--;
    return delElement; // ����û�д� ���Ƿ��ص�ָ�루ָ�����ָ����ǿ��ַ���������뵱Ȼ����ΪӦ�÷���*delElement
    //ʹ����ϼǵ�free  ����ͻ��ڴ�й©
}
ElementType * GetElement(SeqList * seqList, int index)
{
    ElementType * element; //����Ҫ���ҵ�Ԫ�أ�����������Ϊ�˷���
    element = &seqList->datas[index];
   return element;
}

void PrintList(SeqList * seqList)
{
    for(int i = 0; i < seqList->length; i++)
    {
        printf("%d\t%s\n",seqList->datas[i].id,seqList->datas[i].name);
    }
}























