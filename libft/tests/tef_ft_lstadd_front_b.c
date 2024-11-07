#include "../libft.h"
#include <stdio.h>

void test_add_front(t_list *node)
{
	free(node);
}

int main()
{
	char str[] = "Hello";
	char str2[] = "World";
	t_list *node = ft_lstnew(str);
	ft_lstadd_front(&node, ft_lstnew(str2));
	ft_lstadd_front(&node, ft_lstnew(str2));
	ft_lstadd_front(&node, ft_lstnew(str2));
	ft_lstadd_front(&node, ft_lstnew(NULL));
	while (node)
	{
		printf("%s\n", (char *)(node->content));
		node = node->next;
	}
}
