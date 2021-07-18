#include "ft_printf.h"

void	ft_print_d_i(t_data *f, long int a)
{
	int	n_spcs_f;
	int	n_zeros;
	int	n_spcs_b;

	if (a == 0 && f->widht == 0 && f->prec == 0 && f->dot == '.')
		return ;
	zero_exception_d(f, a);
	n_spcs_f = get_n_spcs_f(f, a);
	n_zeros = get_n_zeros(f, a);
	n_spcs_b = get_n_spcs_b(f, a);
	while (n_spcs_f-- > 0)
		f->len_str += write (1, " ", 1);
	if (a < 0)
		f->len_str += write (1, "-", 1);
	while (n_zeros-- > 0)
		f->len_str += write (1, "0", 1);
	if (a < 0)
		mod_putnbr(f, (a * -1));
	else if (a != 0 || (a == 0 && ab_val (f->widht) >= 0 && f->prec != 0) || \
		f->dot != '.')
		mod_putnbr(f, a);
	while (n_spcs_b-- > 0)
		f->len_str += write (1, " ", 1);
}
