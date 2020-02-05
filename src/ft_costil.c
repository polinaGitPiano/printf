/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:18:34 by eidaho            #+#    #+#             */
/*   Updated: 2020/02/05 10:18:41 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     help_specificator(char c)
{
    char    spec[11];
    int i;

    i = 0;
    spec[0] = 's';
    spec[1] = 'c';
    spec[2] = 'd';
    spec[3] = 'p';
    spec[4] = 'o';
    spec[5] = 'i';
    spec[6] = 'x';
    spec[7] = 'u';
    spec[8] = 'f';
    spec[9] = 'X';
    spec[10] = '\0';
    while (spec[i])
    {
        if (spec[i++] == c)
        return (1);
    }
    return (0);
}