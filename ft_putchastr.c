/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchastr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:09:42 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/10 00:33:39 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

void    ft_putchar(char c)
{
    write(1,&c,1);
	g_count++;

}
int    ft_putstr(char *s)
{
    int i;
    i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		i = 6;
	}
	else 
    	while (s[i])
    	{
        	ft_putchar(s[i++]);
    	}
	return (i);
}