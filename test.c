#include "vector.h"

int main()
{
	vector v = create_vector();
	for(unsigned int i = 0; i < 5; i++)
	{
		int x = i * 2;
		push_back(&v, &x);
	}
	*(int*)at(v, 2) = 5;
	pop_back(&v);
	print_elements(v);
	destroy_vector(&v);
	return 0;
}