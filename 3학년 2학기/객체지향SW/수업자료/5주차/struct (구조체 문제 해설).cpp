#include <iostream>
#include <string>
#include <limits>
#include <cctype>

typedef unsigned int uint;

enum Status { Available, Borrowed, Reserved, Lost };

struct Book {
    uint id;
    std::string title;
    uint year;
    std::string author;
    Status status;
};

// ------------------ 유틸 ------------------
void clearLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const char* statusToString(Status s) {
    switch (s) {
        case Available: return "Available";
        case Borrowed:  return "Borrowed";
        case Reserved:  return "Reserved";
        case Lost:      return "Lost";
    }
    return "Unknown";
}

Status statusFromString(const std::string& s) {
    std::string lower;
    lower.reserve(s.size());
    for (char c : s) lower.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));

    if (lower == "available") return Available;
    if (lower == "borrowed")  return Borrowed;
    if (lower == "reserved")  return Reserved;
    if (lower == "lost")      return Lost;
    return Available; // 기본값
}

// ------------------ 핵심 로직 ------------------
constexpr int CAPACITY = 100;

int findIndexById(Book* books[], int count, uint id) {
    for (int i = 0; i < count; ++i) {
        if (books[i] && books[i]->id == id) return i;
    }
    return -1;
}

void printBook(const Book* b) {
    std::cout << "ID: " << b->id << "\n";
    std::cout << "TITLE: " << b->title << "\n";
    std::cout << "YEAR: " << b->year << "\n";
    std::cout << "AUTHOR: " << b->author << "\n";
    std::cout << "STATUS: " << statusToString(b->status) << "\n";
}

void addBook(Book* books[], int& count) {
    if (count >= CAPACITY) {
        std::cout << "저장 공간이 가득 찼습니다.\n";
        return;
    }

    Book* b = new Book{};
    std::cout << "ID: ";
    std::cin >> b->id;
    clearLine();

    std::cout << "TITLE: ";
    std::getline(std::cin, b->title);

    std::cout << "YEAR: ";
    std::cin >> b->year;
    clearLine();

    std::cout << "AUTHOR: ";
    std::getline(std::cin, b->author);

    std::cout << "STATUS: ";
    std::string buf;
    std::getline(std::cin, buf);
    b->status = statusFromString(buf);

    books[count++] = b;
    std::cout << "저장이 완료되었습니다.\n";
}

void printAll(Book* books[], int count) {
    if (count == 0) {
        std::cout << "저장된 Book이 없습니다.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        printBook(books[i]);
    }
}

void deleteById(Book* books[], int& count) {
    std::cout << "삭제를 원하는 Book의 ID를 입력하시오: ";
    uint key; std::cin >> key; clearLine();

    int idx = findIndexById(books, count, key);
    if (idx < 0) {
        std::cout << "해당 ID가 없습니다.\n";
        return;
    }

    std::cout << "아래 Book이 삭제되었습니다.\n";
    std::cout << "ID: " << books[idx]->id << "\n";
    std::cout << "TITLE: " << books[idx]->title << "\n";

    delete books[idx]; // 메모리 해제
    for (int i = idx + 1; i < count; ++i) books[i - 1] = books[i];
    --count;
}

// ------------------ main ------------------
int main() {
    Book* books[CAPACITY] = { nullptr };
    int count = 0;

    while (true) {
        std::cout << "모드를 입력하시오: (0 - 추가, 1 - 출력, 2 - 삭제, 99 - 종료): ";
        int mode; 
        if (!(std::cin >> mode)) break;
        clearLine();

        if (mode == 0) {
            addBook(books, count);
        } else if (mode == 1) {
            printAll(books, count);
        } else if (mode == 2) {
            deleteById(books, count);
        } else if (mode == 99) {
            std::cout << "프로그램을 종료합니다.\n";
            break;
        } else {
            std::cout << "올바르지 않은 입력입니다.\n";
        }
    }

    for (int i = 0; i < count; ++i) delete books[i];
    return 0;
}
