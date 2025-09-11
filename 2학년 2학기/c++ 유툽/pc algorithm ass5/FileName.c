#include <stdio.h>
#include <stdlib.h>

// 노드 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 새로운 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 연결 리스트 출력
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("-");
        temp = temp->next;
    }
    printf("\n");
}

// 노드 삽입
Node* insert(Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

// k번째 노드 삭제
Node* deleteKthNode(Node* head, int k) {
    if (head == NULL) return NULL;
    Node* temp = head;

    // 첫 번째 노드를 삭제하는 경우
    if (k == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    // k번째 노드를 찾기
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // k번째 노드 삭제
    if (temp != NULL && temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }

    return head;
}

int main() {
    int initialData[] = { 22, 3, 45, 21, 34, 20, 75, 64, 56, 32 }; // 초기 데이터
    int n = sizeof(initialData) / sizeof(initialData[0]);
    Node* head = NULL;

    // 연결 리스트 생성
    for (int i = 0; i < n; i++) {
        head = insert(head, initialData[i]);
    }

    printf("초기 리스트: ");
    printList(head);

    // 사용자로부터 k 입력 받기
    int k;
    printf("k를 입력하세요 (1~10): ");
    scanf("%d", &k);

    if (k < 1 || k > 10) {
        printf("잘못된 k 값입니다. 1에서 10 사이의 값을 입력하세요.\n");
        return 1;
    }

    printf("\nk = %d\n", k);

    // k번째 노드 삭제
    head = deleteKthNode(head, k);

    // 결과 출력
    printf("삭제 후 리스트: ");
    printList(head);

    return 0;
}
