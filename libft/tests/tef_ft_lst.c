#include "../libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

void init_lst(void *content, t_list **node)
{
	*node = ft_lstnew(content);
}

void print_bytes(const void *buff, size_t size)
{

	const unsigned char *ap;
	ap = (const unsigned char *)buff;
	printf("[");
	while (size--)
	{
		printf("%.2x", *(ap++));
		if (size)
			printf(", ");
	}
	printf("]\n");
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

void f(void *content)
{
	unsigned char *p = (unsigned char *)content;
	while (*p != 0)
	{
		*p = 1;
		p++;
	}
}

int main()
{
	t_list *node;
	t_list **head = &node;
	init_lst(strdup("abcd"), &node);
	ft_lstadd_front(head, ft_lstnew(strdup("efgh")));
	ft_lstadd_front(head, ft_lstnew(strdup("\x10\xab\xbc")));
	ft_lstadd_back(head, ft_lstnew(strdup("0123")));
	ft_lstadd_back(head, ft_lstnew(strdup("\xaa\xbb\xcc")));
	ft_lstiter(*head, f);
	print_lst(head);
	// ft_lstclear(head, del);
}
