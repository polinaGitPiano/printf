/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:38:11 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:38:12 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	f;

	if (*need == '\0')
		return ((char *)hay);
	if (!*need)
		return ((char *)hay);
	while (*hay != '\0' && len > 0)
	{
		if (*hay == *need)
		{
			i = 0;
			f = len;
			while (need[i] != '\0' && hay[i] == need[i] && f > 0)
			{
				++i;
				f--;
			}
			if (need[i] == '\0')
				return ((char *)hay);
		}
		len--;
		hay++;
	}
	return (0);
}
