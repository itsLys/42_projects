#include "test.h"
size_t get_case()
{
	static size_t i = 0;
	return (i++);
}
