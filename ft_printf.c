/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:47:54 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/15 21:50:22 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

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
void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

 t_f	*ft_init_list(t_f *f)
{
	if (!(f = (t_f *)ft_memalloc(sizeof(t_f))))
		return (NULL);
	f->i = 0;
	f->len = 0;
	f->precision = 0;
	f->width = 0;
	f->minus = 0;
	return (f);
}
int 	ft_printf(const char *format1, ...)
{
	char *s;
	char *format;
	
	format = (char *)format1;
	t_f *f;
	f = NULL;
	if (!(f = ft_init_list(f)))
		return (-1);
    va_list sick;
    va_start(sick,format1);
	f->i = 0;
	f->width = 0;
	f->minus = 0;
	f->precision = 0;
	f->preminus = 0;
	g_count = 0;
    while (format[f->i] != '\0')
    {
         if(format[f->i] == '%')
        {
			f->i++;
			if(ft_strchr("-*.0123456789", format[f->i]))
				{
					
					ft_edit_flags(format, f, sick);
				}
			if(ft_strchr("%cspdiuxX", format[f->i]))
			{
				if (format[f->i] == 'd')
            	{
					s = ft_itoa(va_arg(sick, int));
					if(f->width || f->precision || f->minus)
						ft_execute_flags_d(f, s);
					else
					{
						if(*s == '0' && f->no9ta && !f->precision && f->zero);
						else
							ft_putstr(s);
					}
					f->i++;
				}
				if (format[f->i] == 's')
				{
					s = va_arg(sick, char *);
					if(s == NULL)
					{
        				 s = "(null)";
					}
					//printf("%s\n", s);
					ft_execute_flags_s(f,s);
					f->i++;
				}
				if (format[f->i] == 'x')
				{
					s = hexa(va_arg(sick, int));
					ft_execute_flags_x(f, s);
					f->i++;
				}
			}
            
		}
		
        /*
			if (format[i]== 's')
			{
				a = ft_putstr2(va_arg(sick, char *));
				i++;
			}
        	if (format[i] == 'x')
			{
				  a = hexa(va_arg(sick, unsigned int));
				  i++;
			}
			if (format[i] == 'X')
			{
				a = HEXA(va_arg(sick, unsigned int));
				i++;
			}
			if (format[i] == 'c')
			{
				ft_putchar(va_arg(sick, int));
				a++;
				i++;
			}
			if (format[i] == 'u')
            {
				a += ft_itoa1(va_arg(sick, int));
				i++;
			}
			if (format[i] == '%')
			{
				ft_putchar('%');
				a++;
				i++;
			}
			if (format[i] == 'p')
			{
				a += ft_putstr1("0x");
				hexa(va_arg(sick, long long));
				a++;
				i++;
			}
		}
		*/
		if (format[f->i])
		{
			ft_putchar(format[f->i]);
			f->i++;
		}
    }
	return(g_count);
}
void	f(char *s)
{
	int i;
	int a;
	a = 0;
	i = 0;

	while (s[i])
	{
		if (s[i] == 'O')
			a++;
		i++;
	}
	printf("%d",a);
}
/*
int main()
{
	
	ft_printf("%10.7d.\n", -100);

	//ft_printf("%d\n", ft_printf("%02.7d", 100));
	printf("%10.7d", -100);
	//printf("%d" , printf("%-2s", "simo"));
}*/