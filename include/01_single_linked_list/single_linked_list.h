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
bool isEmptyLinkedList(LinkedList *list);
void destroyLinkedList(LinkedList *list);

#endif // ifndef 조건문의 끝을 나타냄
