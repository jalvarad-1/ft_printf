#include "ft_printf.h"

void	mod_putstr(t_data *flags_conv, char *str)
{
	while (*str != '\0')
	{
		flags_conv->len_str += write(1, str, 1);
		str++;
	}
}

int	ft_atoi(const char *str)
{
	int			sg;
	long long	num;

	sg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str != '+' && *str != '-' && ft_isdigit((int)*str) == 0)
		return (0);
	if (*str == '-')
		sg = -1;
	if (ft_isdigit((int)*str) == 0)
		str++;
	if (ft_isdigit((int)*str) == 0)
		return (0);
	while (ft_isdigit((int)*str))
	{
		num = num * 10 + *str++ - '0';
		if ((num * sg) > INT_MAX)
			return (-1);
		if ((num * sg) < INT_MIN)
			return (0);
	}
	return (num * sg);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	mod_putchar(t_data *flags_conv, char c)
{
	flags_conv->len_str += write(1, &c, 1);
}
