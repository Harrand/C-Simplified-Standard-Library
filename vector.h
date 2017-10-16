#ifndef VECTOR_H
#define VECTOR_H
#include "utility.h"
#include <stddef.h>

struct vector
{
	void** data;
	size_t size;
};

typedef struct vector vector;

vector create_vector();
void destroy_vector(vector* v);
void push_back(vector* v, void* entry);
void* at(vector v, size_t index);
void* pop_back(vector* v);
void print_elements(vector v);

#endif