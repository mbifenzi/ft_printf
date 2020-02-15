/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:23:29 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/01/19 23:59:54 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ft_printf.h"
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (n)
	{
		str = s;
		while (n > i + 1)
		{
			str[i] = 0;
			i++;
		}
		str[i] = '\0';
	}
}
static void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

static t_f	*ft_init_list(t_f *f)
{
	if (!(f = (t_f *)ft_memalloc(sizeof(t_f))))
		return (NULL);
	f->i = 0;
	f->len = 0;
	f->precision = 0;
	f->width = 0;
	f->minus = 0;
	return (f);
}*/