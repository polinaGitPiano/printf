/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:56:57 by eidaho            #+#    #+#             */
/*   Updated: 2020/01/23 16:57:00 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
//переборы аргументов функций
# include <math.h>
# include "../libft/libft.h"


int		ft_printf(const char *format, ...);
int     ft_score_arg(char *str, va_list arg);
int     specificator(int i, char *str);
int     help_specificator(char c);


#endif 