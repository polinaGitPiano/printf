/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:33:52 by eidaho            #+#    #+#             */
/*   Updated: 2020/02/08 19:33:53 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Печать ширины формата
*/

void	ft_print_width(t_buff *buf, int *width, char c)
{
	while ((*width)-- > 0)
		ft_push(buf, c);
}

/*
** Печать количества выводимых символов
*/

void	ft_p_printrec(t_buff *buf, int sum, int len)
{
	while (len < sum--)
		ft_push(buf, '0');
}

/*
** Условия для печати шестнадцатеричной, восьмеричной и двоичной
** с условием если есть флаг F_SHARP '#'
*/

void	ft_s_printharp(t_buff *buf, t_options *f)
{
	if (f->base == 16)
	{
		ft_push(buf, '0');
		ft_push(buf, 'X' | (f->flags & F_LOWER));
	}
	if (f->base == 8)
		ft_push(buf, '0');
	else if (f->base == 2)
	{
		ft_push(buf, '0');
		ft_push(buf, 'b');
	}
}
