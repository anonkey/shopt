#ifndef FT_LEXER_TYPE_H
# define FT_LEXER_TYPE_H
#include "libft.h"
#include "ft_token.h"

typedef enum		e_lexstate
{
			state_start,
			state_expr,
			state_lredir,
			state_llredir,
			state_lllredir,
			state_rredir,
			state_rrredir,
			state_pipe,
			state_bg,
			state_listsep,
			state_termsep,
			state_inhibone,
			state_hinhib,
			state_inhib,
			state_end
}			t_lexstate;

typedef struct		s_lexer
{
	char			*strin;
	t_dynstr		outstack;
	t_toktype		nextexprtype;
	t_toktype		actexprtype;
	t_lexstate		state;
	int			inhiblvl;
	t_ldcd			toklist;
}					t_lexer;

typedef t_lexer		*t_lexer_p;

typedef int (*t_lexfunc)(t_lexer_p);


#endif /* !FT_LEXER_TYPE_H */
