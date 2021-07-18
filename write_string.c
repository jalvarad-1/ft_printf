#include "ft_printf.h"

static void	aux1_print_s(t_data *f, char **str, int *a, int *v)
{
	if (f->dot != '.' && ab_val(f->widht) >= (int)ft_strlen(*str))
	{
		while (f->hyphen != '-' && *a == 0 && f->widht-- > (int)ft_strlen(*str))
			f->len_str += write (1, " ", 1);
		while (**str)
		{
			f->len_str += write (1, (*str)++, 1);
			(*v)--;
		}
		while ((f->hyphen == '-' || *a == 1) && (*v)-- > 0)
			f->len_str += write (1, " ", 1);
	}
}

static void	aux3_print_s(t_data *f, int s_len, int *a, int *n)
{
	if (f->prec < 0)
		*n = 1;
	if (s_len >= f->prec && f->prec >= 0)
		while (f->hyphen != '-' && *a == 0 && f->widht-- > f->prec)
			f->len_str += write (1, " ", 1);
	if (s_len < f->prec)
		while (f->hyphen != '-' && *a == 0 && f->widht-- > s_len)
			f->len_str += write (1, " ", 1);
	if (f->prec < 0)
		while (f->hyphen != '-' && *a == 0 && f->widht-- > s_len)
			f->len_str += write (1, " ", 1);
}

static void	aux2_print_s(t_data *f, char **str, int *a, int *v)
{
	int	n;
	int	s_len;

	n = 0;
	s_len = (int)ft_strlen(*str);
	aux3_print_s(f, s_len, a, &n);
	if (f->prec > 0)
	{
		while (**str && f->prec-- > 0)
		{
			f->len_str += write (1, (*str)++, 1);
			(*v)--;
		}
	}
	else if (f->widht == 0 || f->prec < 0 )
		while (**str)
			f->len_str += write (1, (*str)++, 1);
	while ((f->hyphen == '-' || *a == 1) && n == 1 && (*v)-- > s_len)
		f->len_str += write (1, " ", 1);
	while ((f->hyphen == '-' || *a == 1) && n == 0 && (*v)-- > 0)
		f->len_str += write (1, " ", 1);
}

static void	mini_aux_print_s(t_data *f, char **str, int *a, int *is_null)
{
	if (f->widht < 0)
		*a = 1;
	if (!(*str))
	{
		*str = "(null)";
		*is_null = 1;
	}
}

void	ft_print_s(t_data *f, char *str)
{
	int	v;
	int	a;
	int	is_null;

	is_null = 0;
	a = 0;
	v = ab_val(f->widht);
	if (f->widht == 0 && f->prec == 0 && f->dot == '.')
		return ;
	mini_aux_print_s(f, &str, &a, &is_null);
	if (str)
	{
		if (is_null == 1 && f->prec < 0)
			null_print_s(f, str, &is_null, &v);
		else
		{
			if (f->dot != '.' && ab_val(f->widht) >= (int)ft_strlen(str))
				aux1_print_s(f, &str, &a, &v);
			if (f->dot == '.' )
				aux2_print_s(f, &str, &a, &v);
			else
				while (*str)
					f->len_str += write (1, str++, 1);
		}
	}
}
