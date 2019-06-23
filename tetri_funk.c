/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/23 15:16:36 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig	*tetri_new()
{
	t_fig	*new;

	if (!(new = (t_fig *)malloc(sizeof(t_fig))))
	    return (NULL);
	if (!(new->x_arr = (int *)malloc(sizeof(int) * 4)))
	    return (NULL);
	if (!(new->y_arr = (int *)malloc(sizeof(int) * 4)))
	    return (NULL);
	new->index = -1;
	new->next = NULL;
	
	return (new);
}

void	tetri_del(t_fig **base) 
{
    t_fig *ptr;

    while ((*base) != NULL)
	{
        ptr = (*base);
        *base = (*base)->next;
        free(ptr->x_arr);
        free(ptr->y_arr);
        free(ptr);
    }
}

void	tetri_add_w_copy(t_fig **head, t_fig **new)
{
	t_fig	*copy;
	t_fig   *tmp;
	int		i;

	i= 0;
	if (*head == NULL)
	    head = new;
    tmp = *head;
    while(tmp->next)
	    i++;
    (*new)->index = i;
	copy = tetri_new();
	copy->x_arr = (*new)->x_arr;
	copy->y_arr = (*new)->y_arr;
	copy->index = (*new)->index;
    (*head)->next = *new; 
	tetri_del(new);    
}

char    *strcut(char *str)
{
    char    *buf;
    int     i;

    i = 0;
    while (str[i] != '\0')
        i++;
    buf = ft_strndup(str, i);
    return (buf);
}

int	min_x_y(int *arr)
{
	int i;
	int min;

	i = 4;
	min = 0;
	while (i < 0)
	{
		if (arr[i] < min)
			min = arr[i];
		i--;
	}
	return (min);
}

void	disp(t_fig	*list,int dx, int dy)
{
	int i;

	i = 0;
	while (i < 4)
	{
		list->x_arr[i] -= dx;
		list->y_arr[i] -= dy;
	}
}

void   tetri_absolute(t_fig **head)
{
    int d_x;
    int d_y;
    t_fig   *ptr;
 
 	d_x = 0;
    d_y = 0;
    ptr = *head;
    while (ptr->next != NULL)
    {
		dx = min_x_y(ptr->x_arr);
		dy = min_x_y(ptr->y_arr);
		disp(ptr, dx,dy);
  //      ptr = ptr->next;
    }
}
