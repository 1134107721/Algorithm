#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "BinaryLinkedList.h"

void TestBinaryLinkedList();

int main()
{

    TestBinaryLinkedList();
    return 0;
}

void TestBinaryLinkedList(){
    BiNode * node = (BiNode *)malloc(sizeof(BiNode));
    CreateBinaryLinkedList(node);
    TraverseBinaryTree(node);
    free(node);
    node = NULL;

}
