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
// ʵ�ֲ���ͷ����ѭ������
typedef struct SingleList{
	Node* _head; //_head ��ʾ����������ͷ��㣬����һ����Ч���ݵ�λ��
}SingleList;
Node* createNode(Type data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}
void SingleListInit(SingleList* sl){
	// ������û����Ч�Ľ��
	sl->_head = NULL;
}
void SingleListPushBack(SingleList* sl, Type data){
	Node* node = createNode(data);
	if (sl->_head == NULL){
		sl->_head = node;
	}
	else{
		// �ҵ����һ������
		Node* last = sl->_head;
		while (last->_next){
			last = last->_next;
		}
		last->_next = node;
	}
	//// ����֮ǰ�����ȴ����½��
	//Node* node = createNode(data);

	//if (sl->_head == NULL){// �ж�ͷ����Ƿ�Ϊ��,ͷ���Ϊ�վͲ���ͷ���
	//	sl->_head = node;
	//}
	//else{// ͷ��㲻Ϊ�գ���Ҫ�ҵ����һ����㣬�������һ�����ĺ���
	//	Node* cur = sl->_head;
	//	while (cur->_next){
	//		cur = cur->_next;
	//	}
	//	cur->_next = node;
	//}

}
// ɾ�����������һ��Ԫ��
// �����һ��Ԫ�ص�ǰһ��Ԫ�ص�_next��NULL
void SingleListPopBack(SingleList* sl){
	// �ҵ����һ����㣬�����޸ı�ɾ������ǰ�����
	if (sl->_head){
		// �ҵ����һ����㣬�����Ĺ����У�����prev
		Node* prev = NULL; 
		Node* tail = sl->_head;
		while (tail->_next){
			prev = tail;
			tail = tail->_next;
		}
		// ���ɾ����Ϊͷ��㣬����������ֻ��һ�����
		// �������жϵȼ� if( prev == NULL )
		if (tail == sl->_head){
			sl->_head = NULL;
		}
		else{
			prev->_next = NULL;
		}
			free(tail);
	}
	//// �������Ϊ�գ�ֱ�ӷ���
	//if (sl->_head == NULL){
	//	return;
	//}
	//// ֻ��ͷ���
	//if (sl->_head->_next == NULL){
	//	sl->_head = NULL;
	//	return;
	//}
	////  ����һ��������������
	//Node* cur = sl->_head;
	//Node* prev=sl->_head;
	//while (cur->_next){
	//	prev = cur;
	//	cur = cur->_next;
	//}
	//prev->_next = NULL;
}
void SingleListPushFront(SingleList* sl, Type data){
	// ���ж��Ƿ�Ϊ�ձ�
	Node* node = createNode(data);
	if (sl->_head == NULL){ // ���ͷ���Ϊ�գ���ֻ�����ͷ��㼴��
		sl->_head = node;
	}
	else{// �����Ϊ�գ�����Ҫ�Ƚ�ͷ�����뱻����֮���ٲ��뵱ǰ�����ͷ���
		node->_next = sl->_head;
		sl->_head = node;
	}
}
void SingleListPopFront(SingleList* sl){
	//if (sl->_head){
	//	// �ȱ���ԭ���
	//	Node* cur = sl->_head;
	//	// ������
	//	sl->_head = cur->_next;
	//	//���ɾ��
	//	free(cur);
	//	cur = NULL;
	//}

	// �ж��Ƿ�Ϊ������
	if (sl->_head == NULL){
		return;
	}
	Node* cur = sl->_head;
	sl->_head = sl->_head->_next;
	free(cur);
	cur = NULL;
}
// ����λ�ò��룬��ǰ�����ڵ�ĺ���
void SingleListInsertAfter(Node* pos,Type data){
	if (NULL == pos){ // ��ǰ��㲻����
		return;
	}
	// ����һ�����
	Node* node = createNode(data);
	// ִ�в������
	node->_next = pos->_next;
	pos->_next = node;
}
// ɾ����ǰ�ڵ����һ���ڵ�
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

	
	//// ͷ�����
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
	//	printf("�޸�Ԫ��\n");
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