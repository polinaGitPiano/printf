/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:36:00 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:36:01 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*str;
	unsigned int	l;

	l = 0;
	while (src[l] != '\0')
		l++;
	if (!(str = (char *)malloc(sizeof(*str) * (l + 1))))
		return (NULL);
	l = 0;
	while (src[l] != '\0')
	{
		str[l] = src[l];
		l++;
	}
	str[l] = '\0';
	return ((char *)str);
}
