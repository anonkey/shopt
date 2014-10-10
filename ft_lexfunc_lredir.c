#include "ft_lexer_priv.h"
#include "ft_lang.h"
#include "ft_token.h"

int			ft_lredir(t_lexer_p lex)
{
    ft_flush(lex);
    ft_stack(lex);
    lex->state = state_lredir;
    return (0);
}

int			ft_llredir(t_lexer_p lex)
{
    ft_stack(lex);
    lex->state = state_llredir;
    return (0);
}

int			ft_lllredir(t_lexer_p lex)
{
    ft_stack(lex);
    lex->state = state_lllredir;
    return (0);
}
