/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lang.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:21:00 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:35:45 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LANG_H
# define FT_LANG_H

/*
** Language limits constants
*/
/*
** Language special chars
*/
# define INHIB_CHAR '\\'
# define INHIB_ZONE '\''
# define HALFINHIB_ZONE '\"'
# define SHELL_IFS " \t\v"
# define DICT_LEN 17
# define OP_MAX_LEN 3

/*
** Operators definiton's type
*/
typedef struct		s_def
{
	char			*mark;
	int				len;
	int				type;
	int				nextexprtype;
	int				prior;
}					t_def;

typedef t_def		t_dict[DICT_LEN];

extern t_dict		g_dictsh;

int			ft_get_prior(int type);

int			ft_get_nextexprtype(int type);

int			ft_isop(t_dict dict, char *str, int len);

int			ft_getopind(t_dict dict, char *str);

#endif
