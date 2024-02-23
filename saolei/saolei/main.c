#include "saolei.h"

int main() {
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		getchar();
		switch (input) {
		case 1:game(); break;
		case 0:printf("Exit,See you next time\n"); break;
		default:printf("ERROR£¬RESELECT->:"); break;
		}
		system("CLS");
	} while (input);
	return 0;
}