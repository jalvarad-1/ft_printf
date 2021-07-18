#include "ft_printf.h"

static void	x_putnbr_base(t_data *f, unsigned int nbr, char *base)
{
	int	a;
	int	b;

	a = ft_strlen(base);
	if (nbr > 0)
	{
		x_putnbr_base(f, nbr / a, base);
		b = nbr % a;
		f->len_str += write(1, &base[b], 1);
	}
	if (nbr < 0)
	{
		f->len_str += write(1, "-", 1);
		x_putnbr_base(f, -nbr, base);
	}
}

static void	x_len(t_data *f, unsigned int nbr, char *base, int *len_adress)
{
	int	a;
	int	b;

	a = ft_strlen(base);
	if (nbr > 0)
	{
		x_len(f, nbr / a, base, len_adress);
		b = nbr % a;
		*len_adress *= 10;
	}
	if (nbr < 0)
	{
		*len_adress *= 10;
		x_len(f, -nbr, base, len_adress);
	}
}

static void	aux_print_x(t_data *f, long int s, int len_ad, char *base)
{
	int	n_spcs_f;
	int	n_zeros;
	int	n_spcs_b;

	if (s == 0 && f->widht == 0 && f->prec == 0 && f->dot == '.')
		return ;
	zero_exception_d(f, s);
	n_spcs_f = get_n_spcs_f(f, len_ad);
	n_zeros = get_n_zeros(f, len_ad);
	n_spcs_b = get_n_spcs_b(f, len_ad);
	while (n_spcs_f-- > 0)
		f->len_str += write (1, " ", 1);
	while (n_zeros-- > 0)
		f->len_str += write (1, "0", 1);
	if (s != 0)
		x_putnbr_base(f, s, base);
	else if ((s == 0 && f->prec != 0) || f->dot != '.')
		f->len_str += write (1, "0", 1);
	while (n_spcs_b-- > 0)
		f->len_str += write (1, " ", 1);
}

void	ft_print_x(t_data *f, long int s)
{
	int	widht_neg;
	int	len_ad;

	len_ad = 1;
	if (*f->str == 'x')
		x_len(f, s, "0123456789abcdef", &len_ad);
	if (*f->str == 'X')
		x_len(f, s, "0123456789ABCDEF", &len_ad);
	len_ad /= 10;
	widht_neg = 0;
	if (f->widht < 0)
		widht_neg = 1;
	if (*f->str == 'x')
		aux_print_x(f, s, len_ad, "0123456789abcdef");
	if (*f->str == 'X')
		aux_print_x(f, s, len_ad, "0123456789ABCDEF");
}
