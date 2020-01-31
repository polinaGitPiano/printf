/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:31:10 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/21 11:31:11 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*str;
	t_list	*cmp;

	cmp = *alst;
	while (alst && del && cmp)
	{
		str = cmp;
		del(cmp->content, cmp->content_size);
		free(cmp);
		cmp = str->next;
	}
	*alst = NULL;
}
