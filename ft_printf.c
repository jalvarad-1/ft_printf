#include "ft_printf.h"

static	void	set_do_conv(t_data *flags_conv)
{
	if (*flags_conv->str == 'c')
		ft_print_c(flags_conv, va_arg(flags_conv->args, int));
	else if (*flags_conv->str == 's')
		ft_print_s(flags_conv, va_arg(flags_conv->args, char *));
	else if (*flags_conv->str == 'p')
		ft_print_p(flags_conv, va_arg(flags_conv->args, unsigned long long));
	if (*flags_conv->str == 'd' || *flags_conv->str == 'i')
		ft_print_d_i(flags_conv, va_arg(flags_conv->args, int));
	else if (*flags_conv->str == 'u')
		ft_print_d_i(flags_conv, va_arg(flags_conv->args, unsigned int));
	else if (*flags_conv->str == 'x')
		ft_print_x(flags_conv, va_arg(flags_conv->args, unsigned int));
	else if (*flags_conv->str == 'X')
		ft_print_x(flags_conv, va_arg(flags_conv->args, unsigned int));
	else if (*flags_conv->str == '%')
		flags_conv->len_str += write(1, "%", 1);
}

static void	default_flags(t_data *flags_conv)
{
	flags_conv->zero = ' ';
	flags_conv->widht = 0;
	flags_conv->prec = 0;
	flags_conv->dot = ' ';
	flags_conv->hyphen = ' ';
}

static void	ft_setflags(t_data *f)
{
	if (*f->str == '-')
		f->hyphen = '-';
	if (ft_isdigit(*f->str) && *f->str != '0' && f->dot != '.')
	{
		f->widht = ft_atoi(f->str);
		while (ft_isdigit(*f->str))
			f->str++;
	}
	if (*f->str == '0')
		f->zero = '0';
	if (*f->str == '*')
		f->widht = va_arg(f->args, int);
	if (*f->str == '.')
	{
		f->dot = '.';
		if (!ft_isalpha(*(f->str + 1)))
			f->str++;
		if (ft_isdigit(*f->str))
			f->prec = ft_atoi(f->str);
		else if (*f->str == '*')
			f->prec = va_arg(f->args, int);
	}
}

static void	aux_ft_printf(t_data *f)
{
	if (*f->str == '%')
	{
		f->str++;
		default_flags(f);
		while (!ft_isalpha(*f->str) && *f->str)
		{
			ft_setflags(f);
			if (*f->str == '%' || ft_isalpha(*f->str))
				break ;
			f->str++;
		}
		set_do_conv(f);
	}
	else
		f->len_str += write(1, f->str, 1);
}

int	ft_printf (const char *str, ...)
{
	t_data			flags_conv;

	flags_conv.str = (char *)str;
	va_start(flags_conv.args, str);
	flags_conv.len_str = 0;
	while (*flags_conv.str)
	{
		aux_ft_printf(&flags_conv);
		flags_conv.str++;
	}
	va_end (flags_conv.args);
	return (flags_conv.len_str);
}

int main ()
{
	//ft_printf("%*d\n", 0, 42);
	//printf("%*d\n", 0, 42);
	ft_printf("%0d\n", 0, 42);
	printf("%0d\n", 0, 42);
