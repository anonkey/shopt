#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_pipe(t_lexer_p lex)
{
    ft_flush(lex);
    ft_stack(lex);
    lex->state = state_pipe;
    return (0);
}
