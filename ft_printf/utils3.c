#include "ft_printf.h"

void	ft_putchar_2(const char *format)
{
	write(1, &*format, 1);
}

void	ft_putstr(char *str, int **count)
{
	if (!str)
		(**count) += write(1, "(null)", 6);
	else
		while (*str)
			**count += write(1, &(*str++), 1);
}

void	write_uns_decimal(unsigned int nbr, int **count)
{
	if (nbr > 9)
	{
		write_uns_decimal(nbr / 10, count);
		nbr = nbr % 10;
	}
	(**count)++;
	ft_putchar(nbr + 48);
}
