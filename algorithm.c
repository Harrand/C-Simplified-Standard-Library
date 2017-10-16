#include "algorithm.h"

void bubble_sort(vector* v, int (*compare_function)(void*, void*))
{
	if(v->size < 2) // cant sort unless theres 2 or more elements
		return;
	for(size_t j = 0; j < v->size; j++)
	{
	for(size_t i = 1; i < v->size; i++)
	{
		if(compare_function(at(*v, i - 1), at(*v, i)))
		{// then later > earlier so swap them
			void* temp = at(*v, i - 1);
			//printf("swap!");
			at(*v, i - 1) = at(*v, i);
			at(*v, i) = temp;
		}
	}
	}
}

void merge_sort(vector* v, int (*compare_function)(void*, void*))
{
	// do nothing right now
}
