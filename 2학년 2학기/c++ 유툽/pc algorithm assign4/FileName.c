#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10 // 임의로 최대 노드 수를 10개로 설정

// 이진 트리 노드 정의
typedef struct Node {
    int data;
    struct Node* left, * right;
} Node;

// 새로운 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에 노드 삽입 함수
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// 트리의 높이 계산 함수
int treeHeight(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 중위 순회 함수
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 전위 순회 함수
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회 함수
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n, numbers[MAX_NODES];
    Node* root = NULL;

    srand(time(0)); // 난수 시드 설정

    // 난수를 이용하여 n개의 서로 다른 정수 생성
    printf("몇 개의 노드를 생성하시겠습니까? (최대 %d): ", MAX_NODES);
    scanf_s("%d", &n);
   {
        printf("최대 노드 수는 %d개입니다.\n", MAX_NODES);
        return 1;
    }

    printf("원시 배열 내용: ");
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100; // 0 ~ 99 사이의 정수 생성
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                i--; // 중복값이면 다시 생성
                break;
            }
        }
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 이진 탐색 트리에 삽입
    for (int i = 0; i < n; i++) {
        root = insert(root, numbers[i]);
    }

    // 트리의 높이 계산
    printf("트리의 높이: %d\n", treeHeight(root));

    // 순회 결과 출력
    printf("중위 순회: ");
    inorder(root);
    printf("\n");

    printf("전위 순회: ");
    preorder(root);
    printf("\n");

    printf("후위 순회: ");
    postorder(root);
    printf("\n");

    return 0;
}
