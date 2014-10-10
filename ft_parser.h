#ifndef FT_PARSER_H
# define FT_PARSER_H

# define NB_PARSIN_GROUPS 9
# define NB_PARS_STATES 7
# include "libft.h"
# include "ft_lang.h"
# include "ft_astnode.h"
# include "ft_token.h"

typedef enum	    e_parsstate
{
    pstate_start,
    pstate_wno,
    pstate_wredirarg,
    pstate_wcmd,
    pstate_wsep,
    pstate_wnl,
    pstate_end
}		    t_parsstate;

typedef struct	    s_parser
{
    t_token	    *tokin;
    t_ldcd	    toklist;
    t_ldcd	    oplist;
    t_ldcd	    outlist;
    t_astnode_p	    astree;
    t_astnode_p	    act;
    t_parsstate	    state;
}		    t_parser;

typedef t_parser    *t_parser_p;

typedef int (*t_parsfunc)(t_parser_p);

int		ft_putvtoken(void *tokv);

int		pushop(t_parser_p pars);

int		popop(t_parser_p pars);

int		pushcmd(t_parser_p pars);

int		pushredir(t_parser_p pars);

int		pushout(t_parser_p pars);

int		rpnend(t_parser_p pars);

t_parser_p  ft_parsernew(t_ldcd toklist);

void	    ft_parserdel(t_parser_p *parsp);

int	    ft_parsrpn(t_parser_p pars);

int	    ft_parse(t_parser_p pars);

#endif /* !FT_PARSER_H */