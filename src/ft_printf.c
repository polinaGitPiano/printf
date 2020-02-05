/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:44:05 by eidaho            #+#    #+#             */
/*   Updated: 2020/01/24 11:44:09 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// просматриваем все входящие параметры и передаем их в функцию распределения
int			ft_printf(const char *format, ...) {
    int per;
    va_list arg;
    
    per = 0;
    va_start(arg, format);
    per = ft_score_arg((char *)format, arg);
    va_end(arg);
    return (per);
}