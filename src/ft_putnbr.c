#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int	re;
	
	nb = n;
	re = 0;
	if (nb < 0)
	{
		re += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		re += ft_putchar(nb + '0');
	if (nb > 9)
	{
		re += ft_putnbr(nb / 10);
		re += ft_putnbr(nb % 10);
	}
	return (re);
}

