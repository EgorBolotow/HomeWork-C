#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    void *value;
    struct node *next;
    struct node *prev; 
} Node;


typedef struct list {
    size_t size;
    Node *head;
    Node *tail;
} List;


List* create_List() {
    List *temp = (List*)malloc(sizeof(List));
    temp->size = 0;
    temp->head = temp->tail = NULL;
 
    return temp;
}


void pushFront(List* list, void *data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        exit(1);
    }
    temp->value = data;
    temp->next = list->head;
    temp->prev = NULL;
    if (list->head) {
        list->head->prev = temp;
    }
    list->head = temp;
 
    if (list->tail == NULL) {
        list->tail = temp;
    }
    list->size++;
}


void pushBack(List* list, void *value) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        exit(3);
    }
    temp->value = value;
    temp->next = NULL;
    temp->prev = list->tail;
    if (list->tail) {
        list->tail->next = temp;
    }
    list->tail = temp;
 
    if (list->head == NULL) {
        list->head = temp;
    }
    list->size++;
}


void print_Int(void *value) {
    printf("%d ", *((int*) value));
}


void print_List(List* list, void (*fun)(void*)) {
    Node *temp = list->head;
    while (temp) {
        fun(temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void* k_em_back (List* list, int k) {
    for (k;k!=0;k--) {
        list = list->tail->prev;    
    }   
    return list->tail->value;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;
    List* list = create_List();
    pushFront(list,&a);
    print_List(list,print_Int);
    pushFront(list,&b);
    print_List(list,print_Int);
    pushBack(list,&c);
    print_List(list,print_Int);
    
    int* val = k_em_back(list,2);
    printf("%d", *val);

    return 0;
}
