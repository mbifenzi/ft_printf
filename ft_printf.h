#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int g_count;

typedef struct s_f
{
    int i;
    int width;
    int precision;
    int zero;
    int minus;
    int len;
    int no9ta;
    int preminus;

}              t_f;

void    ft_putchar(char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char    *ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int     ft_edit_flages(char *format);
int     ft_putstr1(char *s);
int     ft_isdigit(int c);
size_t  ft_strlen(const char *str);
int 	ft_putstr(char *s);
void	ft_edit_flags(char *format, t_f *f, va_list sick);
void    ft_execute_flags_d(t_f *f, char *s);
void    ft_execute_flags_s(t_f *f, char *s);
void    ft_execute_flags_x(t_f *f, char *s);
int		ft_atoi(char *str);
char 	*hexa1(unsigned int i);
char 	*hexa(unsigned int i);
int 	ft_printf(const char *format1, ...);
int		len(long n);
void    ft_width_d(t_f *f, int len, char *s);
void    ft_zero_d(t_f *f, int len);
void    ft_na9is_d(t_f *f,char *s, int len);
void    ft_precision_d(t_f *f,  char *s, int len);
void    ft_minus_d( t_f *f, char *s, int len);
void    ft_width_s( t_f *f, char *s  , int len);
void    ft_precision_s(t_f *f , char *s);
void    ft_minus_s(t_f *f, char *s);
void    ft_minus_x(t_f *f, char *s, int len);
void    ft_width_x( t_f *f ,char *s, int len);
void    ft_precision_x(t_f *f, char *s, int len);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
t_f	*ft_init_list(t_f *f);

#endif