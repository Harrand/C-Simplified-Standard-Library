#include "vector.h"
#include "algorithm.h"
#include "fstream.h"
#include <stdio.h>
#include <assert.h>
void unit_test_vector();
void unit_test_algorithm();
void unit_test_fstream();

int main()
{
	unit_test_vector();
	//unit_test_algorithm();
	unit_test_fstream();
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
	clear(&v);
	assert(v.size == 0);
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
	printf("testing algorithm...\n");
	// unsorted = 1, 5, 9, 78, 0, 2, 10
	// sorted = 0, 1, 2, 5, 9, 10, 78
	printf("testing bubble-sort...\n");
	vector v = create_vector();
	int unsorted[7] = {1, 5, 9, 78, 0, 2, 10};
	int sorted[7] = {0, 1, 2, 5, 9, 10, 78};
	for(size_t i = 0; i < 7; i++)
		push_back(&v, &unsorted[i]);
	bubble_sort(&v, &compare_int);
	for(size_t i = 0; i < 7; i++)
		assert(*(int*)at(v, i) == sorted[i]);
	destroy_vector(&v);
	
	printf("testing merge-sort...\n");
	vector vec = create_vector();
	for(size_t i = 0; i < 7; i++)
		push_back(&vec, &unsorted[i]);
	merge_sort(&vec, &compare_int);
	print_elements(vec);
	printf("unit test for algorithm complete.\n");
}

void unit_test_fstream()
{
	printf("testing fstream...\n");
	ifstream test = open("test.txt");
	assert(test.good);
	read_all(&test);
	printf("%s\n", test.buffer);
	close(&test);
	ofstream test_edit = edit_file("test.txt");
	write(&test_edit, "i added some more data to this file!\n");
	printf("unit test for fstream complete");
}