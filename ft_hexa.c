/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:08:39 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/19 02:10:27 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

char 	*hexa(unsigned int i, char c)
{
	unsigned int j;
	unsigned int k;
	int len;
	char *s;
	char a;

	k = 0;
	j = i;
	a = (c == 'X') ? 'A' : 'a';
	len = 0;
	if (i == 0)
		len = 1;
	while (j > 0)
	{
		j = j / 16;
		len++;
	}
	if(!(s = malloc(sizeof(char) * (len + 1))))
		return(0);
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (i % 16 >= 10)
			s[len] = a + (i % 16) % 10;
		else
			s[len] = i % 16 +'0';
		i = i/ 16;
		len--;
	}
	return(s);
}
