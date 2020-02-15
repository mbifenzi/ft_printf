/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_flags_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:18:29 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/12 00:02:57 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_execute_flags_s(t_f *f, char *s)
{
    int len;
    int bonus;
    int a;

    bonus = 0;
    a = f->precision;
    len = ft_strlen(s);
    
    if(!f->width && !f->precision && !f->minus && !f->no9ta)
    {
        ft_putstr(s);
    }
    if(f->minus == 1)
    {
        bonus = 1;
        ft_minus_s(f, s);
    }
    if (f->width)
    {
        ft_width_s(f, s, len);
    }
    if (f->no9ta && bonus == 0)
        ft_precision_s( f, s);
    
    
}

void    ft_minus_s(t_f *f, char *s)
{
    ft_precision_s(f, s);
    
}
void    ft_width_s( t_f *f ,char *s, int len)
{
    int a;
    int b;
    
    b = 0;
    a = f->width;
    if (!f->preminus)
    {
        if(!f->no9ta)
        {   
            if (f->width <= len && !f->minus)
            {
                    ft_putstr(s);
            }  
            if (f->width > len)
            {
                while (f->width > len)
                {
                    ft_putchar(' ');
                    f->width--;
                }
                if(!f->minus)
                    ft_putstr(s);
            }
        
        }
        if (f->no9ta)
        {   
            if(f->width && !f->precision)
            {
                while (f->width > 0)
                {
                    ft_putchar(' ');
                    f->width--;
                }
            }
            if(f->width >= len && f->precision)
            {
            if (f->width > f->precision)
                {
                    while (f->width > f->precision)
                    {
                        ft_putchar(' ');
                        f->width--;
                    }
                    while (f->precision > len && f->width)
                    {
                        ft_putchar(' ');
                        f->width--;
                    }
                }
                if (f->width < f->precision && f->precision > len)
                {
                    while (f->width > len)
                    {
                        ft_putchar(' ');
                        f->width--;
                    }
                }
            }
            if(f->width > len && !f->precision)
            {
                while (f->width > 0)
                {
                    ft_putchar(' ');
                    f->width--;
                }
            }
            if(f->width < len && f->precision < f->width)
            {
                while (f->width < len && f->precision < f->width)
                {
                    ft_putchar(' ');
                    f->width--;
                }
            }
        }
    }
    if(f->preminus == 1)
    {
        b = 1;
        while (f->width > len)
        {
            ft_putchar(' ');
            f->width--;
        }
        if(b == 0)
            ft_putstr(s);
    }
}

void    ft_precision_s(t_f *f, char *s)
{
    int a;

    a = f->precision;
    if(f->minus)
    {
        if(f->no9ta && !f->precision)
            f->precision = a;
        if(f->precision)
        {
            if(f->precision < (int)len)
            {
                while (f->precision > 0 && *s != '\0')
                {
                    ft_putchar(*s);
                    s++;
                    f->precision--;
                }
            }
            if(f->precision > (int)len)
            {
                while (f->precision > (int)len)
                {
                    ft_putchar(*s);
                    s++;
                    f->precision--;
                }
            }    
            f->precision = a;
        }
        if(!f->no9ta)
        {
            ft_putstr(s);
        }
    }
        if(!f->minus)
        {
            if(f->precision)
            {
                while (f->precision > 0 && *s != '\0')
                {
                    ft_putchar(*s);
                    s++;
                    f->precision--;
                }
            }
            f->precision = a;
        }
        if(f->preminus)
            ft_putstr(s);
    f->precision = a;
}
