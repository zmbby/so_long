#include "ft_printf.h"

void	write_format(const char *format, va_list arg, int *count)
{
	format++;
	if (*format == 'c')
		write_character(va_arg(arg, int), &count);
	else if (*format == 'd')
		write_decimale(va_arg(arg, int), &count);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), &count);
	else if (*format == 'u')
		write_uns_decimal(va_arg(arg, unsigned int), &count);
	else if (*format == '%')
	{
		(*count)++;
		size_t ret = write(1, "%", 1);
		(void)ret;
	}
	else if (*format == 'i')
		write_int(va_arg(arg, int), &count);
	else if (*format == 'p')
		write_hexa_add(va_arg(arg, void *), &count);
	else if (*format == 'x')
		ft_print_hex_v2(va_arg(arg, unsigned int), &count);
	else if (*format == 'X')
		ft_print_hex_v3(va_arg(arg, unsigned int), &count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if ((init_format(format)))
		{
			write_format(format, arg, &count);
			format++;
		}
		else
		{
			count++;
			ft_putchar_2(format);
		}
		format++;
	}
	va_end(arg);
	return (count);
}

// int main()
// {

//     unsigned int p = 4294967295;
//     // int count = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%
// 	// 	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%",
// 	// 	'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C',
// 	// 	"0", 0, 0 ,0 ,0, 42, 0);
//     // write(1, "\n", 1);
//     // int count2 = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%
// 	// 	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%",
// 	// 	'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C',
// 	// 	"0", 0, 0 ,0 ,0, 42, 0);
//     // printf("\ndyali => %d\ndyalhom => %d", count, count2);
// 	printf("%d",printf("%p", p));
//     return (0);
// }