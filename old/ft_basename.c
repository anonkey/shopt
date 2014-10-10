/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/28 15:27:59 by tseguier          #+#    #+#             */
/*   Updated: 2014/06/28 21:41:50 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"
#include "libft.h"


static void		ft_putbasename(char *str, char *suffix)
{
	char	*strend;
	char	*suffixend;
	char	tmp;

	strend = str + ft_strlen(str);
	suffixend = suffix + ft_strlen(suffix);
	while (strend != str && suffix != suffixend && *suffixend == *strend)
	{
		--strend;
		--suffixend;
	}
	if (strend == str || suffix != suffixend)
		ft_putendl(str);
	else
	{
		tmp = *strend;
		*strend = '\0';
		ft_putendl(str);
		*strend = tmp;
	}
}

static int		ft_epurbasename(t_cmd cmd, char *str)
{
	char	tmp;
	int		ret;

	if (str == cmd->av[1])
	{
		ft_putendl("/");
		return (0);
	}
	tmp = *str;
	*str = '\0';
	ret = ft_basename(cmd);
	*str = tmp;
	return (ret);
}

int				ft_basename(t_cmd cmd)
{
	char	*strend;

	if (!cmd->av[1])
	{
		ft_putendl_fd("Usage : basename string [suffix]", 2);
		return (-1);
	}
	strend = ft_strrchr(cmd->av[1], '/');
	if (strend && !strend[1])
		return (ft_epurbasename(cmd, strend));
	if (!strend)
		strend = cmd->av[1];
	if (cmd->av[2])
		ft_putbasename((*strend == '/') ? strend + 1 : strend, cmd->av[2]);
	else
		ft_putendl((*strend == '/') ? strend + 1 : strend);
	return (0);
}