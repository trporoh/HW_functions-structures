#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct member_list {
	char name[20];
	char surname[20];
	char number[20];
	struct member_list* next;
};

int prog = 1;

void show(struct member_list* list) {

	struct member_list* ptr = list;
	while(ptr){
		printf("\n%s \n%s \n%s \n\n", ptr->name, ptr->surname, ptr->number);
		ptr = ptr->next;
	}
}

void add(struct member_list** list) {

	struct member_list* ptr = malloc(sizeof(struct member_list));

	printf("Enter the name: \n");
	fgets(ptr->name, sizeof(ptr->name), stdin);
	ptr->name[strcspn(ptr->name, "\n")] = '\0';

	printf("Enter the surname: \n");
	fgets(ptr->surname, sizeof(ptr->surname), stdin);
	ptr->surname[strcspn(ptr->surname, "\n")] = '\0';


	printf("Enter the number: \n");
	fgets(ptr->number, sizeof(ptr->number), stdin);
	ptr->number[strcspn(ptr->number, "\n")] = '\0';
	

	ptr->next = *list;
	*list = ptr;
}

struct member_list* search(struct member_list* list, char* number) {

	struct member_list* prev = list;
	struct member_list* ptr = list;

	while(ptr){
	    if (strcmp(ptr->number, number) == 0) {
			printf("Contact found:\n");
			printf("%s\n", ptr->name);
			printf("%s\n", ptr->surname);
			printf("%s\n", ptr->number);
			return prev;
		}
		prev = ptr;
		ptr = ptr->next;
	}

	printf("\nthere is no such number\n");
	return NULL;

}

void execute(struct member_list* del) {

	struct member_list* ptr = del->next;

	del->next = ptr->next;
	ptr->next = NULL;
	free(ptr);

}


int main() {

	struct member_list* list = NULL;
	struct member_list* result_of_search;
	char number;
	char phone_number[20];
	int del;

	do {

		printf("press 1 for show\npress 2 for add\npress 3 for search or delete\npress 4 for exit\n");
		number = getchar();
        getchar();

		switch (number) {

		case '1':

			show(list);
			break;

		case '2':

			add(&list);
			system("clear");
			break;

		case '3':

			printf("enter the phone number:\n");
			fgets(phone_number, 19, stdin);
			phone_number[strcspn(phone_number, "\n")] = '\0';

			result_of_search = search(list, phone_number);
			printf("delete?\n");
			scanf("%d", &del);
			getchar();

			if (del && result_of_search) {

				execute(result_of_search);

			}
			break;
		case '4':
			prog = 0;
		}

	} while (prog);
	return 0;
}

