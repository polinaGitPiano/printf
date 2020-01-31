/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:28:49 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:28:53 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			far;
	long long	rez;

	far = 1;
	rez = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			far = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		rez = rez * 10 + (*str - 48);
		++str;
	}
	return (far * rez);
}
