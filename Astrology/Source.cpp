#include <stdio.h>
#include <locale.h>
#include <cstdlib>


typedef struct {
	char * name;
	char * zodiac;
	int bday[3];
}Znak;


/**
* Ввод одного элемента Znak
*
* @return Введённый Znak
*/
Znak input();

/**
* Вывод всех элементов массива
*
* @param Массив Znak
*/
void print_all(Znak arr[]);

/**
* Вывод рожденных в указанный месяц
*
* @param Массив Znak, номер месяца
*/
void search(Znak arr[], int m);


int main(void) {
	
	Znak book[8];

	setlocale(LC_CTYPE, "Rus");

	printf("Введите все элементы массива\n");
	for (int i = 0; i < 8; i++) {
		book[i] = input();
	}

	while (1) {
		int choice;
		printf("1. Вывод всех элементов\n2. Поиск по месяцу рождения\n3. Завершение работы\n");
		scanf_s("%d", &choice);
		switch (choice){
		case 1:
			print_all(book);
			break;
		case 2:
			int mounth;
			printf("Введите номер месяца рождения\n");
			scanf_s("%d", &mounth);
			while (mounth < 1 || mounth > 12) {
				printf("Ошибка ввода, попробуйте ещё раз\n");
				scanf_s("%d", &mounth);
			}
			search(book, mounth);
			break;
		case 3:
			system("pause");
			return 0;
			break;
		default:
			printf("Ошибка ввода, попробуйте ещё раз\n");
			break;
		}
	}
}

Znak input(){
	return Znak();
}

void print_all(Znak arr[]){
	printf("Все элементы\n");
}

void search(Znak arr[], int m){
	printf("Найденные элементы\n");
}