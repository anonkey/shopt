/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcddel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 02:05:00 by tseguier          #+#    #+#             */
/*   Updated: 2014/03/27 18:38:26 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_ldcddel(t_ldcd *ldcd, void (*del)(void **))
{
	t_ldcd_cell		iter;
	t_ldcd_cell		temp;

	if (!ldcd || !*ldcd)
		return ;
	iter = (*ldcd)->head;
	while (iter)
	{
		temp = iter->next;
		ft_ldcd_celldel(&iter, del);
		iter = temp;
	}
	ft_memdel((void **)ldcd);
}
