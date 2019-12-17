/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:47:54 by mbifenzi          #+#    #+#             */
/*   Updated: 2019/12/17 20:44:47 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c){
    write(1,&c,1);
}
void    ft_putstr(char *s)
{
    int i;
    i = 0;
	if (!s)
		ft_putstr("(null)");
	else 
    	while (s[i])
    	{
        	ft_putchar(s[i++]);
    	}
}
int	ft_putstr1(char *s)
{
	int i;
    i = 0;
    while (s[i])
    {
        ft_putchar(s[i++]);
    }
	return(i);
}

int 	hexa(unsigned int i)
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
			s[len] = 97 + i % 16 - 10;
		else
			s[len] = i % 16 +'0';
		i = i/ 16;
		len--;
	}
	k = ft_putstr1(s);
	free(s);
	return(k);
}

int 	HEXA(unsigned int i)
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
	k = ft_putstr1(s);
	free(s);
	return(k);
}
static int		len(long n)
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
}


int			ft_itoa(int n)
{
	char	*str;
	long	m;
	int		i;
	int		f;
    int     lens;

	m = (long)n;
	i = len(m);
    lens = len(m);
	f = 0;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	if (m < 0)
	{
		f = 1;
		str[0] = '-';
		m = m * (-1);
	}
	while (i-- > f)
	{
		str[i] = 48 + (m % 10);
		m = m / 10;
	}
    ft_putstr(str);
    free(str);
	return (lens);
}


int ft_printf(const char *format, ...)
{
    int i;
    i = 0;
	int a;
	a = 0;
    va_list sick;
    va_start(sick,format);
    while (format[i] != '\0')
    {
        if(format[i] == '%')
        {  
			i++;
            if (format[i] == 'd')
            {
				a += ft_itoa(va_arg(sick, int));
				i++;
			}
        
			if (format[i]== 's')
			{
				a += ft_putstr1(va_arg(sick, char *));
				i++;
			}
        	if (format[i] == 'x')
			{
				  a += hexa(va_arg(sick, unsigned int));
				  i++;
			}
			if (format[i] == 'X')
			{
				a += HEXA(va_arg(sick, unsigned int));
				i++;
			}
		}
	

		if (format[i])
		{
			ft_putchar(format[i]);
			a++;
			i++;
		}
    }
    return (a);
}
int main()
{
	//hexa(123);
 ft_printf("%X", 123);
  return 0;
} 

