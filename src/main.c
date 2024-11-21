#include "single_linked_list.h"

void displayMenu(void) {
  printf("\n=== 단일 연결 리스트 프로그램 ===\n\n");
  printf("0. 프로그램 종료\n"); // 리스트 삭제 후 프로그램 종료
  printf("1. 리스트 시작 위치에 데이터 삽입\n");
  printf("2. 리스트 끝 위치에 데이터 삽입\n");
  printf("3. 지정 위치에 데이터 삽입\n");
  printf("4. 지정 위치의 데이터 삭제\n"); // 특정 노드를 제거하고 메모리 해제까지
  printf("5. 헤드 노드 제거\n"); // 메모리 해제까지 해야지
  printf("6. 테일 노드 제거\n"); // 메모리 해제까지 해야지
  printf("7. 데이터 검색\n"); // search (값을 조회하면 인덱스 반환(중복까지))
  printf("8. 전체 리스트 조회\n");
  printf("9. 리스트 삭제\n"); // 노드부터 지워주고 남은 빈 리스트 메모리 해제까지
  printf("10. 리스트 정보 확인\n"); // isEmpty, 노드 개수, 메모리 사용량(sizeof로 계산해서)
  printf("메뉴 선택 >> ");
}

int main(void) {
  LinkedList* list = createLinkedList();
  if (list == NULL) {
    puts("리스트 생성 실패");
    return EXIT_FAILURE;
  }

  int choice;
  DataType data;
  Node* node = NULL;
  Node* target = NULL;

  while(1) { // = while(true); 무한루프
    displayMenu();
    scanf("%d", &choice);

    switch (choice) {
      case 0:
        list_destroy(list);
        puts("프로그램을 종료합니다.");
        return EXIT_SUCCESS;
      case 1:
        scanf("%d", &data);
        list_insert_head(list, data);
        break;
      case 2:
        scanf("%d", &data);
        list_insert_tail(list, data);
        break;
      case 3:
        scanf("%d", &data);
        list_insert_position(node, data);
        break;
      case 4:
        list_remove_target_node(list, target);
        break;
      case 5:
        list_remove_head(list);
        break;
      case 6:
        list_remove_tail(list);
        break;
      case 7:
        list_search(list, data);
        break;
      case 8:
        list_print(list);
        break;
      case 9:
        list_destroy(list);
        break;
      case 10:
        list_info_print(list);
        break;
      default:
        puts("0 ~ 10 까지의 숫자를 입력하시오.");
        break;
    }
  }
}