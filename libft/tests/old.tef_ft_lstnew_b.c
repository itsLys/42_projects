#include "../libft.h"
#include <stdio.h>

void test_add_new(void *str)
{
	t_list *node = ft_lstnew(str);
	if (node->content)
		printf("%s\n", (int *)(node->content));
	free(node);
}

int main()
{
	int a = '0';
	test_add_new(NULL);
	test_add_new(&a);
}
