/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/03 16:22:04 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*int main ()
{
    char **map;
    int n =2;
    char     *line;
    int         fd;
    int         ret;
    char        *filename;
    char        buf[BUFF_SIZE + 1];
    char        *tmp;

    t_fig       *head;
    t_fig       *node;
    int         i = 0;
    int x1[4] =  {4 ,4, 4, 4};
    int x2[4] =  {3 ,2, 3, 4};
    int x3[4] =  {1 ,1, 2, 3};

    int y1[4] = {1,2,3,4};
    int y2[4] = {1,2,2,2};
    int y3[4] = {2,3,3,3};

    int index1 = 1;
    int index2 = 2;
    int index3 = 3;


     filename = "tetri.txt";
    fd = open(filename, O_RDONLY);
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        //ft_putstr(buf);
    }
    printf ("buf: %s\n", buf);//считала файл в буфер
    close(fd);*/

  /*printf ("min_edge: %d\n", min_edge(n));
   // min_edge(n);
  if(create_map(n))
  {
      printf("end");
  }*/


int fill_map(int a, t_fig *fig, char **map)
{
    int dx;
    int dy;
    int *x;
    int *y;

    x = fig->x_arr;
    y = fig->y_arr;
    dy = a;
    while (dy >= 0)
    {
        dx = 0;
        while (dx <= a)
        {
            if (check_availible(x,y,dx,dy,map))// проверка, все ли места карты, соответствующие данному смещению и координатам фигуры свободны
            {
                to_map(map);
                if(fill_map (a, t_fig++, map))
                    return (1);
            }
            else
                dx++;
        }
        dy++;
    }// найти место для фигуры не удалось
     if (t_fig->index == 1)
         return(-1);//fill_map(a++, fig, map));
     else
         return(0);//fill_map(a, fig->prev, char *map))

}


int     min_edge(int n)
{
    int a;

    a = 0;
    while (a * a < 4*n)
    {
        a++;
    }
    return (a);
}

char **create_map (t_fig *list,a)
{
    int a;
    char **map;
    int f;

   //начало функции с которой а++
    map = zero_map(a);// выделяю память и заполняю двумерный масссив точками;
    f = fill_map(a, list, map);
    if (f == 1)
        return (map);
    else if (f == 0)
    {
        return();
    }
}

int main() {
    t_fig *list;
    char **map;
    int a;

    list = create_list();
    a = min_edge(n);
    map = create_map()
    print_map(map);


}









}

static int check_availible(int a, int *x[4], int *y[4], int dx0, int dy0)
{
    int *dx[4];
    int *dy[4];
    int i;

    i = 0;
    while(i < 4)
    {
        dx[i] = x[i] - dx0;
        dy[i] = y[i] - dy0;
        i++;
    }

}
void    print_field(int a)
{
    int     i;
    int     j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            ft_putnbr(sudoku_field[i][j]);
            if (j < 8)
                ft_putchar(' ');
            j++;
        }
        ft_putchar(10);
        i++;
    }
}
