#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMBINATION_LENGTH 10

// 원소 구조체 정의
typedef struct {
    char name[3];    // 원소 이름 (2자 이하)
    char symbol;     // 원소 기호 (1자)
    int valence;     // 원소가 결합할 수 있는 최대 수
} Element;

// 원소 목록 초기화
Element elements[] = {
    {"H", 'H', 1},
    {"He", 'He', 0},
    {"Li", 'Li', 1},
    {"Be", 'Be', 2},
    {"B", 'B', 3},
    {"C", 'C', 4},
    {"N", 'N', 5},
    {"O", 'O', 6},
    {"F", 'F', 7},
    {"Ne", 'Ne', 0},
};

int num_elements = sizeof(elements) / sizeof(Element);

// 결합된 원소 목록 초기화
char combination[MAX_COMBINATION_LENGTH + 1] = "";
int combination_length = 0;

// 목표 원소 정의
char goal[] = "CO2";

// 결합된 원소 목록 출력
void print_combination() {
    printf("Combination: %s\n", combination);
}

// 원소 검색 함수
Element *find_element(char symbol) {
    for (int i = 0; i < num_elements; i++) {
        if (elements[i].symbol == symbol) {
            return &elements[i];
        }
    }
    return NULL;
}

// 결합 함수
bool combine(char symbol) {
    // 결합할 원소 검색
    Element *element = find_element(symbol);
    if (element == NULL) {
        printf("Invalid element: %c\n", symbol);
        return false;
    }

    // 결합 가능한지 확인
    if (combination_length + 1 > MAX_COMBINATION_LENGTH) {
        printf("Combination is too long.\n");
        return false;
    }
    if (element->valence <= strlen(combination)) {
        printf("Element %c cannot be combined.\n", symbol);
        return false;
    }

    // 결합
    combination[combination_length++] = element->symbol;
    combination[combination_length] = '\0';
    print_combination();
    return true;
}

// 게임 시작 함수
void start_game() {
    printf("Create %s!\n", goal);
    while (1){
        continue;
    }
}

int main() {
    start_game();
    return 0;
}