#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{	
	char		*str;
	char		zero;
	int			widht;
	int			prec;
	char		dot;
	int			conv;
	int			len_str;
	char		hyphen;
	va_list		args;
}				t_data;

int			get_n_spcs_f(t_data *f, long int a);
int			get_n_zeros(t_data *f, long int a);
int			get_n_spcs_b(t_data *f, long int a);
void		zero_exception_d(t_data *f, long int a);
void		mod_putstr(t_data *flags_conv, char *str);
int			ft_atoi(const char *str);
long int	ab_val(long int a);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
size_t		ft_strlen(const char *s);
int			int_len(long int n);
void		mod_putnbr(t_data *flags_conv, long int n);
void		mod_putchar(t_data *flags_conv, char c);
void		null_print_s(t_data *f, char *str, int *is_null, int *v);
void		ft_print_s(t_data *f, char *str);
void		ft_print_c(t_data *flags_conv, int c);
void		ft_print_d_i(t_data *f, long int a);
void		ft_print_x(t_data *f, long int s);
void		ft_print_p(t_data *f, unsigned long long s);
int			ft_printf (const char *str, ...);
#endif