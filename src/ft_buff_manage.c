/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:09:07 by eidaho            #+#    #+#             */
/*   Updated: 2020/02/24 15:09:09 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_buff(t_buff *buf, int fd)
{
	int		i;

	i = 0;
	while (i < MAX_LEN)
		buf->buff[i++] = '\0';
	buf->i = 0;
	buf->len = 0;
	buf->fd = fd;
}

void	ft_fd_write(int fd, t_buff *buf)
{
	write(fd, buf->buff, buf->i);
	buf->len += buf->i;
	buf->i = 0;
}

void	ft_push(t_buff *buf, unsigned char c)
{
	buf->buff[buf->i++] = c;
	if (buf->i == MAX_LEN - 1)
		ft_fd_write(buf->fd, buf);
}
