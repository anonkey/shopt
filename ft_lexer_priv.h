#ifndef FT_LEXER_PRIV_H
# define FT_LEXER_PRIV_H
# include "ft_lexer_type.h"
# define NB_INPUT_GROUPS 11
# define INHIB_LVL_NO 0
# define INHIB_LVL_ONE 1
# define INHIB_LVL_HMULT 2
# define INHIB_LVL_MULT 4

int		ft_ifs(t_lexer_p lex);

int		ft_flush(t_lexer_p lex);

int		ft_stack(t_lexer_p lex);

int		ft_lredir(t_lexer_p lex);

int		ft_llredir(t_lexer_p lex);

int		ft_lllredir(t_lexer_p lex);

int		ft_rredir(t_lexer_p lex);

int		ft_rrredir(t_lexer_p lex);

int		ft_pipe(t_lexer_p lex);

int		ft_bg(t_lexer_p lex);

int		ft_listsep(t_lexer_p lex);

int		ft_termsep(t_lexer_p lex);

int		ft_expr(t_lexer_p lex);

int		ft_end(t_lexer_p lex);

int		ft_escape(t_lexer_p lex);

int		ft_unescape(t_lexer_p lex);

int		ft_inhib(t_lexer_p lex);

int		ft_uninhib(t_lexer_p lex);

int		ft_hinhib(t_lexer_p lex);

int		ft_unhinhib(t_lexer_p lex);

t_lexstate	ft_getinhib_state(int inhiblvl);

int		ft_getinind(char c);

#endif /* !FT_LEXER_PRIV_H */
