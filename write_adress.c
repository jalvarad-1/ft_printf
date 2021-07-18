#include "ft_printf.h"

static void	ft_putnbr_base(t_data *f, unsigned long long nbr, char *base)
{
	int	a;
	int	b;

	a = ft_strlen(base);
	if (nbr > 0)
	{
		ft_putnbr_base(f, nbr / a, base);
		b = nbr % a;
		f->len_str += write(1, &base[b], 1);
	}
	if (nbr < 0)
	{
		f->len_str += write(1, "-", 1);
		ft_putnbr_base(f, -nbr, base);
	}
}

static void	ft_len_adress(t_data *f, unsigned long long nbr, \
	char *base, int *len_adress)
{
	int	a;
	int	b;

	a = ft_strlen(base);
	if (nbr > 0)
	{
		ft_len_adress(f, nbr / a, base, len_adress);
		b = nbr % a;
		*len_adress += 1;
	}
	if (nbr < 0)
	{
		*len_adress += 1;
		ft_len_adress(f, -nbr, base, len_adress);
	}
}

static void	aux_print_p(t_data *f, unsigned long long s, \
		int widht_neg, int len_ad)
{
	int	v;

	v = ab_val(f->widht);
	if (s != 0)
	{
		while (widht_neg == 0 && f->hyphen != '-' && f->widht-- > (2 + len_ad))
			f->len_str += write(1, " ", 1);
		f->len_str += write(1, "0x", 2);
		ft_putnbr_base(f, s, "0123456789abcdef");
		while ((widht_neg == 1 || f->hyphen == '-') && v-- > (2 + len_ad))
			f->len_str += write(1, " ", 1);
	}
	if (s == 0)
	{
		while (widht_neg == 0 && f->hyphen != '-' && f->widht-- > 3)
			f->len_str += write(1, " ", 1);
		f->len_str += write(1, "0x0", 3);
		while ((widht_neg == 1 || f->hyphen == '-') && v-- > 3)
			f->len_str += write(1, " ", 1);
	}
}

void	ft_print_p(t_data *f, unsigned long long s)
{
	int	widht_neg;
	int	len_ad;

	len_ad = 0;
	ft_len_adress(f, s, "0123456789abcdef", &len_ad);
	widht_neg = 0;
	if (f->widht < 0)
		widht_neg = 1;
	aux_print_p(f, s, widht_neg, len_ad);
}
