/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:37:17 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:37:18 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	len;
	int		i;
	char	*dst;

	if (s == NULL)
		return (NULL);
	dst = (char *)s;
	if (dst || f)
	{
		len = ft_strlen(dst) + 1;
		if (!(str = (char *)malloc((sizeof(char) * len))))
			return (NULL);
		i = 0;
		while (dst[i] != '\0')
		{
			str[i] = f(dst[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
