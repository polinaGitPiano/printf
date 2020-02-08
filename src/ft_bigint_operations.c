/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:31:58 by eidaho            #+#    #+#             */
/*   Updated: 2020/02/08 19:32:00 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_bigint_sum(t_bigint *bigint1, t_bigint *bigint2)
{
	int					i;
	unsigned long long	temp;

	i = 0;
	temp = 0;
	while (i < bigint2->size || temp)
	{
		bigint1->num[i] += temp + bigint2->num[i];
		temp = (bigint1->num[i] >= MAX_NUM);
		if (i == bigint1->size)
			bigint1->size++;
		if (temp)
			bigint1->num[i] -= MAX_NUM;
		i++;
	}
}

void		ft_big_int_multi(t_bigint *bigint, int num)
{
	int					i;
	unsigned long long	temp;
	unsigned long long	div;

	i = 0;
	div = 0;
	while (i < bigint->size)
	{
		temp = div + bigint->num[i] * num;
		bigint->num[i] = temp % MAX_NUM;
		div = temp / MAX_NUM;
		i++;
		if (i == bigint->size && div)
			bigint->size++;
	}
}

t_bigint	ft_bigint_multi(t_bigint *bigint1, t_bigint *bigint2)
{
	t_bigint			result;
	unsigned long long	temp;
	unsigned long long	div;
	int					i;
	int					j;

	ft_reset_bigint(&result);
	i = 0;
	while (i < bigint1->size)
	{
		j = 0;
		div = 0;
		while (j < bigint2->size || div)
		{
			temp = result.num[i + j] + bigint1->num[i] * bigint2->num[j] + div;
			result.num[i + j] = temp % MAX_NUM;
			div = temp / MAX_NUM;
			if ((i + j == result.size) || div)
				result.size++;
			j++;
		}
		i++;
	}
	return (result);
}
