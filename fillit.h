/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:58 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/03 16:13:53 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
//# include <sys/uio.h>
//# include <unistd.h>
# include <io.h>
# include <stdlib.h>
# include "./libft/libft.h"

//# define BUFF_SIZE 1
# define TETRI 26

typedef struct s_figure   t_fig;

struct      s_figure
{
    int     *x_arr;
    int     *y_arr;
    int     index;
    t_fig   *next;
    //t_fig   *prev;
};

char **create_map (t_fig *list,int a);
char **zero_map(int a);
int fill_map(int a, t_fig *fig, char **map);
int check_availible(int *x,int *y, int dx,int dy, char **map);
//int min_edge(int n);
//char   **create_map(int n);
//int availible();

#endif