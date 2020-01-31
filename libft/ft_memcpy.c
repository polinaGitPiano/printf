/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:32:29 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:32:30 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstt;
	const unsigned char	*srcc;

	dstt = (unsigned char *)dst;
	srcc = (const unsigned char *)src;
	while (n > 0)
	{
		if (!dstt && !srcc)
			return (NULL);
		if (n > 0)
		{
			*dstt = *srcc;
			dstt++;
			srcc++;
		}
		n--;
	}
	return (dst);
}
