#include "fstream.h"

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
	file->buffer = (char*)realloc(file->buffer, sizeof(char) * ++buffer_size);
	file->buffer[buffer_size - 1] = '\0';
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