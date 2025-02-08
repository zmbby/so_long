#include "ft_printf.h"

int	init_format(const char *format)
{
	if (*format == '%')
		return (1);
	return (0);
}

void	write_character(char c, int **count)
{
	(**count) += write(1, &c, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_decimale(int i, int **count)
{
	long nbr;

	nbr = i;
	if (nbr < 0)
	{
		(**count)++;
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		write_decimale(nbr / 10, count);
		nbr = nbr % 10;
	}
	(**count)++;
	ft_putchar(nbr + 48);
}