/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:38:56 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:38:57 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	char	*str;

	if (s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			++s;
		if (*s == '\0')
			return (ft_strdup(s));
		dst = (char *)s;
		while (*dst)
			++dst;
		while (*--dst == ' ' || *dst == '\t' || *dst == '\n')
			;
		if (!(str = (char *)malloc(dst - s + 2)))
			return (NULL);
		ft_strncpy(str, s, dst - s + 1);
		*(str + (dst - s + 1)) = '\0';
		return (str);
	}
	return (NULL);
}
