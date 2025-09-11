/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 200
#define MAX_VALUE 99
#define INSERTION_SORT_THRESHOLD 13

int pass_counter = 0; // Pass 카운터

// 배열 출력 함수
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0) printf("\n");
    }
    printf("\n");
}

// 배열 초기화 함수
void generate_random_array(int arr[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_value + 1);
    }
}

// 삽입 정렬 함수
void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Median of Three 함수
int median_of_three(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) {
        int temp = arr[left];
        arr[left] = arr[mid];
        arr[mid] = temp;
    }
    if (arr[left] > arr[right]) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    if (arr[mid] > arr[right]) {
        int temp = arr[mid];
        arr[mid] = arr[right];
        arr[right] = temp;
    }
    return arr[mid];
}

// Quick 정렬 함수
void quick_sort(int arr[], int left, int right, int total_size) {
    if (right - left <= INSERTION_SORT_THRESHOLD) {
        insertion_sort(arr, left, right);
        return;
    }

    int pivot = median_of_three(arr, left, right);
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    printf("\nPass %d (pivot=%d):\n", ++pass_counter, pivot);
    print_array(arr, total_size);

    if (left < j) quick_sort(arr, left, j, total_size);
    if (i < right) quick_sort(arr, i, right, total_size);
}

// Bubble 정렬 함수
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 고해상도 시간 측정 함수
double get_high_resolution_time() {
    LARGE_INTEGER frequency, counter;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / frequency.QuadPart;
}

int main() {
    int arr[SIZE], copy[SIZE];
    srand((unsigned)time(NULL));

    // 배열 생성
    generate_random_array(arr, SIZE, MAX_VALUE);

    printf("원시 배열:\n");
    print_array(arr, SIZE);

    // Quick 정렬
    for (int i = 0; i < SIZE; i++) copy[i] = arr[i];
    double start = get_high_resolution_time();
    quick_sort(copy, 0, SIZE - 1, SIZE);
    double end = get_high_resolution_time();

    printf("\nQuick 정렬 최종 결과:\n");
    print_array(copy, SIZE);
    printf("Quick 정렬 실행 시간: %.6f초\n", end - start);

    // Bubble 정렬
    for (int i = 0; i < SIZE; i++) copy[i] = arr[i];
    start = get_high_resolution_time();
    bubble_sort(copy, SIZE);
    end = get_high_resolution_time();

    printf("\nBubble 정렬 최종 결과:\n");
    print_array(copy, SIZE);
    printf("Bubble 정렬 실행 시간: %.6f초\n", end - start);

    return 0;
}

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 200
#define MAX_VALUE 99
#define INSERTION_SORT_THRESHOLD 13

// 배열 출력 함수
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0) printf("\n");
    }
    printf("\n");
}

// 배열 초기화 함수
void generate_random_array(int arr[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_value + 1);
    }
}

// 삽입 정렬 함수
void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Median of Three 함수
int median_of_three(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) {
        int temp = arr[left];
        arr[left] = arr[mid];
        arr[mid] = temp;
    }
    if (arr[left] > arr[right]) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    if (arr[mid] > arr[right]) {
        int temp = arr[mid];
        arr[mid] = arr[right];
        arr[right] = temp;
    }
    return arr[mid];
}

// Quick 정렬 함수
void quick_sort(int arr[], int left, int right) {
    if (right - left <= INSERTION_SORT_THRESHOLD) {
        insertion_sort(arr, left, right);
        return;
    }

    int pivot = median_of_three(arr, left, right);
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

// Bubble 정렬 함수
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 고해상도 시간 측정 함수
double get_high_resolution_time() {
    LARGE_INTEGER frequency, counter;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / frequency.QuadPart;
}

int main() {
    int arr[SIZE], copy[SIZE];
    srand((unsigned)time(NULL));

    // 배열 생성
    generate_random_array(arr, SIZE, MAX_VALUE);

    printf("원시 배열:\n");
    print_array(arr, SIZE);

    // Quick 정렬
    for (int i = 0; i < SIZE; i++) copy[i] = arr[i];
    double start = get_high_resolution_time();
    quick_sort(copy, 0, SIZE - 1);
    double end = get_high_resolution_time();

    printf("\nQuick 정렬 최종 결과:\n");
    print_array(copy, SIZE);
    printf("Quick 정렬 실행 시간: %.6f초\n", end - start);

    // Bubble 정렬
    for (int i = 0; i < SIZE; i++) copy[i] = arr[i];
    start = get_high_resolution_time();
    bubble_sort(copy, SIZE);
    end = get_high_resolution_time();

    printf("\nBubble 정렬 최종 결과:\n");
    print_array(copy, SIZE);
    printf("Bubble 정렬 실행 시간: %.6f초\n", end - start);

    return 0;
}
