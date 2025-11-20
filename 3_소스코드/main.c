#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 기본값 ±5 범위 랜덤 생성 함수
int rand_stat(int base) {
    return base + (rand() % 11 - 5);
}

int main() {
    srand(time(NULL));

    // 기본 종족값 (HP, ATK, SPD)
    int bulba_base[3] = {45, 49, 45};
    int char_base[3]  = {39, 52, 65};
    int squirt_base[3] = {44, 48, 43};
int a;
    // 실제 랜덤 능력치
    int Bulbasaur[3];
    int Charmander[3];
    int Squirtle[3];
    int* PokemonList[3] = { Bulbasaur, Charmander, Squirtle };

    // 기본값에 랜덤 적용
    for (int i = 0; i < 3; i++) {
        Bulbasaur[i]  = rand_stat(bulba_base[i]);
        Charmander[i] = rand_stat(char_base[i]);
        Squirtle[i]   = rand_stat(squirt_base[i]);
    }
    int enemyIndex = rand() % 3;  // 0~2 중 하나
	int* Enemy = PokemonList[enemyIndex];
	printf("%d", PokemonList[enemyIndex]);
    printf("포켓몬을 선택하세요(숫자를 쓰세요)\n1.이상해씨\n2.파이리\n3.꼬부기");
    scanf("%d", a); 

    // 출력
    printf("이상해씨 : HP=%d ATK=%d SPD=%d\n", Bulbasaur[0], Bulbasaur[1], Bulbasaur[2]);
    printf("파이리   : HP=%d ATK=%d SPD=%d\n", Charmander[0], Charmander[1], Charmander[2]);
    printf("꼬부기   : HP=%d ATK=%d SPD=%d\n", Squirtle[0], Squirtle[1], Squirtle[2]);

    return 0;
}
