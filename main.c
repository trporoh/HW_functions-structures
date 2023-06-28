#include <stdio.h>
#include <string.h>

struct member_list {
	char name[20];
	char surname[20];
	char number[20];
};

int prog = 1;

void show(struct member_list* list, int size) {

	for (int i = 0; i < size;i++) {

		printf("\n%s \n%s \n%s \n\n", list[i].name, list[i].surname, list[i].number);
	}
}

void add(struct member_list* list, int size) {


	printf("Enter the name: \n");
	fgets(list[size].name, sizeof(list[size].name), stdin);
	list[size].name[strcspn(list[size].name, "\n")] = '\0';

	printf("Enter the surname: \n");
	fgets(list[size].surname, sizeof(list[size].surname), stdin);
	list[size].surname[strcspn(list[size].surname, "\n")] = '\0';


	printf("Enter the number: \n");
	fgets(list[size].number, sizeof(list[size].number), stdin);
	list[size].number[strcspn(list[size].number, "\n")] = '\0';

}

int search(struct member_list* list, char* number, int size) {

	for (int i = 0; i < size; i++) {
	        if (strcmp(list[i].number, number) == 0) {
				printf("Contact found:\n");
				printf("%s\n", list[i].name);
				printf("%s\n", list[i].surname);
				printf("%s\n", list[i].number);
				return i;
        }
	}
	printf("\nthere is no such number\n");
	return -1;
}

void execute(struct member_list* list, int index, int size) {

	for (index; index < size; index++) {
		list[index] = list[index + 1];
	}
	for (int i = 0; i < 20; i++) {

		list[size].name[i] = 0;
		list[size].surname[i] = 0;
		list[size].number[i] = 0;
	}
}


int main() {

	struct member_list list[100];
	char number;
	char phone_number[20];
	int del;
	int size = 0;
	int result_of_search;

	do {

		printf("press 1 for show\npress 2 for add\npress 3 for search or delete\npress 4 for exit\n");
		number = getchar();
        getchar();

		switch (number) {

		case '1':

			show(list, size);
			break;

		case '2':

			add(list, size);
			system("clear");
			size++;
			break;

		case '3':

			printf("enter the phone number:\n");
			fgets(phone_number, 19, stdin);
			phone_number[strcspn(phone_number, "\n")] = '\0';

			result_of_search = search(&list, phone_number, size);
			printf("delete?\n");
			scanf("%d", &del);
			getchar();

			if (del && phone_number == -1) {

				execute(&list, result_of_search, size);
				size--;

			}
			break;
		case '4':
			prog = 0;
		}

	} while (prog);
	return 0;
}

