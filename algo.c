/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/20 12:02:51 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*istatic  t_fig *create_list(int a)
{
    t_fig *head = NULL;
    t_fig* second = NULL;
    t_fig* third = NULL;
 
    head   = (t_fig*)malloc(sizeof(t_fig));
    second = malloc(sizeof(t_fig));
    third  = malloc(sizeof(t_fig));
 
// инициализировать элементы списка и связать их между собой
    head->x_arr = (int*)malloc(sizeof(int) * 4);
    head->y_arr = (int*)malloc(sizeof(int) * 4);
    second->x_arr = (int*)malloc(sizeof(int) * 4);
    second->y_arr = (int*)malloc(sizeof(int) * 4);
    third->x_arr = (int*)malloc(sizeof(int) * 4);
    third->y_arr = (int*)malloc(sizeof(int) * 4);

    head->index = 1;
  //  ((int)head->x_arr) = {0,0,0,0};
    head->x_arr[0] = 0;
    head->x_arr[1] = 0;
    head->x_arr[2] = 0;
    head->x_arr[3] = 0;
    head->y_arr[0] = 0;
    head->y_arr[1] = 1;
    head->y_arr[2] = 2;
    head->y_arr[3] = 3;
  
   head->next = third;
    head->prev = NULL;

    second->index =2;

  /*  second->x_arr[0] = 1;
    second->x_arr[1] = 0;
    second->x_arr[2] = 1;
    second->x_arr[3] = 2;
    second->y_arr[0] = 0;
    second->y_arr[1] = 1;
    second->y_arr[2] = 1;
    second->y_arr[3] = 1;*/

  /* second->x_arr[0] = 0;
    second->x_arr[1] = 1;
    second->x_arr[2] = 2;
    second->x_arr[3] = 3;
    second->y_arr[0] = 0;
    second->y_arr[1] = 0;
    second->y_arr[2] = 0;
    second->y_arr[3] = 0;

    third->next = second;
    third->prev = head;

    third->index = 3;
    third->x_arr[0] = 0;
    third->x_arr[1] = 0;
    third->x_arr[2] = 1;
    third->x_arr[3] = 2;
    third->y_arr[0] = 0;
    third->y_arr[1] = 1;
    third->y_arr[2] = 1;
    third->y_arr[3] = 1;
   
    second->next = NULL;
    second->prev = third;
    return(head);
}*/

int check_avail(int *x,int *y, int dx,int dy, char **map)
{
    int i;
    int nx;
    int ny;
   // int j = 0;
    
        i = 0;
        while(i < 4)
        {
           nx = x[i]+dx;
           ny = y[i]+dy;
           printf("nx = %d___ny = %d\n", nx,ny);
           printf("map= %c\n",map[ny][nx]);
           if(map[ny][nx] == '.')
            {
               printf("check_%c\n",map[ny][nx]);
                i++;
            }
            else
                return(0);
        }
        return (1);
}

void    to_map(t_fig *list, int dx, int dy, char **map)
{
    int *x;
    int *y;
    int i;
    char c;

    i = 0;
    x = list->x_arr;
    y = list->y_arr;
    c = list->index + 64;
    printf("c_%c\n", c);
    while(i < 4)
    {
        map[y[i]+dy][x[i]+dx] = c;
      //  printf("to_map_c_%c\n",map[y[i]-dy-1][x[i]+dx]);
        i++;
    }
}

void    clear(t_fig *list, int dx, int dy, char **map)
{
    int *x;
    int *y;
    int i;
    char c;

    i = 0;
    x = list->x_arr;
    y = list->y_arr;
    c = list->index + 64;
    printf("c_%c\n", c);
    while(i < 4)
    {
        map[y[i]-dy-1][x[i]+dx] = '.';
        //  printf("to_map_c_%c\n",map[y[i]-dy-1][x[i]+dx]);
        i++;
    }

}

 int fill_map(int a, t_fig *list, char **map)
{
    int dx;
    int dy;
    int *x;
    int *y;

    int j = 0;
        x = list->x_arr;
        y = list->y_arr;
        dy = 0;
        while (dy < a)
         {
            dx = 0;
            while (dx < a)
            {
                 if (check_avail(x,y,dx,dy,map))// проверка, все ли места карты, соответствующие данному смещению и координатам фигуры свободны
                 {
                     printf("DX_1=%d__DY_1=%d\n", dx,dy);
                     to_map(list, dx, dy,map);
                     printf("OK\n");
                     if(list->next == NULL || fill_map (a, list->next, map))
                     {
                         return (1);
                     }

                 }
                   // printf("DX_2=%d__DY_2=%d\n", dx,dy);
                    dx++;
            }
            dy++ ;
         }// найти место для фигуры не удалось
     if (list->index == 1)
         return(-1);//    просто очистить и увеличить карту      fill_map(a++, fig, map));
     else
         return(0);//  переставить предыдущий элемент     fill_map(a, fig->prev, char *map))

}


static int     min_edge(int n)
{
    int a;

    a = 0;
    while (a * a < 4*n)
    {
        a++;
    }
    return (a);
}

char **zero_map(int a)
{
    int i;
    int j;
    char    **map;

     j = 0;
    map = (char**)malloc((a+1)*sizeof(char*));
   
    while(j < a+1)
    {
        map[j] = (char*)malloc((a+1)*sizeof(char));
        j++;
    }

         j = 0;
    while(j < a)
    {
        i = 0;
        while(i < a)
        {
            map[i][j] = '.';
            i++;
        }
        map[a][j] = '\0';
        j++;
    }
    map[a] = NULL;
    return(map);
}

char *free_map(char **map)
{
    int i;

    i = ft_strlen(map[0]) ;
    while(i +1 > 0)
    {
        free(map[i]);
        i--;
    }
    free(map);
    return(NULL);
}

 char **create_map (t_fig *list,int a)
{
    char **map;
    int f;
    int j = 0;

    map = zero_map(a);



    f = fill_map(a, list, map);
    if (f == 1)
        return (map);
    else if (f == -1)
    {
        printf("NEED_a++\n");
        free_map(map);
        return(create_map(list, a+1));
    }
    return(map);
}


void    print_map(char **map)
{
      int j;

      j = 0;
      while(map[j])
      {
          ft_putstr(map[j]);
          ft_putchar('\n');
          j++;
      }
}

int main()
{
    t_fig *list;
    char **map;
    int a;
    int n = 3;
    int i;
    int j;
    int fd;

    fd = open("tetri.txt", O_RDONLY);
    reading(fd);
    // printf("n = %d\n",n);
    a = min_edge(n);
    // printf("a = %d\n",a);
    list = create_list(a);
    map = create_map(list, a);

    j = 0;
   print_map(map);
   free_map(map);

}
     /* while (j< a)
        {
            printf("zero_%s",map[j]);
            printf("\n");
            j++;
        }*/


  /* while(list != NULL)
    {
         printf("INDEX = %d\n",list->index);
        i = 0;
        while(i <4)
        {
            printf("x_arr1 = %d\n",((int*)list->x_arr)[i]);
            i++;
        }
        i = 0;
        while(i <4)
        {
        printf("y_arr1 = %d\n",((int*)list->y_arr)[i]);
        i++;
        }
        printf("\n");
        list = list->next;
    }*/
    
  




/*
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
}*/
