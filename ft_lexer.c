/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 11:00:40 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 19:01:04 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

void				ft_lexdel(t_lexer_p *lex_p, int dellist)
{
    if (!lex_p || !*lex_p)
	    return ;
    if (dellist)
        ft_ldcddel(&((*lex_p)->toklist), NULL);
    ft_dynstrdel(&((*lex_p)->outstack));
    ft_memdel((void **)lex_p);
}

t_lexer_p				ft_lexnew(char *strin)
{
    t_lexer_p	lex;

    if (!strin || !(lex = (t_lexer_p)ft_memalloc(sizeof(t_lexer))))
	    return (NULL);
    if (!(lex->toklist = ft_ldcdnew()) || !(lex->outstack = ft_dynstrnew(1024)))
    {
	    ft_lexdel(&lex, 1);
	    return (NULL);
    }
    lex->strin = strin;
    lex->state = state_start;
    lex->actexprtype = tok_cmd;
    lex->nextexprtype = tok_cmd;
    return (lex);
}

const t_lexfunc			g_lexmatrix[16][11] =
{
	/*
	** inputs:
	** < ,
	** > ,
	** | ,
	** & ,
	** ;\n ,
	** IFS ,
	** \ ,
	** ' ,
	** " ,
	** others,
	** \0
	*/
		/*
		**start
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**expr
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**lredir
		*/
		{
			&ft_llredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**llredir
		*/
		{
			&ft_lllredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**lllredir
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**rredir
		*/
		{
			&ft_lredir,
			&ft_rrredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**rrredir
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**pipe
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_listsep,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**bg
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_listsep,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_hinhib,
			&ft_inhib,
			&ft_expr,
			&ft_end
		},
		/*
		** listsep
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		** termsep
		*/
		{
			&ft_lredir,
			&ft_rredir,
			&ft_pipe,
			&ft_bg,
			&ft_termsep,
			&ft_ifs,
			&ft_escape,
			&ft_inhib,
			&ft_hinhib,
			&ft_expr,
			&ft_end
		},
		/*
		**inhibone
		*/
		{
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_unescape,
			&ft_end
		},
		/*
		**hinhib
		*/
		{
			&ft_hinhib,
			&ft_hinhib,
			&ft_hinhib,
			&ft_hinhib,
			&ft_hinhib,
			&ft_hinhib,
			&ft_escape,
			&ft_hinhib,
			&ft_unhinhib,
			&ft_hinhib,
			&ft_end
		},
		/*
		**inhib
		*/
		{
			&ft_inhib,
			&ft_inhib,
			&ft_inhib,
			&ft_inhib,
			&ft_inhib,
			&ft_inhib,
			&ft_escape,
			&ft_uninhib,
			&ft_inhib,
			&ft_inhib,
			&ft_end
		}
};

int	ft_lexerize(t_lexer_p lex)
{
    while (lex->state != state_end)
    {
	if (!g_lexmatrix[(int)lex->state][ft_getinind(*lex->strin)]
	    || -1 == g_lexmatrix[(int)lex->state][ft_getinind(*lex->strin)](lex))
	    return (1 + *lex->strin);
	++lex->strin;
    }
    return (lex->state == state_end ? 0 : (int)'1');
}
