/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:34:33 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:34:34 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*str;
	char	*dst;

	str = s1;
	dst = (char *)s2;
	while (*str != '\0')
		str++;
	while (*dst != '\0')
	{
		*str = *dst;
		str++;
		dst++;
	}
	*str = '\0';
	return (s1);
}
