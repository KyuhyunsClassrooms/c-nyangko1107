#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    포켓몬 배틀 게임
    - 이상해씨 / 파이리 / 꼬부기 중 하나 선택
    - 컴퓨터도 랜덤 선택
    - 상성에 따라 승패 결정
*/

/* 함수 선언 */
int generate_random();
void start_game();

int main() {
    int play_again = 1;

    printf("============================\n");
    printf("     포켓몬 배틀 게임 v1.0     \n");
    printf("============================\n\n");

    while (play_again == 1) {
        start_game();

        printf("\n다시 하시겠습니까? (1: 예, 0: 아니오): ");
        scanf("%d", &play_again);
        while (getchar() != '\n');  // 입력 버퍼 비우기
        printf("\n");
    }

    printf("게임을 종료합니다. 감사합니다!\n");
    return 0;
}

/* 0~2 사이의 랜덤 숫자 생성 (포켓몬 선택용) */
int generate_random() {
    srand(time(NULL));  
    return rand() % 3;  // 0~2
}

/* 포켓몬 이름 매핑 */
const char* get_pokemon_name(int num) {
    switch (num) {
        case 0: return "이상해씨";  // 풀
        case 1: return "파이리";    // 불
        case 2: return "꼬부기";    // 물
        default: return "???";
    }
}

/* 승패 판정:  
   0: 이상해씨(풀), 1: 파이리(불), 2: 꼬부기(물)
   규칙:
   - 풀 → 물 승
   - 물 → 불 승
   - 불 → 풀 승
*/
int check_result(int user, int com) {
    if (user == com) return 0;  // 비김

    if ((user == 0 && com == 2) ||
        (user == 2 && com == 1) ||
        (user == 1 && com == 0)) {
        return 1;               // 사용자 승
    }

    return -1;                  // 사용자 패
}

/* 게임 시작 함수 */
void start_game() {
    int user, com, result;

    printf("=== 포켓몬 배틀 시작! ===\n");
    printf("포켓몬을 선택하세요!\n");
    printf("0: 이상해씨 (풀)\n1: 파이리 (불)\n2: 꼬부기 (물)\n\n");

    printf("당신의 선택: ");
    scanf("%d", &user);
    while (getchar() != '\n');  // 입력 버퍼 비우기

    if (user < 0 || user > 2) {
        printf("??  0~2 사이의 숫자를 입력하세요!\n");
        return;
    }

    com = generate_random();

    printf("\n당신의 포켓몬: %s\n", get_pokemon_name(user));
    printf("상대 포켓몬: %s\n\n", get_pokemon_name(com));

    result = check_result(user, com);

    if (result == 0) {
        printf("?? 비겼습니다!\n");
    } else if (result == 1) {
        printf("?? 당신의 승리입니다!\n");
    } else {
        printf("?? 패배했습니다...\n");
    }
}
