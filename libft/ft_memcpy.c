/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:51:01 by slott             #+#    #+#             */
/*   Updated: 2021/10/14 16:18:30 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char		*pdst;
	const char	*psrc;
	size_t		x;

	pdst = (char *) dst;
	psrc = (const char *) src;
	x = 0;
	if (!(pdst) && !(psrc))
		return (dst);
	while (x < size)
	{
		pdst[x] = psrc[x];
		x++;
	}
	return (dst);
}

/*int main()
{
	//char src[3] = "";
	char dst[30] = "";
	printf("%s\n", dst);
	ft_memcpy(NULL, NULL, NULL);
	printf("%s", dst);
}*/
