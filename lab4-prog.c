#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

typedef struct list2 {
    int field;
    struct list2 *ptr2;
} List2;

typedef struct list {
    int field;
    struct list *ptr;
    struct list2 *other;
} List;

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

List2 *init(int a) {
    List2 *lst;
    lst = (List2*)malloc(sizeof(List2));
    lst->field = a;
    lst->ptr2 = NULL;
    return(lst);
}

List2 *addelem(List2 *lst, int number) {
    List2 *temp, *p;
    temp = (List2*)malloc(sizeof(List2));
    p = lst->ptr2;
    lst->ptr2 = temp;
    temp->field = number;
    temp->ptr2 = p;
    return(temp);
}


/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

List *init2(int a) {
    List *lst;
    lst = (List*)malloc(sizeof(List));
    lst->field = a;
    lst->ptr = NULL;
    return(lst);
}

List *addelem2(List *lst, int number) {
    List *temp, *p;
    temp = (List*)malloc(sizeof(List));
    p = lst->ptr;
    lst->ptr = temp;
    temp->field = number;
    temp->ptr = p;
    return(temp);
}



int main(void) {
    int N,K;
    int counter = 0;
    int counter2 = 0;
    int i = 0;

    List *list;
    List2 *list2;

    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (counter == 0) {
            list = init2(num);
            counter = 1;
        }
        addelem2(list, num);
        N++;
    }

    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (counter2==0) {
            list2 = init(num);
            counter2 = 1;
        }
        addelem(list2, num);
        K++;
    }

    while (i!=abs(N-K)) {
        List *temp = list;
        List2 *temp2 = list2;
        temp->other = temp2;
        i++;
        temp = temp->ptr;
        temp2 = temp2->ptr2;
    }

    List *S = list;

    printf("%d\n", S->field);

    while (1) {
        char *s;
        scanf("%s", s);
        if (strcmp(s, "d") == 0) {
            S=S->other;
            printf("%d\n", S->field);
        }
        if (strcmp(s, "r") == 0) {
            S=S->ptr;
            printf("%d\n", S->field);
        }
        if (strcmp(s, "q")== 0) {
            break;
        }
    }

    return 0;
}
