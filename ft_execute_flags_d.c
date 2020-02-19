/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_flags_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:35:48 by mbifenzi          #+#    #+#             */
/*   Updated: 2020/02/17 23:09:19 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


 
void    ft_execute_flags_d(t_f *f, char *s)
{
    int len;
    int i;

    i = 0;
    
    len = ft_strlen(s);
    if (*s == '-')
    {    
        if (f->preminus)
    {
        f->precision = 0;
        f->no9ta = 0;
    }
        //printf("sss");
        
        i = 1;
        ft_na9is_d(f,s, len);
    }
    if (*s == '0')
    {
        if (f->preminus)
    {
        f->precision = 0;
        f->no9ta = 0;
    }
        i = 1;
        ft_zero_d(f, len);
    }
    if (f->preminus)
    {
        f->precision = 0;
        f->no9ta = 0;
    }
    if (f->minus == 1 && *s != '0' && i != 1)
    { 
        if (f->no9ta && !f->precision)
        {
            f->no9ta = 0;
            f->precision = 0;
        }
        ft_minus_d(f, s, len);
    }
    if (!f->width && !f->minus && *s != '0' && i != 1)
    { 
        if (f->precision)
            ft_precision_d(f,s,len);
        else
        {
            ft_putstr(s);
        }
        
    }
    if (f->width && !f->minus && *s != '0' && i != 1)
    {
        if (f->preminus)
        {
            f->no9ta = 0;
            f->precision = 0;
        }
        ft_width_d(f, len, s);
    }
    if (f->width && f->precision && !f->minus && *s != '0' && i != 1)
    {
        ft_precision_d( f,  s, len);
    }
    
}
void    ft_na9is_d(t_f *f,char *s, int len)
{
    //if(f->precision || f->width || !f->prec)
    //{
    if(f->zero)
    {
        if (!f->no9ta)
        {
            ft_putchar('-');
            s++;
            len--;
            if (f->width)
                f->width--;
            while (f->width > len)
            {
                ft_putchar('0');
                f->width--;
            }
        }
        if (f->no9ta)
        {
            if (f->width > len && f->width > f->precision)
            {
                if (f->precision)
                    f->width--;
                while (f->width > len && f->width > f->precision)
                {
                    ft_putchar(' ');
                    f->width--;
                }
            }
            //ft_putchar('s');
            ft_putchar(*s);
            s++;
            len--;
        }
        while (f->precision > len)
        {
            ft_putchar('0');
            f->precision--;
        }
        ft_putstr(s);

    }
    if (f->minus)
    {
        ft_putchar('-');
        s++;
        len--;
        if (f->width)
            f->width--;
        if (f->precision)
        {
            while (f->precision > len)
            {
                ft_putchar('0');
                f->precision--;
                if (f->width)
                    f->width--;
            }
        }
        {
        ft_putstr(s);
        while (f->width > len)
        {
                ft_putchar(' ');
                f->width--;
            }
        }
    }
    else if (!(f->minus || f->zero))
    {
            while (f->width > len && f->width > f->precision + 1)
            {
                
                ft_putchar(' ');
                f->width--;
            }
            ft_putchar('-');
            s++;
            while (f->precision >= len)
            {
                //printf("s");
                ft_putchar('0');
                f->precision--;
            }
            ft_putstr(s);
        
    }  
//}
}

void    ft_zero_d(t_f *f, int len)
{
    int i;

    i = 0;
    if(f->no9ta && !f->precision)
    {
        i = 1;
        while (f->width)
        {
            ft_putchar(' ');
            f->width--;
        }
    }
    if ((f->zero || f->minus) && !(f->no9ta && !f->precision))
    {
        if(f->zero)
        {
            if (f->precision || f->width)
            {
                if (f->precision)
                {
                    while (f->width > len && f->width > f->precision)
                    {
                        ft_putchar(' ');
                        f->width--;
                    }
                    while (f->precision > len)
                    {
                        ft_putchar('0');
                        f->precision--;
                    }
                }
                if (f->width && !f->precision)
                {
                while (f->width > len)
                { 
                    ft_putchar('0');
                    if (f->width)
                        f->width--;
                }
                }
                
            }        
        
            if (!i)
            {
                ft_putchar ('0');
            }
        }
    }
        if (f->minus)
        {
            if (!(f->no9ta && !f->precision))
            {
                ft_putchar('0');
            }
            while (f->precision > len)
            {
                ft_putchar('0');
                f->precision--;
                if(f->width)
                    f->width--;
            }
            while (f->width > len)
            {
                ft_putchar(' ');
                f->width--;
            }
        }
        else if (!(f->zero || f->minus) && !(f->no9ta && !f->precision))
        {
            //printf("sss");
            while (f->width > f->precision && f->width > len)
            {
                ft_putchar(' ');
                f->width--;
            }
            while (f->precision > len)
            {
                ft_putchar('0');
                f->precision--;
            }
            ft_putchar('0');
        }
        
    }

void    ft_precision_d(t_f *f, char *s, int len)
{
    while (f->precision > len)
    {
        ft_putchar('0');
        f->precision--;
    }
    if (*s == '-')
        s++;
    ft_putstr(s);
}
void    ft_width_d(t_f *f, int len, char *s)
{
    if (f->zero)
    {
        while (f->width > len && f->width > f->precision)
        {
            if(!f->no9ta)
            {
                ft_putchar('0');
            }
            if(f->no9ta)
                ft_putchar(' ');
            f->width--;
        }
    }
    while (f->width > len && f->width > f->precision)
    {
        ft_putchar(' ');
        f->width--;
    }
    if(!f->precision)
    {
        ft_putstr(s);
    }
}
void    ft_minus_d(t_f *f, char *s, int len)
{
    //printf("ssss");
    if(!f->precision)
    {
        if(!f->width)
            ft_putstr(s);
        if(f->width >= len)
        {
           
            f->width -= len;
            ft_putstr(s);
            len = 0;
        }
        if (f->width < len)
        {   
            f->width = 0;
            ft_putstr(s);
        }
        while (f->width)
        {
            ft_putchar(' ');
            f->width--;
        }
    }
    if(f->precision)
    { 
        int j;
        j = len;
        while(f->precision > len)
            {
                ft_putchar('0');
                f->precision--;
                f->width--;
            }
        ft_putstr(s);
        if(f->width > len)
        {
        while (f->width)
            {
            ft_putchar(' ');
            f->width--;
            }
        }
    }
}
    
