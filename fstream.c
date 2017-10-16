#include "fstream.h"
#include <stdlib.h>

ifstream open(const char* file_name)
{
	ifstream in;
	in.file_handle = fopen(file_name, "r");
	in.good = in.file_handle != NULL;
	in.buffer_size = IFSTREAM_DEFAULT_BUFFER_SIZE;
	in.buffer = (char*)malloc(sizeof(char) * in.buffer_size);
	return in;
}

void read_all(ifstream* file)
{
	int character;
	size_t buffer_size = 0;
	do
	{
		character = fgetc(file->file_handle);
		if(++buffer_size > file->buffer_size)
			file->buffer = (char*)realloc(file->buffer, sizeof(char) * buffer_size);
		file->buffer[buffer_size] = character;
	}while(character != EOF);
	if(feof(file->file_handle))
	{
		file->buffer = (char*)realloc(file->buffer, sizeof(char) * ++buffer_size);
		file->buffer[buffer_size - 1] = '\0';
	}
}

void close(ifstream* opened_file)
{
	free(opened_file->buffer);
	opened_file->buffer = NULL;
	opened_file->buffer_size = 0;
	opened_file->good = 0;
	fclose(opened_file->file_handle);
	opened_file->file_handle = NULL;
}

ofstream open(const char* file_name, const char* mode)
{
	ofstream out;
	out.file_handle = fopen(file_name, mode);
	out.good = out.file_handle != NULL;
	return out;
}

ofstream create_file(const char* file_name)
{
	return open(file_name, "w");
}

ofstream edit_file(const char* file_name)
{
	return open(file_name, "a");
}

void write(ofstream* out_file, const char* data)
{
	if(!out_file->good)
		return;
	fprintf(out_file->file_handle, "%s", data);
}

void put(ofstream* out_file, char c)
{
	if(!out_file->good)
		return;
	fprintf(out_file->file_handle, "%c", c);
}

void close(ofstream* opened_file)
{
	if(!opened_file->good)
		return;
	opened_file->good = 0;
	fclose(opened_file->file_handle);
	opened_file->file_handle = NULL;
}