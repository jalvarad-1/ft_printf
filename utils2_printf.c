#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	null_print_s(t_data *f, char *str, int *is_null, int *v)
{
	int	a;

	a = 0;
	if (f->widht < 0)
		a = 1;
	if (*is_null == 1 && f->prec < 0)
	{
		while (a == 0 && f->hyphen != '-' && (*v)-- > (int)ft_strlen(str))
			f->len_str += write(1, " ", 1);
		f->len_str += write (1, "(null)", 6);
		while ((a == 1 || f->hyphen == '-') && (*v)-- > (int)ft_strlen(str))
			f->len_str += write(1, " ", 1);
	}
}
