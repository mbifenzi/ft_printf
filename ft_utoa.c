/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:04:08 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/18 23:29:04 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		len(long n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}*/

char	*ft_utoa(unsigned int n)
{
	char	*str;
	unsigned int 	m;
	int		i;
	int		f;

	m = n;
	i = len(m);
	f = 0;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	
	while (i-- > f)
	{
		str[i] = '0' + (m % 10);
		m = m / 10;
	}
	return (str);
}