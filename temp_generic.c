#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    int age;
    char *name;
};

int cmpstr(void* v1, void* v2)
{
	char *a1 = *(char**)v1;
	char *a2 = *(char**)v2;
	return strcmp(a1, a2);
}

int cmpnum(void* s1, void* s2)
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

int cmpperson(void* v1, void* v2)
{
    struct Person guy1 = *(struct Person*)v1;
    struct Person guy2 = *(struct Person*)v2;

    char* name1 = guy1.name;
    char* name2 = guy2.name;

    // Compare age 
    int ans = cmpnum(&guy1.age, &guy2.age);
    if (ans == 0){
        // Compare names 
        return cmpstr(&name1, &name1);
    } else {
        return ans;
    }
}

void swap(void* v1, void* v2, int size)
{
	char buffer[size];

	memcpy(buffer, v1, size);
	memcpy(v1, v2, size);
	memcpy(v2, buffer, size);
}

void _qsort(void* v, int size, int left, int right,
					int (*comp)(void*, void*))
{
	void *vt, *v3;
	int i, last, mid = (left + right) / 2;
	if (left >= right)
		return;

	void* vl = (char*)(v + (left * size));
	void* vr = (char*)(v + (mid * size));
	swap(vl, vr, size);
	last = left;
	for (i = left + 1; i <= right; i++) {

		vt = (char*)(v + (i * size));
		if ((*comp)(vl, vt) > 0) {
			++last;
			v3 = (char*)(v + (last * size));
			swap(vt, v3, size);
		}
	}
	v3 = (char*)(v + (last * size));
	swap(vl, v3, size);
	_qsort(v, size, left, last - 1, comp);
	_qsort(v, size, last + 1, right, comp);
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
    struct Person fourtneen = {.name="Risa",.age= 24}; 
    struct Person fifteen = {.name="Benny",.age= 28}; 
    struct Person sixteen = {.name="Juan",.age= 33}; 
    struct Person seventeen = {.name="Natalie",.age= 25}; 

    struct Person arr[] = {one, two, three};
    int size_people = sizeof(int*)/sizeof(int);

    for (int i=0; i <= 2; i++){
        printf("str: %s\n",arr[i].name);
    }

    qsort(arr, 2, sizeof(Person), cmpperson);


    for (int i=0; i <= 2; i++){
        printf("str: %s\n",arr[i].name);
    }


//	char* a[] = {"bbc", "xcd", "ede", "def",
//			"afg", "hello", "hmmm", "okay", "how" };
//
//	int b[] = { 45, 78, 89, 65, 70, 23, 44 };
//	int* p = b;
//	_qsort(a, sizeof(char*), 0, 8, (int (*)(void*, void*))(cmpstr));
//	_qsort(p, sizeof(int), 0, 6, (int (*)(void*, void*))(cmpnum));
//
//	for (int i = 0; i < 9; i++)
//		printf("%s ", a[i]);
//	printf("\n");
//
//	for (int i = 0; i < 7; i++)
//		printf("%d ", b[i]);
	return 0;
}

