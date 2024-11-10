#include "libft.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

void init_lst(void *content, t_list **node)
{
	*node = ft_lstnew(content);
}

void print_lst(t_list **head)
{
	t_list *node = *head;
	t_list *last = ft_lstlast(*head);
	size_t lstsize = ft_lstsize(*head);
	printf("size:		%zu\n", lstsize);
	printf("head:		%p\n", *head);
	printf("last node:	%p\n", last);
	while (node)
	{
		printf("----------------------------------------\n");
		printf("content:	");
		print_bytes(node->content, strlen(node->content));
		printf("addr:		%p\n", node);
		printf("next:		%p\n", node->next);
		node = node->next;
	}
	// assert(node == last->next);
}

void del(void *content)
{
	unsigned char *p = (unsigned char *)content;
	if (p)
		*p = 0;
}

void *f(void *content)
{
	char *p = strdup((char *)content);
	*p = '\x12';
	return (void *)p;
}

int main()
{
	t_list *node;
	t_list **head = &node;
	t_list *hh;
	init_lst(strdup("abcd"), &node);
	ft_lstadd_front(head, ft_lstnew(strdup("efgh")));
	ft_lstadd_front(head, ft_lstnew(strdup("\x10\xab\xbc")));
	ft_lstadd_back(head, ft_lstnew(strdup("0123")));
	ft_lstadd_back(head, ft_lstnew(strdup("\xaa\xbb\xcc")));
	hh = ft_lstmap(*head, f, del);
	print_lst(&hh);
	ft_lstclear(head, del);
}
