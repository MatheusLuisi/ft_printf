/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:57:13 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/09 11:59:11 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_format(va_list args, char c)
{
	int printed;

	printed = 0;
	if (c == 'd' || c == 'i')
		printed = ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		printed = ft_putchar(va_arg(args, int));
	else if (c == 's')
		printed = ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		printed = ft_puthex_lower(va_arg(args, unsigned int));	
	else if (c == 'X')
		printed = ft_puthex_upper(va_arg(args, unsigned int));
	else if (c == 'u')
		printed = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		printed = ft_putstr("0x");
		printed = ft_putadress(va_arg(args, unsigned long long));
	}
	else if (c == '%')
	  return (ft_putchar('%'));
	return (printed);
}


int	ft_printf(const char *str, ...)
{
	int i;
	int printed;
	va_list args;

	i = 0;
	printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if(str[i + 1] != '\0')
				printed += check_format(args, str[i + 1]);
		}
		else 
			printed += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (printed);
}


