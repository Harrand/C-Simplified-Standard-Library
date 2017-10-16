#include "utility.h"
#include <string.h> // memcpy
#include <stdlib.h>

void* copy(void* data)
{
	void* cpy = malloc(sizeof(void*));
	memcpy(cpy, data, sizeof(void*));
	return cpy;
}