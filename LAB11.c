#include <stdio.h>
#include <string.h>


char first_word[100];

char table_ASCII[128] = {0}; 


    /*
     * Эта функция принимает строку(string), введенную
     * пользователем и создает строку(first_word) с первым
     * словом, которое ввел пользователь   
     */


void where_is_first_word (char* string) {  

    int i = 0;

    for (;(string[i]!=' ')&&(string[i]!='\0');i++) {

        first_word[i] = string[i];

    }

      first_word[i] = '\0';    

}


     /*
      * Эта функция выводит количество слов не учитывая first_word
      */   



int numbers_of_words (char* string) {

    int counter = 0;

    for (int i = 0; i < 100; i++) {

        if (string[i] == ' ') {

            counter+=1;

        }

        return counter;
    }

}



    /*
    * Эта функция помечает в таблице ASCII цифрой 1,
    * все буквы, которые есть в первом слове (first_word)
    */    


void symbols_first_word (char* first_word) {

    for (int i = 0; first_word[i]!='\0'; i++) {

        table_ASCII[first_word[i]] = 1;

    }
}

int main(void) {

    char string[101];                   

    fgets(string, 100, stdin);

    where_is_first_word(string);
    symbols_first_word(first_word);  
    int n = numbers_of_words(string);

    char flag = 1;

    for (int i = 0; i<n; i++) {

        for (int j = strlen(first_word); string[j] != ' '; j++) {

            if (flag) {

                

            }

        }

    }
    
  

    return 0;

}



// gcc LAB11.c -o l11 && ./l11
