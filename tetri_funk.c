/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:29:22 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/20 12:02:32 by bcharity         ###   ########.fr       */
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
    if (!(new->index = (int *)malloc(sizeof(int))))
        return (NULL);
	new->next = NULL;
//	new->prev = NULL;
	return (new);
}

/*int		tetri_del(t_fig **base, t_fig *del)  //возможно понадобится простое удаление листов
{
	t_fig	*ptr;
	t_fig	*buf;

	ptr = *base;
	if (*base && *base != del)
	{
		while (ptr && ptr->next != del)
			ptr = ptr->next;
		if (ptr)
		{
			buf = ptr->next;
			ptr->next = ptr->next->next;
			free(buf);
		}
		return (ptr) ? (0) : (-1);
	}
	else if (*base == del)
	{
		buf = *base;
		*base = (*base)->next;
		free(buf);
	}
	return (*base) ? (0) : (-1);
}*/

void	tetri_add(t_fig **base, t_fig *new)
{
	if (!(new))
		return ;
	new->next = *base;
	*base = new;
   // (*base)->prev = new;
}

void	tetri_add_w_copy(tetri **base, tetri *new, int index)
{
	tetri	*copy;

	if (!(new))
		return ;
	copy = tetri_new();
	*copy->x = *new->x;
	*copy->y = *new->y;
	copy->index = index;
	copy->next = *base;
	*base = copy;
    (*base)->previous = copy;
	free(new);
}

char    *strcut(char *str)
{
    char    *buf;
    int     i;

    i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
    buf = ft_strndup(str, i);
    return (buf);
}

void   tetri_absolute(tetri **base)   //чекоть
{
    int dimention_x;
    int dimention_y;
    int i;

    i = 0;
    while ((*base)->next != NULL)
    {
        dimention_x = (*base)->x[0];
        dimention_y = (*base)->y[0];
        while (i != 8)
        {
            (*base)->x[i] = (*base)->x[i] - dimention_x;
            (*base)->y[i] = (*base)->y[i] - dimention_y;
            i++;
        }
        *base = (*base)->next;
    }
}
