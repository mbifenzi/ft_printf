/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:07:58 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/01/13 17:43:52 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

char 	*hexa1(unsigned int i)
{
	int j;
	int k;
	int len;
	char *s;

	k = 0;
	j = i;
	len = 0;
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
			s[len] = 65 + i % 16 - 10;
		else
			s[len] = i % 16 +'0';
		i = i/ 16;
		len--;
	}
	return(s);
}
