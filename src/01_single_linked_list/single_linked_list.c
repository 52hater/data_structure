#include "single_linked_list.h"

LinkedList* createLinkedList(void) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        puts("리스트 생성 실패");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

Node* node_create(DataType data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        puts("노드 생성 실패");
        return NULL;
    }
    new_node->data = data; // 받아온 데이터로 초기화
    new_node->next = NULL;
    return new_node;
}

int list_insert_head(LinkedList* list, DataType data) {
    Node* new_node = node_create(data);
    if (new_node == NULL) {
        return 0;
    }
    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return 1;
}

int list_insert_tail(LinkedList* list, DataType data) {
    Node* new_node = node_create(data);
    if (new_node == NULL) {
        return 0;
    }
    new_node->next = NULL;

    // 리스트가 비었으면
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        // 리스트가 안비었으면
        Node* current = list->head; // 헤드부터
        while (current->next != NULL) { // current의 next가 없을때까지
            current = current->next; // 훑고
        }
        current->next = new_node; // 마지막 노드 뒤에 새 노드를 붙여
    }
    list->size++;
    return 1;
}

int list_remove_head(LinkedList* list) {
    if (list->head == NULL) {
        return 0;
    } else {
        Node* temp = list->head; // 원래 헤드 임시저장
        list->head = list->head->next;
        free(temp); // 원래 헤드 메모리 해제
        list->size--;
    }
    return 1;
}

int list_remove_tail(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }

    // 노드가 하나일 경우
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return 1;
    }

    // 노드가 여러 개일 경우
    Node* current = list->head;
    Node* prev = list->head; // NULL로 초기화 하면 while문이 돌아가지 않으면 포인터 자체가 NULL이 되어버림

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
    list->size--;

    return 1;
}

// 지정 위치에 데이터 삽입
int list_insert_position(LinkedList *list, DataType data, DataType position) {
// 유효성검사 > 리스트가 있는지 > 포지션범위가 >= 면 안되지(조건거는방법두가지 )
}