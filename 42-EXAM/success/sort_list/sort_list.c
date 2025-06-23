#include "list.h"

void swap_values(t_list *t1, t_list *t2)
{
	int temp = t1->data;
	t1->data = t2->data;
	t2->data = temp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *temp;
	int continuer;

	continuer = 1;
	temp = lst;
	while (continuer == 1)
	{
		continuer = 0;
		while (temp != 0 && temp->next != 0)
		{
			if (!cmp(temp->data, temp->next->data))
			{
				swap_values(temp, temp->next);
				continuer = 1;
			}
			temp = temp->next;
		}
		temp = lst;
	}
	return (lst);
}
