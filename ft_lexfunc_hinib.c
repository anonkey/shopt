#include "ft_lexer_priv.h"

int			ft_hinhib(t_lexer_p lex)
{
    if (lex->state == state_hinhib)
	ft_stack(lex);
    else
    {
	lex->inhiblvl |= INHIB_LVL_HMULT;
	if (lex->state != state_expr && lex->state != state_inhib && lex->state != state_hinhib)
	    ft_flush(lex);
    }
    lex->state = state_hinhib;
    return (0);
}

int			ft_unhinhib(t_lexer_p lex)
{
    lex->inhiblvl &= ~INHIB_LVL_HMULT;
    lex->state = ft_getinhib_state(lex->inhiblvl);
    return (0);
}


