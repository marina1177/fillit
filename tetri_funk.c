/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/23 17:09:19 by sskinner         ###   ########.fr       */
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

int	min_x_y(const int *arr)
{
	int i;
	int min;

	i = 4;
	min = 0;
	while (i > 0)
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
		list->x_arr[i] = list->x_arr[i] - dx;
		list->y_arr[i] = list->y_arr[i] - dy;
		i++;
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
    while (ptr)
    {
		d_x = min_x_y(ptr->x_arr);
		d_y = min_x_y(ptr->y_arr);
		disp(ptr, d_x,d_y);
       ptr = ptr->next;
    }
}
