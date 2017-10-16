#ifndef FSTREAM_H
#define FSTREAM_H
#include <stdio.h>
#include <stddef.h>

#define IFSTREAM_DEFAULT_BUFFER_SIZE 16

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

struct ofstream
{
	FILE* file_handle;
	int good;
};

typedef struct ofstream ofstream;
ofstream open(const char* file_name, const char* mode);
ofstream create_file(const char* file_name);
ofstream edit_file(const char* file_name);
void write(ofstream* out_file, const char* data);
void put(ofstream* out_file, char c);
void close(ofstream* opened_file);

#endif