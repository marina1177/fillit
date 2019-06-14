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

static  t_fig *create_list(int a)
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
    head->y_arr[0] = a;
    head->y_arr[1] = a-1;
    head->y_arr[2] = a-2;
    head->y_arr[3] = a-3;  
  
    head->next = second;

    second->index =2;
    second->x_arr[0] = 2;
    second->x_arr[1] = 1;
    second->x_arr[2] = 2;
    second->x_arr[3] = 3;
    second->y_arr[0] = a;
    second->y_arr[1] = a-1;
    second->y_arr[2] = a-1;
    second->y_arr[3] = a-1;

    second->next = third;

    third->index = 3;
    third->x_arr[0] = 0;
    third->x_arr[1] = 0;
    third->x_arr[2] = 1;
    third->x_arr[3] = 2;
    third->y_arr[0] = a-1;
    third->y_arr[1] = a-2;
    third->y_arr[2] = a-2;
    third->y_arr[3] = a-2;
   
    third->next = NULL;
    return(head);
}
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
 
int check_availible(int *x,int *y, int dx,int dy, char **map)
{
    int i;
    
        i = 0;
        while(i < 4)
        {
            if(map[x[i]+dx][y[i]+dy] == '.')
            {
                printf("");
                i++;
            }
            else
                return(0);
            
        }
        return (1);
}


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
            if (check_availible(x,y,dx,dy,map,a))// проверка, все ли места карты, соответствующие данному смещению и координатам фигуры свободны
            {
                //to_map(map);
                printf("OK");
               // if(fill_map (a, t_fig++, map))
               //    return (1);
            }
            else
                dx++;
        }
        dy--b  ;
    }// найти место для фигуры не удалось
     if (t_fig->index == 1)
         return(-1);//fill_map(a++, fig, map));
     else
         return(0);//fill_map(a, fig->prev, char *map))

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
    //char    **map;

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

 char **create_map (t_fig *list,int a)
{
    char **map;
    int f;
    
   //начало функции с которой а++
    map = zero_map(a);// 
    f = fill_map(a, list, map);
    if (f == 1)
        return (map);
    else if (f == 0)
    {
        return(create_map(t_fig *list, a+1));
    }
    return(map);
}




int main()
 {
    t_fig *list;
    char **map;
    int a;
    int n = 3;
    int i;
    int j;
   
    printf("n = %d\n",n);
    a = min_edge(n);
    printf("a = %d\n",a);
    list = create_list(a);
    map = create_map(list, a);

    j = 0;
    while (map[j])
    {
       printf("_%s",map[j]);
       printf("\n");   
        j++;     
    }
    

 
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
    
  


}


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
