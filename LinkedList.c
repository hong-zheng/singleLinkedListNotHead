#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef int  Type;
typedef struct Node{
	struct Node* _next;
	Type _data;
}Node;
// 实现不带头单向循环链表
typedef struct SingleList{
	Node* _head; //_head 表示链表真正的头结点，即第一个有效数据的位置
}SingleList;
Node* createNode(Type data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}
void SingleListInit(SingleList* sl){
	// 空链表，没有有效的结点
	sl->_head = NULL;
}
void SingleListPushBack(SingleList* sl, Type data){
	Node* node = createNode(data);
	if (sl->_head == NULL){
		sl->_head = node;
	}
	else{
		// 找到最后一个数据
		Node* last = sl->_head;
		while (last->_next){
			last = last->_next;
		}
		last->_next = node;
	}
	//// 插入之前都得先创建新结点
	//Node* node = createNode(data);

	//if (sl->_head == NULL){// 判断头结点是否为空,头结点为空就插入头结点
	//	sl->_head = node;
	//}
	//else{// 头结点不为空，就要找到最后一个结点，插于最后一个结点的后面
	//	Node* cur = sl->_head;
	//	while (cur->_next){
	//		cur = cur->_next;
	//	}
	//	cur->_next = node;
	//}

}
// 删除单链表最后一个元素
// 将最后一个元素的前一个元素的_next置NULL
void SingleListPopBack(SingleList* sl){
	// 找到最后一个结点，并且修改被删除结点的前驱结点
	if (sl->_head){
		// 找到最后一个结点，遍历的过程中，更新prev
		Node* prev = NULL; 
		Node* tail = sl->_head;
		while (tail->_next){
			prev = tail;
			tail = tail->_next;
		}
		// 如果删除的为头结点，或者链表中只有一个结点
		// 和下面判断等价 if( prev == NULL )
		if (tail == sl->_head){
			sl->_head = NULL;
		}
		else{
			prev->_next = NULL;
		}
			free(tail);
	}
	//// 如果链表为空，直接返回
	//if (sl->_head == NULL){
	//	return;
	//}
	//// 只有头结点
	//if (sl->_head->_next == NULL){
	//	sl->_head = NULL;
	//	return;
	//}
	////  多余一个结点的正常情形
	//Node* cur = sl->_head;
	//Node* prev=sl->_head;
	//while (cur->_next){
	//	prev = cur;
	//	cur = cur->_next;
	//}
	//prev->_next = NULL;
}
void SingleListPushFront(SingleList* sl, Type data){
	// 先判断是否为空表
	Node* node = createNode(data);
	if (sl->_head == NULL){ // 如果头结点为空，则只需插入头结点即可
		sl->_head = node;
	}
	else{// 如果不为空，则需要先将头结点插入被插结点之后，再插入当前结点于头结点
		node->_next = sl->_head;
		sl->_head = node;
	}
}
void SingleListPopFront(SingleList* sl){
	//if (sl->_head){
	//	// 先保留原结点
	//	Node* cur = sl->_head;
	//	// 再链接
	//	sl->_head = cur->_next;
	//	//最后删除
	//	free(cur);
	//	cur = NULL;
	//}

	// 判断是否为空链表
	if (sl->_head == NULL){
		return;
	}
	Node* cur = sl->_head;
	sl->_head = sl->_head->_next;
	free(cur);
	cur = NULL;
}
// 任意位置插入，当前给定节点的后面
void SingleListInsertAfter(Node* pos,Type data){
	if (NULL == pos){ // 当前结点不存在
		return;
	}
	// 创建一个结点
	Node* node = createNode(data);
	// 执行插入操作
	node->_next = pos->_next;
	pos->_next = node;
}
// 删除当前节点的下一个节点
void SingleListEraseAfter(Node* pos){
	if (NULL == pos){
		return;
	}
	if (pos->_next){
		pos->_next = pos->_next->_next;
	}
	else{
		pos->_next = NULL;
	}
}
Node* find(SingleList* sl,Type data){
	if (sl->_head == NULL){
		return NULL;
	}
	Node* cur = sl->_head;
	while (cur){
		if (data == cur->_data){
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void SingleListDestory(SingleList* sl){
	if (sl->_head == NULL){
		return;
	}
	Node* cur = sl->_head;
	while (cur){
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}
void SingleListPrint(SingleList* sl){
	Node* cur = sl->_head;
	while(cur){
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void test(){
	SingleList sl;
	SingleListInit(&sl);

	SingleListPushBack(&sl, 1);
	SingleListPushBack(&sl, 2);
	SingleListPushBack(&sl, 3);
	SingleListPushBack(&sl, 4);
	SingleListPrint(&sl);
	SingleListPopBack(&sl);
	SingleListPopBack(&sl);

	SingleListPrint(&sl);

	
	//// 头插测试
	//SingleListPushFront(&sl, 7);
	//SingleListPushFront(&sl, 6);
	//SingleListPushFront(&sl, 5);

	//SingleListPushFront(&sl, 1);
	//SingleListPrint(&sl);

	//SingleListPopFront(&sl);
	//SingleListPrint(&sl);

	//SingleListPopFront(&sl);
	//SingleListPrint(&sl);
	//SingleListInsertAfter((&sl)->_head,12);
	//SingleListPrint(&sl);
	//SingleListEraseAfter((&sl)->_head->_next);
	//SingleListPrint(&sl);
	//SingleListEraseAfter((&sl)->_head);
	//SingleListPrint(&sl);
	//Node* cur = find(&sl, 7);
	//if (cur){
	//	printf("%p\n", cur);
	//	printf("%d\n", cur->_data);
	//}
	//else{
	//	printf("无该元素\n");
	//}
	//SingleListDestory(&sl);
	//SingleListPushBack(&sl, 1);
	//SingleListPushBack(&sl, 2);
	//SingleListPrint(&sl);
	//SingleListPopBack(&sl);
	//SingleListPrint(&sl);
	//SingleListPopBack(&sl);
	//SingleListPrint(&sl);
}
int main(){
	test();
	system("pause");
	return 0;
}