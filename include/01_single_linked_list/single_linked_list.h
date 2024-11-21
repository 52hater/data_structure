// 헤더 가드
#ifndef SINGLE_LINKED_LIST_H // 만약 SINGLE_LINKED_LIST_H 가 정의되지 않았다면 (if not defined)
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 데이터 타입 정의
typedef int DataType;

// 노드 구조체 정의
typedef struct Node {
  DataType data;
  struct Node *next;
} Node;

// 리스트 관리 위한 구조체
typedef struct LinkedList {
  Node *head;
  size_t size;
} LinkedList;

// 함수 원형 선언
LinkedList *createLinkedList();
Node* node_create(DataType data);
// void node_delete(Node *node);
int list_insert_head(LinkedList *list, DataType data);
int list_insert_tail(LinkedList *list, DataType data);
int list_remove_head(LinkedList *list);
int list_remove_tail(LinkedList *list);
int list_insert_position(Node* node, DataType data);
int list_remove_target_node(LinkedList *list, Node* target);
int list_destroy(LinkedList *list);
int list_search(const LinkedList *list, DataType data);
void list_print(const LinkedList *list);
void list_info_print(const LinkedList *list);


#endif
