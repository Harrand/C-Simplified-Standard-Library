#ifndef FSTREAM_H
#define FSTREAM_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define IFSTREAM_DEFAULT_BUFFER_SIZE 256

struct ifstream
{
	FILE* file_handle;
	char* buffer;
	size_t buffer_size;
	int good;
};

typedef struct ifstream ifstream;

ifstream open(const char* file_name);
void read_all(ifstream* file);
void close(ifstream* opened_file);

#endif