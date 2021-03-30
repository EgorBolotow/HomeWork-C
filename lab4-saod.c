#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
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


void pushFront(List* list, int* data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        exit(1);
    }
    temp->value = *(data);
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


void pushBack(List* list, int* value) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        exit(3);
    }
    temp->value = *(value);
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


void print_Int(int value) {
    printf("%d ", value);
}


void print_List(List* list) {
    Node *temp = list->head;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


Node* getNode(List *list, size_t index) {
    Node *temp = list->head;
    size_t i = 0;
 
    while (temp && i < index) {
        temp = temp->next;
        i++;
    }
 
    return temp;
}

void deleteNode(List *list, size_t index) {
    Node *elm = NULL;
    elm = getNode(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
 
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
 
    free(elm);
 
    list->size--;
 
}

void insertNode(List *list, size_t index, int* value) {
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNode(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = *(value);
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;
 
    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }
 
    list->size++;
}

int k_em_back (List* list, int k) {
    Node* temp = list->tail;
    for (k;k>1;k--) {
        temp = temp->prev;    
    }   
    return temp->value;
}

void deleteDuplicates (List* list) {
    Node* temp = list->head;
    for (int i = 0; i < list->size-1; i++) {
        if (temp->value == temp->next->value) {
            deleteNode(list, i+1);
            temp = temp->next;
        }   
    }
}

int isPalindrom (List* list) {
    int flag = 1;
    Node* t_head = list->head;
    Node* t_tail = list->tail;
    
    while (flag) {
        if (t_tail != t_head) {
            if (t_tail->value == t_head->value) {
                flag = 1;
            } else {
                flag = 0;
            }
        } else {
            break;
        }
        t_head = t_head->next;
        t_tail = t_tail->prev;
    }
    
    return flag;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 5;
    List* list = create_List();
    pushFront(list,&a);
    pushFront(list,&a);
    pushFront(list,&b);
    pushFront(list,&b);
    pushBack(list,&c);
    pushBack(list,&c);

    print_List(list);
    
    int k = 3; int i = 1;
    
    printf("%d элемент с конца = %d\n", k, k_em_back(list,k));
    
    deleteDuplicates(list);
    print_List(list);
    printf("\n");
    
    // check Palindrom

    List* list2 = create_List();
    pushFront(list2,&a);
    pushFront(list2,&b);
    pushFront(list2,&b);
    pushFront(list2,&a);
    print_List(list2);
    if (isPalindrom(list2)) {
        printf("Число является палиндромом");
    } else {
        printf("Не является палиндромом");
    }

    free(list);
    free(list2);
    return 0;
}  
