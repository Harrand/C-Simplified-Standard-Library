#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "vector.h"
/* for int (*compare_function)(void*, void*):
	should return 1 when left void* > right void*, 0 if not
*/
void bubble_sort(vector* v, int (*compare_function)(void*, void*));
void merge_sort(vector* v, int (*compare_function)(void*, void*));
vector merge_sort_impl(vector a, vector b, int (*compare_function)(void*, void*));

#endif