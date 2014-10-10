/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 09:53:27 by jcoignet          #+#    #+#             */
/*   Updated: 2014/06/27 16:06:07 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_builtins.h"
#include	"tcap_proto.h"

int		ft_echo(t_cmd cmd)
{
	t_tcap	*list;
	char	*s;

	if (!(s = cmd->av[1]))
	{
		if (!(list = get_tcap_data(NULL, 0)))
		{
			ft_putstr("\n");
			return (0);
		}
		ft_putstr_fd("\n", list->tty_fd);
	}
	else if (s[0] && s[1] && s[0] == '-' && s[1] == 'n')
	{
		s = cmd->av[2];
		if (!(list = get_tcap_data(NULL, 0)))
		{
			ft_putstr(s);
			return (0);
		}
		ft_putstr_fd(s, list->tty_fd);
	}
	else
	{
		if (!(list = get_tcap_data(NULL, 0)))
		{
			ft_putendl(s);
			return (0);
		}
		ft_putendl_fd(s, list->tty_fd);
	}
	return (0);
}
