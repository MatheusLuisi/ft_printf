#include "ft_printf.h"

int ft_puthex_lower(unsigned int n)
{
	int count;
	char *base;

	count = 0;
	base = "0123456789abcdef";
	if (n >=16)
	{
		count += ft_puthex_lower(n / 16);
		count += ft_puthex_lower(n % 16);
	}
	else 
		count += ft_putchar(base[n % 16]);
	return (count);
}

