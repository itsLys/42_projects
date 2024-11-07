#include "../libft.h"
#include <stdio.h>

int main()
{
	char str[] = "Hello";
	char str2[] = "World";
	// t_list *node;
	// node->next = NULL;
	t_list *node = ft_lstnew(str);
	ft_lstadd_front(&node, ft_lstnew(str2));
	ft_lstadd_front(&node, ft_lstnew(str2));
	ft_lstadd_front(&node, ft_lstnew(str2));
	ft_lstadd_front(&node, ft_lstnew(NULL));
	printf("content: %s\n", (char *)(ft_lstlast(node)->content));
	printf("next: %p\n", (ft_lstlast(node)->next));
}
