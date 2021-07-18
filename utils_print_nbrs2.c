#include "ft_printf.h"

long int	ab_val(long int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	int_len(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	aux_n_spcs(t_data *f, long int a, int *n_spcs_f)
{
	if (f->zero == '0' && f->dot == '.')
	{
		if (f->prec > int_len(a) && a >= 0)
			*n_spcs_f = f->widht - f->prec;
		if (f->prec > int_len(a * -1) && a < 0)
			*n_spcs_f = f->widht - f->prec - 1;
		if (f->prec <= int_len(a) && f->prec >= 0 && a >= 0)
		{
			if (f->prec >= 0 && f->prec < int_len(a) && a == 0)
				f->widht++;
			*n_spcs_f = f->widht - int_len(a);
		}
		if (f->prec <= int_len(a * -1) && f->prec >= 0 && a < 0)
			*n_spcs_f = f->widht - int_len(a);
	}
}

static void	mini_aux_get_n_spcs_f(t_data *f, long int a, int *n_spcs_f)
{
	if (f->prec >= 0 && f->prec < int_len(a))
		f->widht++;
	*n_spcs_f = f->widht - int_len(a) - 1;
	if (f->prec < 0)
		*n_spcs_f = f->widht - int_len(a);
}

int	get_n_spcs_f(t_data *f, long int a)
{
	int	n_spcs_f;

	n_spcs_f = 0;
	if (f->hyphen != '-' && f->widht >= int_len(a))
	{
		if (f->zero == ' ' && f->prec == 0)
			n_spcs_f = f->widht - int_len(a);
		if (f->zero == ' ' && f->prec < f->widht)
		{
			if (f->prec > int_len(a) && a >= 0)
				n_spcs_f = f->widht - f->prec;
			if (a < 0 && f->prec > int_len(a * -1))
				n_spcs_f = f->widht - f->prec - 1;
			if (f->prec < 0 || (f->prec <= int_len(a) && a >= 0))
				n_spcs_f = f->widht - int_len(a);
			if (f->prec <= int_len(a) && a < 0)
				mini_aux_get_n_spcs_f(f, a, &n_spcs_f);
		}
		aux_n_spcs(f, a, &n_spcs_f);
	}
	return (n_spcs_f);
}
