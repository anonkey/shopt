#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_flush(t_lexer_p lex)
{
    t_token	tok;

    if (lex->outstack->size <= 0)
	    return (0);
    if (!(tok.str = ft_dynstrflush(lex->outstack)))
	return (-1);
    if (lex->state == state_expr)
	tok.type = lex->nextexprtype;
    else
	tok.type = (t_toktype)(1 + ft_getopind(g_dictsh, tok.str));
    lex->nextexprtype = ft_get_nextexprtype(tok.type);
    return (ft_ldcdpush_back(lex->toklist, &tok, sizeof(t_token)));
}

int			ft_stack(t_lexer_p lex)
{
    char	tmp;

    tmp = lex->strin[1];
    lex->strin[1] = '\0';
    ft_dynstradd(lex->outstack, lex->strin);
    lex->strin[1] = tmp;
    return (0);
}

int			ft_end(t_lexer_p lex)
{
    t_token	tok;

    ft_flush(lex);
    tok.str = NULL;
    tok.type = tok_end;
    lex->state = state_end;
    return (ft_ldcdpush_back(lex->toklist, &tok, sizeof(t_token)));
}
