/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 02:07:36 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:42:16 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_lang.h"
#include "ft_token.h"
t_def				g_dictsh[DICT_LEN] =
{
	{NULL, 0, tok_cmd, tok_cmdarg, 4},
	{NULL, 0, tok_cmdarg, tok_cmdarg, 3},
	{NULL, 0, tok_userinput, tok_cmdarg, 1},
	{NULL, 0, tok_filename, tok_cmdarg, 1},
	{"<", 1, tok_lredir, tok_filename, 2},
	{"<<", 2, tok_llredir, tok_filename, 2},
	{"<<<", 3, tok_lllredir, tok_userinput, 2},
	{">", 1, tok_rredir, tok_filename, 2},
	{">>", 2, tok_rrredir, tok_filename, 2},
	{"|", 1, tok_pipe, tok_cmd, 5},
	{"&&", 2, tok_and, tok_cmd, 6},
	{"||", 2, tok_or, tok_cmd, 6},
	{"&", 1, tok_bg, tok_cmd, 7},
	{";", 1, tok_semicol, tok_cmd, 8},
	{"\n", 1, tok_nl, tok_cmd, 9},
	{NULL, 0, tok_end, tok_unknown, 10}
};

int			ft_getprior(int type)
{
	int		i;

	i = 0;
	while (i < DICT_LEN)
	{
		if (g_dictsh[i].type == type)
		    return (g_dictsh[i].prior);
		++i;
	}
	return (0);
}

int			ft_get_nextexprtype(int type)
{
	int		i;

	i = 0;
	while (i < DICT_LEN)
	{
		if (g_dictsh[i].type == type)
		    return (g_dictsh[i].nextexprtype);
		++i;
	}
	return (tok_unknown);
}

int			ft_isop(t_dict dict, char *str, int len)
{
    int	    res;

    str[len] = '\0';
    res = ft_getopind(dict, str);
    return (res == -1 ? 0 : 1);
}

int			ft_getopind(t_dict dict, char *str)
{
	int		i;

	i = 0;
	while (i < DICT_LEN)
	{
		if (!ft_strcmp(dict[i].mark, str))
		    return (i);
		++i;
	}
	return (-1);
}
