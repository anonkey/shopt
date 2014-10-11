#include "ft_lang.h"
#include "ft_token.h"
#include "libft.h"
#include "ft_lexer_priv.h"

const char	*g_lexin_tab[NB_INPUT_GROUPS] =
{
    "<",
    ">",
    "|",
    "&",
    ";\n",
    SHELL_IFS,
    "\\",
    "\"",
    "\'",
    "",
    "\0"
};

t_lexstate			ft_getinhib_state(int inhiblvl)
{
    if (inhiblvl & INHIB_LVL_ONE)
	return (state_inhibone);
    if (inhiblvl & INHIB_LVL_MULT)
	return (state_inhib);
    if (inhiblvl & INHIB_LVL_HMULT)
	return (state_hinhib);
    return (state_expr);
}

int	ft_getinind(char c)
{
int	    i;

    i = 0;
    if (!c)
	return (NB_INPUT_GROUPS - 1);
    while (i < NB_INPUT_GROUPS - 2)
    {
	if (ft_strchr(g_lexin_tab[i], c))
	    return (i);
	++i;
    }
    return (NB_INPUT_GROUPS - 2);
}
