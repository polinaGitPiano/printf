/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:38:45 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:38:46 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	d;

	if (*s2 == '\0')
		return ((char *)s1);
	if (!*s1 || !*s2)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			d = 1;
			while (s2[d] != '\0' && s1[i + d] == s2[d])
				d++;
			if (s2[d] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
