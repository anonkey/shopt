#include "ft_lexer_priv.h"

int			ft_expr(t_lexer_p lex)
{
    if (lex->state != state_expr)
	    ft_flush(lex);
    ft_stack(lex);
    lex->state = state_expr;
    return (0);
}
