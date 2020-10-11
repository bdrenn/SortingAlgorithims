#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compares two ints
int cmpnum(const void* s1, const void* s2);
// Compares two floats
int cmpfloat(const void* s1, const void* s2);
// Compares two people
int cmpperson(const void* v1, const void* v2);
// Person Structure
struct Person;


struct Person{
    int age;
    char *name;
};

int cmpnum(const void* s1, const void* s2)
{
	int *a = (int*)s1;
	int *b = (int*)s2;
	if ((*a) > (*b))
		return 1;
	else if ((*a) < (*b))
		return -1;
	else
		return 0;
}

int cmpfloat(const void* s1, const void* s2)
{
	float *a = (float*)s1;
	float *b = (float*)s2;
	if ((*a) > (*b))
		return 1;
	else if ((*a) < (*b))
		return -1;
	else
		return 0;
}

int cmpperson(const void* v1, const void* v2)
{
    struct Person guy1 = *(struct Person*)v1;
    struct Person guy2 = *(struct Person*)v2;

    // Compare age 
    int ans = cmpnum(&guy1.age, &guy2.age);
    if (ans == 0){
        // Compare names 
        return strcmp(guy1.name, guy2.name);
    } else {
        return ans;
    }
}

int main()
{
    // People
    struct Person one = {.name="Hal",.age= 20}; 
    struct Person two = {.name="Susann",.age= 31}; 
    struct Person three = {.name="Dwight",.age= 19}; 
    struct Person four = {.name="Kassandra",.age= 21}; 
    struct Person five = {.name="Lawrence",.age= 25}; 
    struct Person six = {.name="Cindy",.age= 22}; 
    struct Person seven = {.name="Corc",.age= 27}; 
    struct Person eight = {.name="Mac",.age= 19}; 
    struct Person nine = {.name="Romana",.age= 27}; 
    struct Person ten = {.name="Doretha",.age= 32}; 
    struct Person eleven = {.name="Danna",.age= 20}; 
    struct Person twelve = {.name="Zara",.age= 23}; 
    struct Person thirteen = {.name="Rosalyn",.age= 26}; 
    struct Person fourteen = {.name="Risa",.age= 24}; 
    struct Person fifteen = {.name="Benny",.age= 28}; 
    struct Person sixteen = {.name="Juan",.age= 33}; 
    struct Person seventeen = {.name="Natalie",.age= 25}; 
    
    struct Person arr[] = {one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen};
    int size_people = sizeof(int*)/sizeof(int);

    float c[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};

    // Sort
    qsort(arr, 17, sizeof(struct Person), cmpperson);
    qsort(c, 12, sizeof(float), cmpfloat);

    // Print People
    printf("People: \n");
    for (int i=0; i <= 16; i++){
        printf("%s, %d\n",arr[i].name, arr[i].age);
    }
    printf("\n");

    // Print floats
    printf("floats: \n");
	for (int i = 0; i < 12; i++)
		printf("%f\n", c[i]);
	return 0;
}

