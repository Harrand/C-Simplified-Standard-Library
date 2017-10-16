#include "vector.h"
#include <stdlib.h> //realloc
#include <stdio.h>

vector create_vector()
{
	vector v;
	v.data = NULL;
	v.size = 0;
	return v;
}

void destroy_vector(vector* v)
{
	for(size_t i = 0; i < v->size; i++)
	{
		free(v->data[i]);
	}
	v->size = 0;
	free(v->data);
}

void push_back(vector* v, void* entry)
{
	v->data = (void**)realloc(v->data, ++(v->size) * sizeof(void*));
	v->data[v->size-1] = copy(entry);
}

void* at(vector v, size_t index)
{
	return v.data[index];
}

void* pop_back(vector* v)
{
	void* cpy = copy(v->data[v->size-1]);
	free(v->data[v->size-1]);
	v->data = (void**)realloc(v->data, --(v->size) * sizeof(void*));
	return cpy;
}

void print_elements(vector v)
{
	if(v.size < 1)
		return;
	for(unsigned int i = 0; i < v.size; i++)
	{
		void* cur = at(v, i);
		int* curI = (int*)(cur);
		printf("%d: address %p, value %d\n", i, cur, *curI);
	}
}