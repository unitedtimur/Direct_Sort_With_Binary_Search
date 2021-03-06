/*
*
*Created by UnitedTimur
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main() {

	printf("Enter the size of Array, please: ");

	unsigned int Size;
	scanf("%u", &Size);
	int *Array = new int[Size];

	printf("Enter 1 or 2.\n1 = Random Array.\n2 = You write Array\n");
	unsigned int Result = 0;
	scanf("%u", &Result);

	if (Result != 1 && Result != 2) {
		printf("ERROR #1. Try again ;(\n");
		system("pause");
		exit(1);
	}

	switch (Result) {
	case 1: {
		for (int i = 0; i < Size; i++) {
			Array[i] = rand() % 61;
		}
		break;
	}
	case 2: {
		for (int i = 0; i < Size; i++) {
			scanf("%d", &Array[i]);
		}
	}
	}

	for (int i = 0; i < Size; i++) {
		printf("[%d] ", Array[i]);
	}
	printf("\n");

	/*----SORTING----*/
	int X;
	int Left;
	int Right;
	int Middle;

	for (int i = 0; i < Size; i++) {
		if (Array[i - 1] > Array[i]) {
			X = Array[i];
			Left = 0;
			Right = i - 1;
			do {
				Middle = (Left + Right) / 2;
				if (Array[Middle] < X) {
					Left = Middle + 1;
				}
				else {
					Right = Middle - 1;
				}
			} while (Left <= Right);

			for (int j = i - 1; j >= Left; j--) {
				Array[j + 1] = Array[j];
			}
			Array[Left] = X;
		}
	}
	/*----END SORTING----*/

	for (int i = 0; i < Size; i++) {
		printf("[%d] ", Array[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
