#include <stdio.h>
#include <cstdlib>
#define ARR_SIZE 2
#define STR_SIZE 50

typedef struct {
	char name[STR_SIZE + 1];
	char zodiac[STR_SIZE + 1];
	int bday[3];
}Znak;

/**
* Input one Znak item
*
* @return Inputted Znak element
*/
void input(Znak arr[]);

/**
* Print all array items
*
* @param Znak array
*/
void print_all(Znak arr[]);

/**
* Print people, who born in specified month
*
* @param Znak array, month number
*/
void search(Znak arr[], int m);



int main(void) {
	Znak book[ARR_SIZE];
	printf("Input all array items\n");
	input(book);
	while (1) {
		int choice;
		printf("1. Print all\n2. Search by month\n3. Shut down\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			print_all(book);
			break;
		case 2:
			int mounth;
			printf("Input month of birth\n");
			scanf_s("%d", &mounth);
			while (mounth < 1 || mounth > 12) {
				printf("Error, try again\n");
				scanf_s("%d", &mounth);
			}
			search(book, mounth);
			break;
		case 3:
			system("pause");
			return 0;
			break;
		default:
			printf("Error, try again\n");
			break;
		}
	}
}


void input(Znak arr[]) {
	for (int i = 0; i < ARR_SIZE; i++) {
		fflush(stdin);
		printf("Enter name: ");
		scanf("%s", arr[i].name);
		printf("Enter zodiac: ");
		scanf("%s", arr[i].zodiac);
		printf("Enter birth day in dd.mm.yyyy format: ");
		scanf("%d.%d.%d", &arr[i].bday[0], &arr[i].bday[1], &arr[i].bday[2]);
		fflush(stdin);
	}
}

void print_all(Znak arr[]) {
	printf("All items...\n");
	for (int i = 0; i < ARR_SIZE; i++) {
		puts(arr[i].name);
		puts(arr[i].zodiac);
		printf("%d.%d.%d\n", arr[i].bday[0], arr[i].bday[1], arr[i].bday[2]);
	}
}

void search(Znak arr[], int m) {
	int kol = 0;
	printf("Items found...\n");
	for (int i = 0; i < ARR_SIZE; i++) {
		if (arr[i].bday[1] == m) {
			if (m > 9) {
				printf("%s\n", arr[i].name);
				printf("%s\n", arr[i].zodiac);
				printf("%d.%d.%d\n", arr[i].bday[0], arr[i].bday[1], arr[i].bday[2]);
				kol++;
			}
			else {
				printf("%s\n", arr[i].name);
				printf("%s\n", arr[i].zodiac);
				printf("%d.0%d.%d\n", arr[i].bday[0], arr[i].bday[1], arr[i].bday[2]);
				kol++;
			}
		}
	}
	if (kol == 0) {
		printf("Not found\n");
	}
}