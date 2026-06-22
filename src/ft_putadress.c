
#include "ft_printf.h"

int ft_putadress(unsigned long nb)
{
 	int	count;
 	char	*base;

 	count = 0;
 	base = "0123456789abcdef";
 	if (nb >= 16)
 	{
    		count += ft_putadress(nb / 16);
    		count += ft_putadress(nb % 16);
 	}
 	else
		count += ft_putchar(base[nb % 16]);
	return (count);
}
