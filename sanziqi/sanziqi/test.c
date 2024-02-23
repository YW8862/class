#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


int main() {
	int input = 0;
	do {
		menu();
		printf("Select >:");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ERROR!Rselect please!>:\n");
		}
	} while (input);
}