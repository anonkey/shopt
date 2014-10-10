#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_rredir(t_lexer_p lex)
{
    ft_flush(lex);
    ft_stack(lex);
    lex->state = state_rredir;
    return (0);
}

int			ft_rrredir(t_lexer_p lex)
{
    ft_stack(lex);
    lex->state = state_rrredir;
    return (0);
}
