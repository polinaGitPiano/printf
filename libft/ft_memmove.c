/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:32:57 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:32:58 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstt;
	const unsigned char	*srcc;
	size_t				k;

	dstt = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	k = 0;
	if (dstt > srcc)
	{
		while (++k <= len)
			dstt[len - k] = srcc[len - k];
	}
	else if (dstt < srcc)
		ft_memcpy(dstt, srcc, len);
	return ((void *)dst);
}
