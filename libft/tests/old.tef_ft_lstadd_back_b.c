#include "../libft.h"
#include <stdio.h>

int main()
{

	char str[] = "Hello";
	char str2[] = "World";
	char str3[] = "WWW";
	t_list *node = ft_lstnew(str);
	ft_lstadd_back(&node, ft_lstnew(str2));
	ft_lstadd_back(&node, ft_lstnew(str2));
	ft_lstadd_back(&node, ft_lstnew(str3));
	ft_lstadd_back(&node, ft_lstnew(NULL));
	while (node)
	{
		printf("%s\n", (char *)(node->content));
		node = node->next;
	}
}
