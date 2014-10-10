#include "ft_lexer_priv.h"

int			ft_escape(t_lexer_p lex)
{
    if (lex->state != state_expr)
	    ft_flush(lex);
    lex->inhiblvl |= INHIB_LVL_ONE;
    lex->state = state_inhibone;
    return (0);
}

int			ft_unescape(t_lexer_p lex)
{
    ft_stack(lex);
    lex->inhiblvl &= ~INHIB_LVL_ONE;
    lex->state = ft_getinhib_state(lex->inhiblvl);
    return (0);
}
