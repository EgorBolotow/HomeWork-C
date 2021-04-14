#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} Node;
 
typedef struct deq {
    Node* left;
    Node* right;
} Deq;

Deq *PushLeft(Deq *deq, int value) {
 
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->prev = NULL;
    node->next = deq->left;
 
    if (deq->left != NULL) {
        deq->left->prev = node;
    } else {
        deq->right = node;
    }
 
    deq->left = node;
 
    return deq;
}

Deq *PushRight(Deq *deq, int value) {
 
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = deq->right;
 
    if (deq->right != NULL) {
        deq->right->next = node;
    } else {
        deq->left = node;
    }
 
    deq->right = node;
 
    return deq;
}

void PrintLeft(const Deq *deq) {
 
    Node *node = deq->left;
 
    for (; node; node = node->next) {
        printf("%d ", node->value);
    }
    printf("\n");
}

void PrintRight(const Deq *deq) {
 
    Node* node = deq->right;
 
    for (; node; node = node->prev)
    {
        printf("%d ", node->value);
    }
    printf("\n");
}

//------------------------------------------
//------------------------------------------
//------------------------------------------
//------------------------------------------

typedef struct List{
    int value;
    int prior;
    struct List *next;
} list;

typedef struct Queue{
    struct List *head, *tail;
    int h_prior;
} queue;

queue* init_q () {
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->head = 0;
    temp->tail = 0;
    temp->h_prior = 100;
    
    return temp;
}

list* init (list* tail, int val, int priority) {
    tail->next = (list*)malloc(sizeof(list));
    tail->next->next = NULL;
    tail->next->value = val;
    tail->next->prior = priority;
    
    return tail->next;
}

void insert (queue* que, int val, int priority) {
    if ((que->head == 0) && (que->tail == 0)) {
        que->tail = (list*)malloc(sizeof(list));
        que->tail->next = NULL;
        que->tail->value = val;
        que->tail->prior = priority;
        que->head = que->tail;
        
        if (que->h_prior > priority) {
            que->h_prior = priority;
        }
    } else {
        que->tail = init(que->tail, val, priority);
        if (que->h_prior > priority) {
            que->h_prior = priority;
        }
    }    
}

void print(queue* que) {
    list* i;
    for(i = que->head; i!= NULL; i=i->next) {
        printf("%d[%d] ",i->value, i->prior);    
    }
}

void delete_node (list* el, list* root, queue* que) {
    list *temp = root;   
    
    if (el == root) {
        temp = temp->next;
        que->head = temp;
        free(el);
    } else {
        while (temp->next!=el) {
        temp = temp->next;
        }
        temp->next = el->next;
        free(el);    
    }
    
}

queue* remove_el (queue* que) {
    int temp_prior = que->h_prior;
    while (temp_prior!=10) {
        list* i = que->head;
        for (i;i!=NULL;i=i->next) {
            if (i->prior == temp_prior) {
                delete_node(i, que->head, que);
                break;
            }
        }
        if (i!= NULL && i->prior == temp_prior) {
            break;    
        }
        temp_prior++;
    }
    return que;
}

int main(void) {
    queue* queue = init_q();
    insert(queue, 6, 1);
    insert(queue, 8, 0);
    insert(queue, 11, 1);
    insert(queue, 13, 1);
    insert(queue, 13, 1);
    print(queue);
    queue = remove_el(queue);
    printf("\n");
    print(queue);
    queue = remove_el(queue);
    queue = remove_el(queue);
    printf("\n");
    print(queue);
    printf("\n");
    
    
    printf("Deque\n");
    
    
    Deq deq = { NULL, NULL };
 
    PushLeft(&deq, 1);
    PushLeft(&deq, 2);
    PushLeft(&deq, 3);
    PushRight(&deq, 3);
    PushRight(&deq, 2);
    PushRight(&deq, 1);
 
    PrintLeft(&deq);
    PrintRight(&deq);
    
    return 0;
}
