#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char * firstName;
  char * calledName;
  char * surname;
  float GPA;
  int studentID;
};
typedef struct student Student;

Student** loadSomeData();
Student* createStudent(char*, char*, char*, float, int);
void printFirst(Student* stu);
void printLast(Student* stu);
void printGPA(Student* stu);

int compareStudent(const void* av, const void *bv);

void printList(int sizeOfArray, Student** array,
    void (*funcptr) (Student*)
    );

int main(void)
{
    Student** array;

    array = loadSomeData();

    printList(3, array, &printFirst);
    printf("---\n");
    printList(3, array, &printLast);
    printf("---\n");
    printList(3, array, &printGPA);
    printf("---\n");
    qsort(array, 3, sizeof(Student*), &compareStudent);
    printList(3, array, &printGPA);

    return(0);
}

int compareStudent(const void* av, const void *bv) {
    const Student* a = *(Student**)av;
    const Student* b = *(Student**)bv;
    if (a->GPA < b->GPA) return -1;
    else if (a->GPA > b->GPA) return 1;
    else return 0;
}

void printFirst(Student* stu) {
    printf("%s\n", stu->firstName);
}

void printLast(Student* stu) {
    printf("%s\n", stu->surname);
}

void printGPA(Student* stu) {
    printf("%.1f\n", stu->GPA);
}

void printList(int sizeOfArray, Student** array,
    void (*funcptr) (Student*)
    ) {
    for (int i=0; i<sizeOfArray; i++) {
        funcptr(array[i]);
    }
}

Student ** loadSomeData(){
    Student ** newList = malloc(sizeof(Student*)*3);

    newList[0] = createStudent("Ash", "Yellow", "Ketchum", 2.0, 1);
    newList[1] = createStudent("Gary", "Blue", "Oak", 1.0, 2);
    newList[2] = createStudent("Daisy", "May", "Oak", 2.5, 3);

    return (newList);
}

Student* createStudent(char* fname, char* cname, char* lname, float GPA, int id) {
    Student* new = malloc(sizeof(Student));
    new->studentID = id;
    new->firstName = malloc(sizeof(char)*(strlen(fname) +1));
    strcpy(new->firstName, fname);
    new->calledName = malloc(sizeof(char)*(strlen(cname) +1));
    strcpy(new->calledName, cname);
    new->surname = malloc(sizeof(char)*(strlen(lname) +1));
    strcpy(new->surname, lname);
    new->GPA = GPA;
    return new;
}
