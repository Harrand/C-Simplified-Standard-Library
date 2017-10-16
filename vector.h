#ifndef VECTOR_H
#define VECTOR_H
#include "utility.h"
#include <stddef.h>

// Like std::vector, this vector is essentially a dynamic array that is guaranteed to be contiguous
struct vector
{
	void** data;
	size_t size;
};

typedef struct vector vector;

vector create_vector(); // O(1)
void destroy_vector(vector* v); // O(N)
void push_back(vector* v, void* entry); // O(N)
//C++ std::vector::push_back(...) is amortized constant as it pre-allocates. this is a simple implementation so remains linear until pre-allocation is implemented here.
// at needs to be a macro because otherwise we copy a pointer and try to assign to an rvalue
#define at(v, i) ((v).data[(i)])
void* pop_back(vector* v); // O(N) (i think)
void resize(vector* v, size_t new_size, void* default_value); // O(N)
void clear(vector* v);
void print_elements(vector v); // O(N)

#endif