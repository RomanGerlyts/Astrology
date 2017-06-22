#include <stdio.h>
#include <locale.h>
#include <cstdlib>


typedef struct {
	char * name;
	char * zodiac;
	int bday[3];
}Znak;


/**
* ���� ������ �������� Znak
*
* @return �������� Znak
*/
Znak input();

/**
* ����� ���� ��������� �������
*
* @param ������ Znak
*/
void print_all(Znak arr[]);

/**
* ����� ��������� � ��������� �����
*
* @param ������ Znak, ����� ������
*/
void search(Znak arr[], int m);


int main(void) {
	
	Znak book[8];

	setlocale(LC_CTYPE, "Rus");

	printf("������� ��� �������� �������\n");
	for (int i = 0; i < 8; i++) {
		book[i] = input();
	}

	while (1) {
		int choice;
		printf("1. ����� ���� ���������\n2. ����� �� ������ ��������\n3. ���������� ������\n");
		scanf_s("%d", &choice);
		switch (choice){
		case 1:
			print_all(book);
			break;
		case 2:
			int mounth;
			printf("������� ����� ������ ��������\n");
			scanf_s("%d", &mounth);
			while (mounth < 1 || mounth > 12) {
				printf("������ �����, ���������� ��� ���\n");
				scanf_s("%d", &mounth);
			}
			search(book, mounth);
			break;
		case 3:
			system("pause");
			return 0;
			break;
		default:
			printf("������ �����, ���������� ��� ���\n");
			break;
		}
	}
}

Znak input(){
	return Znak();
}

void print_all(Znak arr[]){
	printf("��� ��������\n");
}

void search(Znak arr[], int m){
	printf("��������� ��������\n");
}