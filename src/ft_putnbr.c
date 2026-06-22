#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int	count;
	
	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		count += ft_putchar(nb + '0');
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

