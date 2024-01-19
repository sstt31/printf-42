

#include "ft_printf.h"

int	check_flag(va_list ap, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = len + print_char(va_arg(ap, int));
	else if (specifier == 's')
		len = len + print_string(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		len = len + print_digit(va_arg(ap, int));
	else if (specifier == 'u')
		len = len + print_unsigned_int(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len = len + print_hexa(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'p')
		len = len + print_ptr(va_arg(ap, unsigned long long), 0);
	else if (specifier == '%')
		len = len + print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len = len + check_flag(ap, format[i + 1]);
			i++;
		}
		else
			len = len + print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

/* #include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
#include <limits.h>

#include "ft_printf.h" //library of ft_printf

int main(void)

{
	int check_ret;
	ft_printf("\001\002\007\v\010\f\r\n");
	check_ret = ft_printf("\001\002\007\v\010\f\r\n");
	printf("\n");
	printf("%d", check_ret);


    return 0;
} */