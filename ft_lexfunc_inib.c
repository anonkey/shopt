#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_inhib(t_lexer_p lex)
{
    if (lex->state != state_expr && lex->state != state_inhib)
	ft_flush(lex);
    if (lex->state == state_inhib)
	ft_stack(lex);
    else
    {
	lex->inhiblvl |= INHIB_LVL_MULT;
	lex->state = state_inhib;
    }
    return (0);
}

int			ft_uninhib(t_lexer_p lex)
{
    lex->inhiblvl &= ~INHIB_LVL_MULT;
    lex->state = ft_getinhib_state(lex->inhiblvl);
    return (0);
}
