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
			at(*v, i - 1) = at(*v, i);
			at(*v, i) = temp;
		}
	}
	}
}

void merge_sort(vector* v, int (*compare_function)(void*, void*))
{
	if(v->size < 2)
		return;
	size_t halfway = v->size / 2;
	vector a = create_vector();
	for(size_t i = 0; i < halfway; i++)
		push_back(&a, at(*v, i));
	vector b = create_vector();
	for(size_t i = halfway; i < v->size; i++)
		push_back(&b, at(*v, i));
	vector sorted = merge_sort_impl(a, b, compare_function);
	destroy_vector(&a);
	destroy_vector(&b);
	clear(v);
	for(size_t i = 0; i < sorted.size; i++)
		push_back(v, at(sorted, i));
	destroy_vector(&sorted);
}

vector merge_sort_impl(vector a, vector b, int (*compare_function)(void*, void*))
{
	// a and b are sorted and of equal size
	vector res = create_vector();
	unsigned int a_index = 0, b_index = 0;
	while(a_index < a.size && b_index < b.size)
	{
		if(compare_function(at(a, a_index), at(b, b_index)))
		{
			push_back(&res, at(a, a_index++));
		}
		else
		{
			push_back(&res, at(b, b_index++));
		}
	}
	destroy_vector(&a);
	destroy_vector(&b);
	return res;
}
