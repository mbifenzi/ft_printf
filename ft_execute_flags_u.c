/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_flags_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:15:24 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/19 00:00:00 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_execute_flags_u(t_f *f, char *s)
{ //printf("%d", f->preminus);
    int len;
    int bonus;
    int a;

    bonus = 0;
    a = f->precision;
    len = ft_strlen(s);
    if(!f->precision && !f->width && !f->no9ta && !f->minus)
        ft_putstr(s);
    if (f->no9ta && !f->precision && *s == '0')
    {   if (f->width)
            *s = ' ';
        else
        {
            *s = 0;
        }
        
    }
    if(f->minus == 1)
    {
        bonus = 1;
        
        ft_minus_u(f, s, len);
    }
    if (f->width)
    {
        ft_width_u(f, s, len);
    }
    if (f->no9ta && bonus == 0)
        ft_precision_u( f,  s, len);
}

void    ft_minus_u(t_f *f, char *s, int len)
{
    ft_precision_i(f,  s, len);
}

void    ft_width_u( t_f *f ,char *s, int len)
{
    int a;
    a = f->width;
    if(f->width > len && !f->zero)
    {
        /*printf("%d-%d", f->width, f->precision);*/
        while (f->width > f->precision && f->width > len)
        {
            ft_putchar(' ');
            f->width--;
        }
    }
    else if (f->width > len && f->zero)
    {
        while (f->width > f->precision && f->width > len)
        {
            if (!f->no9ta)
            {
            ft_putchar('0');
            f->width--;
            }
            if (f->no9ta)
            {
                ft_putchar(' ');
                f->width--;
            }
        }
    }
    else
    {
        while (f->width > len && f->width > f->precision)
        {       
                ft_putchar('0');
                f->width--;
        }
    }
    if(!f->no9ta && !f->minus)
        ft_putstr(s);
}

void    ft_precision_u(t_f *f, char *s, int len)
{
    int a;

    a = f->precision;
    while (f->precision > len)
    {
        ft_putchar('0');
        f->precision--;
    }
    while (f->precision <= len && *s)
    {
        ft_putchar(*s);
        s++;
    }
    f->precision = a;
}
