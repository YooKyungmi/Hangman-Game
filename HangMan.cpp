#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
int check(char s[], char a[], char ch);
int main() {
	char solution[10][100] = { "meet at midnight",
								"nice to meet you",
								"Hello world",
								"programing in C",
								"time is running out",
								"You raise me up",
								"Busan National University",
								"made in Korea",
								"World Wide Web",
								"no pain no gain" };
	char ch= ' ', ans[100];
	srand((unsigned int)time(NULL));

	while (ch!='.') {
		char* sol = solution[rand() % 10];
		strcpy(ans, sol);

		int len_str = strlen(ans);  // ans값 숨기기
		for (int i = 0; i < len_str; i++) {
			if (ans[i] != ' ')
				ans[i] = '_';
		}
		printf("------------ HANGMAN GAME ------------\n\n");
		printf("        도전 횟수는 10번 입니다 \n");
		printf("     문자는 소문자로 입력해주세요\n");
		printf("   '.'을 입력하면 게임이 종료됩니다\n");
		printf(" 한 문자씩 입력해 문자열을 맞춰보세요\n");
		
		for (int i = 1; i < 11; i++) {
			printf("\n--------------------------------------");
			printf("\n\n< %d회 도전 >\n", i);
			printf("문자열: %s \n", ans);
			printf("글자를 추측하시오: ");
			ch = getchar();
			if (ch == '.') break;
			if (check(sol, ans, ch) == 1)
				break;
			while (getchar() != '\n') {};  // getchar 버퍼 비우기
		}
		if (check(sol, ans, ch) != 1 && ch != '.') {
			printf("\n문자열은 %s입니다!\n\n",sol);
		}
	}
	printf("\n게임이 종료되었습니다!\n");
	
	return 0;
}

int check(char s[], char a[], char ch) {
	int i;
	for (i = 0; s[i] != NULL; i++) {
		if (s[i] == ch || s[i] == ch-32)
			a[i] = s[i];
	}
	if (strcmp(s, a) == 0) return 1; // 정답과 일치하는지를 검사
	else return 0;
}