/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:49:59 by sskinner          #+#    #+#             */
/*   Updated: 2019/06/15 18:12:48 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int validate_1(char *str)
{
    int y;
    int x;

    y = 0;
    while (!(*str == '\0' && *(str - 1) == '\n') &&
    !(*str == '\n' && *(str - 1) == '\n'))
    {
        x = 0;
        while (*str != '\n')
        {
            if ((*str != '.' && *str != '#') || x > 4)//НЕ(А+В)=НЕ(А)*НЕ(В)
            {
                    return (-1);
            }
            x++;
            str++;
        }
        if(x < 4)
            return(-1);
        y++;
        str++;
    }
    return (y == 4) ? (1) : (-1);
}

static  int getvid(int *stack, int i)
{
    int flag;
    int vis[8];
    int k;

    flag = 0;
    k = 0;
    vis[0] = stack[i] + 1;  //+x
    vis[1] = stack[i + 4]; //y
    vis[2] = stack[i];  //x
    vis[3] = stack[i + 4] + 1;  //+y
    vis[4] = stack[i] - 1;  //-x
    vis[5] = stack[i + 4];  //y
    vis[6] = stack[i];  //x
    vis[7] = stack[i + 4] - 1;  //-y
    while (k < 4)
    {
        if ((vis[0] == stack[k]) && (vis[1] == stack[k + 4]))
            flag++;
        if ((vis[2] == stack[k]) && (vis[3] == stack[k + 4]))
            flag++;
        if ((vis[4] == stack[k]) && (vis[5] == stack[k + 4]))
            flag++;
        if ((vis[6] == stack[k]) && (vis[7] == stack[k + 4]))
            flag++;
        k++;
    }
    return (flag);
}

static int validate_3(int *stack)
{
    int i;
    int k;
//    int j;

    i = 0;
    k = 0;
//    j = 0;
    while (i < 4)
    {
        k = k + getvid(stack, i);
        i++;
    }
//    printf("%d\n", k);
    if (k >= 6)
        return (0);
    return (-1);
}

static int validate_k(char *buf_str)
{


}

static int validate_2(char *str)
{
    int k;
    int x;
    int y;
    int stack[8];

    k = 0;
    y = 0;
    while (!(*str == '\0' && *(str - 1) == '\n') &&
    !(*str == '\n' && *(str- 1) == '\n'))
    {
        x = 0;
        while (*str != '\n')
        {
            if (*str == '#')
            {
         /*      if (k == 4)
                    return(-1);*/
                stack[k] = x;
                stack[k + 4] = y;
                k++;
            }
            x++;
            str++;
        }
        y++;
        str++;
    }
    return (validate_3(stack) == 0) ? (0) : (-1);
}

int     main_validate(char *str, int count) //отправлять на валидацию по 21 символу
{
    char   buf_str[21 + 1];
    int i;

    if (count % 21 != 0)
        return (-1);
    while (*(str-1) != '\0')
    {
        i = 0;
        while (i < 21)
        {
            buf_str[i] = *str;
            i++;
            str++;
        }
     //   if (buf_str[i - 1] != '\0')
        buf_str[i] = '\0';  //buf[21]='\0'(22-ой элемент = '\0')
        if (validate_1(buf_str) == -1)
            return (-1);
        if (validate_k(buf_str) == -1)
            return (-1);
        if (validate_2(buf_str) == -1)
            return (-1);
    }
    return (0);
}