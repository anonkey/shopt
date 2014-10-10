/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 03:33:11 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 18:28:43 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"
#include "ft_lexer.h"
#include "ft_parser.h"

int		ft_putvtoken(void *tokv)
{
    t_token_p	    tokp;
    int		    len;

    tokp = tokv;
    len = ft_putstr(tokp->str);
    len += ft_putstr(" -> ");
    switch (tokp->type)
    {
	case tok_unknown:
		len += ft_putendl("tok_unknown");
		break;
	case tok_cmd:
		len += ft_putendl("tok_cmd");
		break;
	case tok_cmdarg:
		len += ft_putendl("tok_cmdarg");
		break;
	case tok_userinput:
		len += ft_putendl("tok_userinput");
		break;
	case tok_filename:
		len += ft_putendl("tok_filename");
		break;
	case tok_lredir:
		len += ft_putendl("tok_lredir");
		break;
	case tok_llredir:
		len += ft_putendl("tok_llredir");
		break;
	case tok_lllredir:
		len += ft_putendl("tok_lllredir");
		break;
	case tok_rredir:
		len += ft_putendl("tok_rredir");
		break;
	case tok_rrredir:
		len += ft_putendl("tok_rrredir");
		break;
	case tok_pipe:
		len += ft_putendl("tok_pipe");
		break;
	case tok_and:
		len += ft_putendl("tok_and");
		break;
	case tok_or:
		len += ft_putendl("tok_or");
		break;
	case tok_bg:
		len += ft_putendl("tok_bg");
		break;
	case tok_semicol:
		len += ft_putendl("tok_semicol");
		break;
	case tok_nl:
		len += ft_putendl("tok_nl");
		break;
	case tok_end:
		len += ft_putendl("tok_end");
		break;
    }
    return (len);
}
int		main(int argc, char **argv)
{
    t_lexer_p	lex;
    t_parser_p	pars;
    char	c;

    if (argc < 2)
	return (0);
	ft_printf("Argv : %s\n", argv[1]);
    lex = ft_lexnew(argv[1]);
    if ((c = ft_lexerize(lex)))
	ft_printf("Error on '%c'", c - 1);
    else
	ft_putldcd(lex->toklist, &ft_putvtoken);
    pars = ft_parsernew(lex->toklist);
    ft_putendl("\n\t PARSED \n");
    if (-2 == ft_parse(pars))
    {
	ft_putendl("Error on token : ");
	ft_putvtoken((void *)pars->tokin);
    }
    else
        ft_putldcd(pars->outlist, &ft_putvtoken);
    ft_parserdel(&pars);
    ft_lexdel(&lex, 0);
	return (0);
}