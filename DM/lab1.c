#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* data;
    unsigned char maxSym;
} Set;

const int success = 0;
const int incorrect_input = 2;


void prFill(char* arr, char len, char val)
{
    for (size_t i = 0; i < len; ++i)
    {
        *(arr + i) = val;
    }
}

void prReadUntil(char until)
{
    char c = (char) getchar();
    while (c != until)
    {
        c = (char) getchar();
    }
}

int getSetFromCon(Set** set)
{
    char* data = malloc(sizeof(char) * 26);
    char maxSym = 0;
    prFill(data, 26, 0);
    char lastSym = 0;
    char c = (char) getchar();
    while (c != '\n') {
        if (!(c >= 'a' && c <= 'z') && c!= ' ')
        {
            prReadUntil('\n');
            free(data);
            return incorrect_input;
        }
        if (c != ' ')
        {
            if (lastSym == 0)
            {
                c = (char) (c - 'a');
                if (c > maxSym)
                {
                    maxSym = c;
                }
                *(data + c) = 1;
                lastSym = 1;
            }
            else {
                prReadUntil('\n');
                free(data);
                return incorrect_input;
            }
        }
        else {
            lastSym = 0;
        }
        c = (char) getchar();
    }
    *set = malloc(sizeof(set));
    (*set)->data = data;
    (*set)->maxSym = (unsigned char) maxSym;
    return success;
}

void destSet(Set** set)
{
    free((*set)->data);
    free(*set);
    *set = NULL;
}

void printSet(Set* set)
{
    if (set->maxSym == 0 && *(set->data) == 0)
    {
        printf("Пустое множество\n");
        return;
    }
    size_t max = set->maxSym;
    for (size_t i = 0; i <= max; ++i)
    {
        if (*(set->data + i) == 1)
        {
            printf("%c ", (char) (i + 'a'));
        }
    }
    printf("\n");
}

Set* merge(Set* set1, Set* set2)
{
    size_t max = 0;
    if (set1->maxSym > set2->maxSym)
    {
        max = set1->maxSym;
    }
    else {
        max = set2->maxSym;
    }
    char* data = malloc(sizeof(char) * 26);
    prFill(data, 26, 0);
    size_t tmpMax = 0;
    for (size_t i = 0; i <= max; ++i)
    {
        if (*(set1->data + i) == 1 || *(set2->data + i) == 1)
        {
            *(data + i) = 1;
            tmpMax = i;
        }
    }
    Set* res = malloc(sizeof(Set));
    res->data = data;
    res->maxSym = (unsigned char) tmpMax;
    return res;
}

Set* intersect(Set* set1, Set* set2)
{
    size_t max = 0;
    if (set1->maxSym > set2->maxSym)
    {
        max = set1->maxSym;
    }
    else {
        max = set2->maxSym;
    }
    char* data = malloc(sizeof(char) * 26);
    prFill(data, 26, 0);
    size_t tmpMax = 0;
    for (size_t i = 0; i <= max; ++i)
    {
        if (*(set1->data + i) == 1 && *(set2->data + i) == 1)
        {
            *(data + i) = 1;
            tmpMax = i;
        }
    }
    Set* res = malloc(sizeof(Set));
    res->data = data;
    res->maxSym = (unsigned char) tmpMax;
    return res;
}

char subSet(Set* set1, Set* set2)
{
    if (set1->maxSym == 0 && *(set1->data) == 0)
    {
        return 1;
    }
    size_t max = set1->maxSym;
    for (size_t i = 0; i <= max; ++i)
    {
        if (*(set1->data + i) != *(set2->data + i))
        {
            return 0;
        }
    }
    return 1;
}

Set* complement(Set* set1, Set* set2)
{
    size_t max = 0;
    if (set1->maxSym > set2->maxSym)
    {
        max = set1->maxSym;
    }
    else
    {
        max = set2->maxSym;
    }
    char* data = malloc(sizeof(char) * 26);
    prFill(data, 26, 0);
    size_t tmpMax = 0;
    for (size_t i = 0; i <= max; ++i)
    {
        if (*(set1->data + i) == 1 && *(set2->data + i) == 0)
        {
            *(data + i) = 1;
            tmpMax = i;
        }
    }
    Set* res = malloc(sizeof(Set));
    res->data = data;
    res->maxSym = (unsigned char) tmpMax;
    return res;
}

Set* symComplement(Set* set1, Set* set2)
{
    size_t max = 0;
    if (set1->maxSym > set2->maxSym)
    {
        max = set1->maxSym;
    }
    else {
        max = set2->maxSym;
    }
    char* data = malloc(sizeof(char) * 26);
    prFill(data, 26, 0);
    size_t tmpMax = 0;
    for (size_t i = 0; i <= max; ++i)
    {
        if (*(set1->data + i) == 1 ^ *(set2->data + i) == 1)
        {
            *(data + i) = 1;
            tmpMax = i;
        }
    }
    Set* res = malloc(sizeof(Set));
    res->data = data;
    res->maxSym = (unsigned char) tmpMax;
    return res;
}

void getSet(char* name, Set** set)
{
    char* str = "Через пробел введите элементы множества ";
    printf("%s",str);
    printf("%s",name);
    printf(".\n");
    int flag = getSetFromCon(set);
    while (flag != 0) {
        printf("Некорректные данные. Попробуйте еще раз.\n");
        flag = getSetFromCon(set);
    }
}

void printMenu()
{
    printf("\n\t1. A ⊂ B\n");
    printf("\t2. A ∪ B\n");
    printf("\t3. A ⋂ B\n");
    printf("\t4. А \\ В\n");
    printf("\t5. В \\ А\n");
    printf("\t6. А ⊕ В\n");
    printf("\t7. Выход\n");
}

void printAnsw(Set* setA, Set* setB)
{
    printf("A = ");
    printSet(setA);
    printf("B = ");
    printSet(setB);
    printf("Результат.\n");
}

int main()
{
    Set* setA;
    getSet("A", &setA);
    Set* setB;
    getSet("B", &setB);
    char exit = 0;
    while (exit == 0)
    {
        printMenu();
        char c = (char) getchar();
        Set* setC = NULL;
        switch (c) {
            case '1':
                printAnsw(setA, setB);
                if (subSet(setA, setB) == 1)
                {
                    printf("Да\n");
                }
                else
                {
                    printf("Нет\n");
                }
                break;
            case '2':
                printAnsw(setA, setB);
                setC = merge(setA, setB);
                printSet(setC);
                destSet(&setC);
                break;
            case '3':
                printAnsw(setA, setB);
                setC = intersect(setA, setB);
                printSet(setC);
                destSet(&setC);
                break;
            case '4':
                printAnsw(setA, setB);
                setC = complement(setA, setB);
                printSet(setC);
                destSet(&setC);
                break;
            case '5':
                printAnsw(setA, setB);
                setC = complement(setB, setA);
                printSet(setC);
                destSet(&setC);
                break;
            case '6':
                printAnsw(setA, setB);
                setC = symComplement(setA, setB);
                printSet(setC);
                destSet(&setC);
                break;
            case '7':
                exit = 1;
                break;
            default:
                break;
        }
        getchar();
    }
    destSet(&setA);
    destSet(&setB);
    return 0;
}
