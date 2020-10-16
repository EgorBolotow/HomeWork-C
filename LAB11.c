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

    int p = strlen(first_word);

    int start = p;

    int bool = 0;

    while(1) {

		char c = string[p];

		if (c == ' ' || c == '\0') {
			

			if (bool) {
				
				bool = 0;

			} else {
			
				for (int i = start; i<p; i++) {
                    printf("%c", string[i]);
                }

                printf(" ");
			}
			if (c == '\0') { 

				break;

			}

			p++;
			start = p; 

		} else {

			if (table_ASCII[c] == 1) {
                bool = 1;
            }
			p++;

		}
	}
    
  

    return 0;

}



// gcc LAB11.c -o l11 && ./l11
