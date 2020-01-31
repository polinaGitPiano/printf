/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:32:00 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:32:01 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstt;
	unsigned char		*srcc;
	size_t				i;

	dstt = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		*dstt = *srcc;
		if (*dstt == (unsigned char)c)
			return ((void *)dst + i + 1);
		dstt++;
		srcc++;
		i++;
	}
	return (NULL);
}
