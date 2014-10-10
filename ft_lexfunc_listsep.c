#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_listsep(t_lexer_p lex)
{
    ft_stack(lex);
    lex->state = state_listsep;
    return (0);
}
