#include "libft.h"
#include <stdio.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;

	if (!del || !lst || !*lst)
		return;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
	*lst = NULL;
}
