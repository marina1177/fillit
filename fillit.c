/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:41:20 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/23 14:17:55 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void tetri_build(t_fig **head, int *tetri, int i, int x, int y)
{

    tetri[i] = x;
    tetri[i + 4]= y;

    if (i == 3)
        tetri_add_w_copy(head, tetri);
}

t_fig   *detect_and_createtetri(char *str)
{
    int		x;
    int		y;
    int		i;
    t_fig   *head;
    int     tetri[9];

    i = 0;
    y = 0;
    head = NULL;
    while (*str != '\0')
    {
        x = 0;
        while (!(*str == '\n' && *(str + 1) == '\n') &&
        !(*str == '\n' && *(str + 1) == '\0'))
        {
            if (*str == '#')
            {
                tetri_build(&head, tetri, i, x, y);
                i++;
            }
            str++;
            x++;
        }
        y++;
        str++;
    }
    return (head);
}

char	*reading(int fd)
{
	char	str[546];
	char    *tmp;
    int     count;

	tmp = NULL;
	while ((count =read(fd, str, 546)) >= 20)
	{
	    str[count] = '\0';
        printf("str_before_strcat_%s",str);
        tmp = strcut(str);
        printf("str_after_strcat_%s",tmp);
    }
    return (tmp);
}

