#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_termsep(t_lexer_p lex)
{
    ft_flush(lex);
    ft_stack(lex);
    lex->state = state_termsep;
    return (0);
}
