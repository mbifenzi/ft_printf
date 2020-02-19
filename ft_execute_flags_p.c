/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_flags_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:40:05 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/19 18:39:19 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_execute_flags_p(t_f *f, char *s)
{ //printf("%d", f->preminus);
    int len;
    int bonus;

    bonus = 0;
    f->precision = 0;
    f->no9ta = 0;
    len = ft_strlen(s);
    if (f->width >= 2)
    {
        f->width -= 2;
    }
    if (f->width < 2)
        f->width = 0;
    if(!f->precision && !f->width && !f->no9ta && !f->minus)
    {
        ft_putstr("x0");
        ft_putstr(s);
    }
    if(f->minus == 1 && !f->width)
    {
        bonus = 1;
        
        ft_width_p(f, s, len);
    }
    if (f->width)
    {
        ft_width_p(f, s, len);
    }
}



void    ft_width_p( t_f *f ,char *s, int len)
{
    if (f->minus)
    {
        ft_putstr("0x");
        ft_putstr(s);
        while (f->width > len)
        {
            ft_putchar(' ');
        }
    }
    else
    {
        while (f->width > len)
        {
            ft_putchar(' ');
            f->width--;
        }
        ft_putstr("x0");
        ft_putstr(s);
    }
}