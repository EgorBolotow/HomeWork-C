#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct list2 {
    int field;
    struct list2 *ptr;
} List2;

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
    struct list2 *other;
} Node;


typedef struct list {
    size_t size;
    Node *head;
    Node *tail;
} List;

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

List* create_List() {
    List *temp = (List*)malloc(sizeof(List));
    temp->size = 0;
    temp->head = temp->tail = NULL;
 
    return temp;
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


void print_List(List* list) {
    Node *temp = list->head;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

List2 *init(int a) {
    List2 *lst;
    lst = (List2*)malloc(sizeof(List));
    lst->field = a;
    lst->ptr = NULL;
    return(lst);
}

List2 *addelem(List2 *lst, int number) {
    List2 *temp, *p;
    temp = (List2*)malloc(sizeof(List2));
    p = lst->ptr; 
    lst->ptr = temp; 
    temp->field = number;
    temp->ptr = p; 
    return(temp);
}

void listprint(List2 *lst) {
    List2 *p;
    p = lst;
    do {
        printf("%d ", p->field);
        p = p->ptr; 
    } while (p != NULL);
}

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

int main(void) {
    int N,K;
    
    List *list = create_List();
    List2 *list2;
    int flag = 1;
    
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        pushBack(list, &num);
        N++;
    }
    
    printf("\n");
    printf("\n");
    
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (flag) {
            list2 = init(num);
            flag = 0;
        }
        addelem(list2,num);
        K++;
    }
    
    int counter = 0;
    
    while (counter != abs(N-K)) {
        Node *temp = list->head;
        List2 *temp2 = list2;
        
        temp->other = temp2;
        temp->next;
        temp2->ptr;
        counter++;
    }
    
    Node *S = list->head;
    
    printf("\n\n");
    
    printf("%d", S->value);
    printf("\n");
    
    while (1) {
        char *cymbol;
        scanf("%s", cymbol);
        if (strcmp(cymbol,"r") == 0) {
            if (S->next == NULL) {
                break;
            }
            S = S->next;
            printf("%d", S->value);
        }
    }
    
    return 0;
}
