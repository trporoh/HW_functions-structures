#include <stdio.h>

struct member_list {
	char* name;
	char* surname;
	char* number;
};

struct tree {
	struct member_list* abonent;
	struct tree* left = NULL;
	struct tree* right = NULL;
};



void show(struct tree* root) {
	struct tree* ptr = root;
	if (ptr) {
		show(ptr->left);
		show(ptr->right);
		printf("%c \n%c \n%c \n\n", root->abonent->name, root->abonent->surname, root->abonent->number);
	}
}

void add() {
	struct member_list member;
}


int main() {

}