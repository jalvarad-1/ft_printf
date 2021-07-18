#include "ft_printf.h"

void	ft_print_c(t_data *flags_conv, int c)
{
	int	v;

	v = ab_val(flags_conv->widht);
	while (flags_conv->widht-- > 1 && flags_conv->hyphen != '-')
		flags_conv->len_str += write (1, " ", 1);
	flags_conv->len_str += write(1, &c, 1);
	while (v-- > 1 && (flags_conv->hyphen == '-' || flags_conv->widht < 0))
		flags_conv->len_str += write (1, " ", 1);
}
