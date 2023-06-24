/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:27:34 by slott             #+#    #+#             */
/*   Updated: 2021/10/13 16:53:43 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	char	*p;
	size_t	x;

	p = (char *) str;
	x = 0;
	while (x < size)
	{
		p[x] = c;
		x++;
	}
	return (str);
}

/*int main()
{
	char str[30] = "okiiiiii";
	printf("%s\n", str);
	ft_memset(str, 'a', 3);
	printf("%s", str);

}*/
