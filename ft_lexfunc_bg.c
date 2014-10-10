#include "ft_lexer_priv.h"

int			ft_bg(t_lexer_p lex)
{
    ft_flush(lex);
    ft_stack(lex);
    lex->state = state_bg;
    return (0);
}
