#include <stdlib.h>
#include <stdio.h>

typedef struct List {
	int value;
	struct List* next;
} list;

list* add_first(list* head, list* new_element) {
	new_element->next = head;
	return new_element;
}

list* add_last(list* head, list* new_element) {
	if (head == NULL) {
		return new_element;
	}
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = new_element;
	return head;
}

list* add_by_increasing(list* head, list* new_element) {
	list* previous = NULL;
	list* following = head;
	while(following != NULL) {
		if (new_element->value == following->value) {
			free(new_element);
			return head;
		}
		if (new_element->value < following->value) {
			break;
		}
		previous = following;
		following = following->next;
	}
	new_element->next = following;
	if (previous != NULL) {
		previous->next = new_element;
		return head;
	} else {
		return new_element;
	}
}

void delete_list(list* head) {
	while(head != NULL) {
		list* this = head;
		head = head->next;
		free(this);
	}
}

int main(int argc, char** argv) {
	list* head = NULL;

	while(1) {
		int input;
		scanf("%d", &input);
		if (input == 0) {
			break;
		}

		list* element = (list*) malloc(sizeof(list));
		element->value = input;

		head = add_by_increasing(head, element);

	}

	while(head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");

	delete_list(head);
	
	return 0;
}
