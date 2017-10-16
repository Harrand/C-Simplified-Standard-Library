#include "vector.h"
#include "algorithm.h"
#include <stdio.h>
#include <assert.h>
void unit_test_vector();
void unit_test_algorithm();

int main()
{
	unit_test_vector();
	unit_test_algorithm();
	return 0;
}

void unit_test_vector()
{
	printf("unit-testing vector...\n");
	vector v = create_vector();
	for(unsigned int i = 0; i < 5; i++)
	{
		int x = i * 2;
		push_back(&v, &x);
	}
	size_t original_size = v.size;
	for(unsigned int i = 0; i < 5; i++)
	{
		int x = i * 2;
		assert(*(int*)(at(v, i)) == x);
	}
	int* last = (int*)pop_back(&v);
	assert(*last == 8);
	free(last);
	assert(v.size < original_size);
	int zero = 0;
	resize(&v, 100, &zero);
	assert(v.size == 100);
	destroy_vector(&v);
	printf("unit test for vector complete.\n");
}

int compare_int(void* left, void* right)
{
	int l = *(int*)(left);
	int r = *(int*)(right);
	return l > r;
}

void unit_test_algorithm()
{
	// unsorted = 1, 5, 9, 78, 0, 2, 10
	// sorted = 0, 1, 2, 5, 9, 10, 78
	vector v = create_vector();
	int unsorted[7] = {1, 5, 9, 78, 0, 2, 10};
	int sorted[7] = {0, 1, 2, 5, 9, 10, 78};
	for(size_t i = 0; i < 7; i++)
		push_back(&v, &unsorted[i]);
	bubble_sort(&v, &compare_int);
	for(size_t i = 0; i < 7; i++)
		assert(*(int*)at(v, i) == sorted[i]);
	destroy_vector(&v);
}