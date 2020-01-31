/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:37:47 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:37:48 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		k;

	k = 0;
	while (k < len)
	{
		while (src[k] != '\0' && k < len)
		{
			dst[k] = src[k];
			++k;
		}
		while (len > k)
		{
			dst[k] = '\0';
			k++;
		}
	}
	return ((char *)dst);
}
