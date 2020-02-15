/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:38:37 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/01/13 17:47:47 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"



int	ft_putstr1(char *s)
{
	int i;

    i = 0;

    while (s[i])
    {
        ft_putchar(s[i++]);
    }
	return(i);
}

/*int	ft_putstr2(char *s,int a)
{
	int i;
	int b;
    i = 0;
	b = a - strlen(s);
	if (a > 0) 
		while (b--)
			ft_putchar(' ');

    while (s[i])
    {
        ft_putchar(s[i++]);
    }
	return(i);
}
*/

/*
int		ft_itoa1(unsigned int n)
{
	char	*str;
	long	m;
	int		i;
	int		f;
    int     lens;

	m = (long)n;
	i = len(m);
    lens = len(m);
	f = 0;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	if (m < 0)
	{
		f = 1;
		str[0] = '-';
		m = m * (-1);
	}
	while (i-- > f)
	{
		str[i] = 48 + (m % 10);
		m = m / 10;
	}
    ft_putstr(str);
    free(str);
	return (lens);
}
*/





