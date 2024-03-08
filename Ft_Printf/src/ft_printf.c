/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:00:48 by slott             #+#    #+#             */
/*   Updated: 2021/11/04 13:44:18 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	check_flag(char *str, va_list ptr, int c);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		c;
	char	*x;

	c = 0;
	x = (char *)str;
	i = 0;
	va_start(ptr, str);
	while (x[i])
	{
		if (x[i] == '%')
		{
			c = check_flag(&x[i], ptr, c);
			i++;
		}
		else
		{
			write(1, &x[i], 1);
			c++;
		}
		i++;
	}
	va_end(ptr);
	return (c);
}

int	check_flag(char *str, va_list ptr, int c)
{
	if (str[1] == 'c')
		c = ft_putchar(va_arg(ptr, int), c);
	else if (str[1] == 's')
		c = ft_putstr(va_arg(ptr, char *), c);
	else if (str[1] == 'd' || str[1] == 'i')
		c = ft_putnbr(va_arg(ptr, int), c);
	else if (str[1] == '%')
	{
		write(1, "%", 1);
		c++;
	}
	else if (str[1] == 'u')
		c = ft_putunint(va_arg(ptr, unsigned int), c);
	else if (str[1] == 'x')
		c = ft_putnbr_hexa(va_arg(ptr, unsigned int), "0123456789abcdef", c);
	else if (str[1] == 'X')
		c = ft_putnbr_hexa(va_arg(ptr, unsigned int), "0123456789ABCDEF", c);
	else if (str[1] == 'p')
	{
		c = ft_putstr("0x", c);
		c = ft_putptr(va_arg(ptr, unsigned long), "0123456789abcdef", c);
	}
	else
		c = ft_putchar(str[1], c);
	return (c);
}

/*int main()
{
	printf("%d", printf("%s", NULL));
	printf("%d", ft_printf("%s", NULL));
}*/
