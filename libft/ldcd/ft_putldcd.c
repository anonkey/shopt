/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldcd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 13:24:38 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 13:31:05 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ldcd_cell.h"

int		ft_putldcd(t_ldcd ldcd, int (*put)(void *))
{
	int	    size;
	int	    tmp;
	t_ldcd_cell		iter;

	size = 0;
	if (!ldcd)
		return (-1);
	iter = ldcd->head;
	while (iter)
	{
		if (-1 == (tmp = (*put)(iter->content)))
			return (-1);
		size += tmp;
		iter = iter->next;
	}
	return (size);
}
