/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:58 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/23 17:09:27 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
//# include <io.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

//# define BUFF_SIZE 1

typedef struct s_figure   t_fig;

struct      s_figure
{
    int     *x_arr;
    int     *y_arr;
    int     index;
    t_fig   *next;
 //   t_fig   *prev;
};
//PART2
char    **create_map (t_fig *list,int a);
char    **zero_map(int a);
int     fill_map(int a, t_fig *fig, char **map);
int     check_avail(int *x,int *y, int dx,int dy, char **map);
void    to_map(t_fig *list, int dx, int dy, char **map);
char    *free_map(char **map);
void    print_map(char **map);
void    clear(t_fig *list,int dx, int dy, char **map);
//int min_edge(int n);
//char   **create_map(int n);
//int availible();

//PART1
char	*reading(int fd);
t_fig	*tetri_new();
t_fig	*new_list(t_fig **head,int l);
void	tetri_del(t_fig **base);
void    tetri_absolute(t_fig **head);
t_fig   *main_validate(char *str, int count);
t_fig   *create_list(int *st, t_fig **head, int l);
void    disp (t_fig *list,int dx, int dy);
int     min_x_y(const int *arr);
char    *strcut(char *str);

#endif
