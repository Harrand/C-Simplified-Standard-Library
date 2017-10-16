#include "vector.h"
#include <stdio.h>
#include <assert.h>
void unit_test_vector();

int main()
{
	unit_test_vector();
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
	destroy_vector(&v);
	printf("unit test for vector complete.\n");
}