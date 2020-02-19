/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:20:09 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/17 23:07:51 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

void	ft_flags(char *format, t_f *f)
{
	while (ft_strchr("-0",format[f->i]))
	{
		if (format [f->i]== '0')
			f->zero = 1;
		if (format[f->i] ==  '-')
			f->minus = 1;
		f->i++;
	}

}

void    ft_width(char *format, t_f *f,va_list sick)
{
    if(ft_isdigit(format[f->i]))
	{
		f->width = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
			f->i++;
	}
	else if(format[f->i] == '*')
	{
		
		f->width = va_arg(sick, int);
		if (f->minus == 0)
			f->minus = (f->width < 0) ? 1 : 0;
		if (f->width < 0)
		{
			f->width = -f->width;
			f->zero = 0;
			f->i++;
		}
		else
		{
			f->width = f->width;
			f->i++;
		}
		
		/*f->width = (f->width < 0) ? -f->width : f->width;
			f->zero = 0;
			f->i++;*/
	}
}

void	ft_precision(char *format, t_f *f, va_list sick)
{
	char *s;
	if (format[f->i] == '.')
	{
			f->no9ta = 1;
			f->i++;
		if (format[f->i] == '-')
		{	
			f->preminus = 1;
			f->i++;
		}
		if(ft_isdigit(format[f->i]))
		{
			f->precision = ft_atoi(&format[f->i]);
			f->precision = (f->preminus == 1) ? -f->precision : f->precision;
			while (ft_isdigit(format[f->i]))
			f->i++;
		}
		else if(format[f->i] == '*')
		{
			f->precision = va_arg(sick, int);
			s = ft_itoa(f->precision);
			if(s[0] == '-')
			{
				f->preminus = 1;
			}
			f->i++;
		}
	}
}

void	ft_edit_flags(char *format, t_f *f, va_list sick)
{
	ft_flags(format, f);
	ft_width(format, f,sick);
	ft_precision(format, f, sick);
}
