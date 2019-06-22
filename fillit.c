/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/22 14:32:25 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_fig	*tetri_build(t_fig **head, int index, int x, int y)
{
	t_fig  *tmp;
	
	tmp = *head;
	while (tmp)
	{
		if ((int)tmp->index == )
		{

			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

	if (*head == NULL)
	{
	    *head = tetri_new();
	}
	
	/*(*base)->x[index] = x;
	(*base)->y[index] = y;
	return (*base);*/
}

static t_fig   *detect_and_createtetri(char *str)
{
    int		x;
    int		y;
    int		index;
    int     k;
    t_fig   *head;
   // t_fig	*tetri;

    index = 0;
    x = 0;
    y = 0;
    k = 0;
    tetri = NULL;
    while (*str != '\0' && *(str - 1) != '\n')
    {
        while (*str != '\n')
        {
            if (*str == '#')
            {
                tetri = tetri_build(&head, index, x, y);
                index++;
            }
            str++;
            x++;
        }
        if (*str == '\n' && *(str + 1) == '\n')
        {
            tetri_add_w_copy(&head, tetri, k++);
            str++;
        }
        y++;
        str++;
        x = 0;
    }
    return (head);
}

int		reading(int fd)
{
	int		count;
	char	str[546];
//	char    *tmp;
	t_fig	*base_tetri;
	int		i;

	base_tetri = NULL;
	i = 0;
	while ((count = read(fd, str, 546)) <= 20)
    {
        str[count] = '\0';
        //tmp = strcut(str);  //?
        if (main_validate(str, ft_strlen(str) + 1) == -1)
            return (-1);
        base_tetri = detect_and_createtetri(str);
        /*while (base_tetri->x[i])
        {
            printf("%d\n", base_tetri->x[i]);
            i++;
        }
        i = 0;*/
		free(base_tetri);
		//free(tmp);
	}
    return (1);
}

