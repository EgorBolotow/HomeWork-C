#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>

typedef struct student{
	int uid;
	char name[128];
	char group[12];
	int average_grade;
} Student_t;



void print_student(Student_t* array_of_student, int i) {
    printf("%d %s %d %s \n",
    array_of_student[i].uid, array_of_student[i].group,
    array_of_student[i].average_grade, array_of_student[i].name);

}

int main(int argc, char** argv)
{

    system("chcp 65001 > nul");
    FILE* file = fopen("students.txt", "r");


    if(file == NULL) {
		perror("Can't open file.");
		return 1;
	}

	int size;
	fscanf(file, "%d", &size);

	Student_t *array = (Student_t*) malloc( sizeof(Student_t) * size);

	for (int i=0; i != size; i++) {
        fscanf(file, "%d%s%d", &array[i].uid, array[i].group, &array[i].average_grade);
        fgets(array[i].name,127,file);
	}

	if (strcmp("-uid", argv[1]) == 0) {
        int id = atoi(argv[2]);
	    printf("Студент с uid: %d\n", id);
	    for (int i = 0; i!=size; i++) {
            if (array[i].uid == id) {
                print_student(array, i);
            }
	    }
	}

	if (strcmp("-n", argv[1]) == 0) {
	    printf("Студент с частью имени: %s\n", argv[2]);
	    for (int i = 0; i!=size; i++) {
            if(strstr(array[i].name, argv[2]) != NULL) {
				print_student(array, i);
			}
	    }
	}

	if (strcmp("-g", argv[1]) == 0) {
	    printf("Студенты группы: %s\n", argv[2]);
	    for (int i = 0; i!=size; i++) {
            if (strcmp(array[i].group, argv[2]) == 0) {
                print_student(array, i);
            }
	    }
	}

	if (strcmp("-b", argv[1]) == 0) {
        int av_grade = atoi (argv[2]);
        for (int i=0; i!=size; i++) {
            if (array[i].average_grade>av_grade) {
                print_student(array, i);
            }
        }
	}



    return 0;
}
