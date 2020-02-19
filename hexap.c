/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:10:07 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/19 02:13:21 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*hexap(unsigned long long i)
{
	unsigned long long j;
	unsigned long long k;
	int len;
	char *s;
	//char a;

	k = 0;
	j = i;
	//a = (c == 'X') ? 'A' : 'a';
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
			s[len] = 'a' + (i % 16) % 10;
		else
			s[len] = i % 16 +'0';
		i = i/ 16;
		len--;
	}
	return(s);
}