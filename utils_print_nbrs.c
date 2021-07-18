#include "ft_printf.h"

void	mod_putnbr(t_data *flags_conv, long int n)
{
	if (n < 0)
	{
		mod_putchar(flags_conv, '-');
		n = -n;
	}
	if (n >= 10)
	{
		mod_putnbr(flags_conv, n / 10);
		mod_putnbr(flags_conv, n % 10);
	}
	else
		mod_putchar(flags_conv, n + '0');
}

void	zero_exception_d(t_data *f, long int a)
{
	if (a == 0 && f->widht < 0 && f->prec == 0 && f->dot == '.')
		f->widht--;
	if (a == 0 && f->widht > 0 && f->prec == 0 && f->dot == '.' && \
		f->zero != '0')
		f->widht++;
}

int	get_n_spcs_b(t_data *f, long int a)
{
	int	n_spcs_b;

	n_spcs_b = 0;
	if (f->hyphen == '-' || f->widht < 0 )
	{
		if (ab_val(f->widht) > int_len(a))
		{
			if (f->prec >= int_len(a) && a >= 0)
				n_spcs_b = ab_val(f->widht) - f->prec;
			if (f->prec >= int_len(a * -1) && a < 0)
				n_spcs_b = ab_val(f->widht) - f->prec - 1;
			if (f->prec < int_len(a) && a >= 0)
				n_spcs_b = ab_val(f->widht) - int_len(a);
			if (f->prec < int_len(a * -1) && a < 0)
				n_spcs_b = ab_val(f->widht) - int_len(a);
		}
	}
	return (n_spcs_b);
}

static void	aux_n_zeros(t_data *f, long int a, int *n_zeros)
{
	if (f->zero == ' ')
	{
		if (f->prec > int_len(a * -1) && (f->prec < ab_val(f->widht) || \
			f->prec > ab_val(f->widht)) && a < 0)
			*n_zeros = f->prec - int_len(a * -1);
		if ((f->prec < ab_val(f->widht) || f->prec > ab_val(f->widht)) && \
			f->prec > int_len(a) && a >= 0)
			*n_zeros = f->prec - int_len(a);
		else if (f->prec == ab_val(f->widht))
			*n_zeros = f->prec - int_len(ab_val(a));
	}
}

int	get_n_zeros(t_data *f, long int a)
{
	int	n_zeros;

	n_zeros = 0;
	if (f->zero == '0')
	{
		if (f->dot == ' ' && f->hyphen != '-')
			if ((a >= 0 && f->widht > int_len(a)) || \
				(a < 0 && f->widht > int_len(a * -1)))
				n_zeros = f->widht - int_len(a);
		if (f->dot == '.')
		{
			if (a >= 0 && f->prec > int_len(a))
				n_zeros = f->prec - int_len(a);
			if (a < 0 && f->prec > int_len(a * -1))
				n_zeros = f->prec - int_len(a * -1);
			if (a >= 0 && f->prec < 0)
				n_zeros = f->widht - int_len(a);
			if (a < 0 && f->prec < 0)
				n_zeros = f->widht - int_len(a);
		}
	}
	aux_n_zeros(f, a, &n_zeros);
	return (n_zeros);
}
