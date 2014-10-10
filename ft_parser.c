#include "ft_parser.h"
#include "ft_lang.h"

int		ft_getparsin_ind(t_toktype type)
{
    int	    ind;

    if (0 == (ind = ft_get_prior(type)))
	return (-1);
    ind = (ind < 5) ? ind - 1 : ind - 2;
    return (ind);
}

int		ft_pushonstack(t_parser_p pars)
{
    t_token	*tmp;

    while (ft_ldcdsize(pars->oplist)
	    && ft_get_prior(pars->tokin->type) >= ft_get_prior(((t_token *)pars->oplist->tail->content)->type))
    {
	if (!(tmp = ft_ldcdpop_back(pars->oplist)))
	 	return (-1);
        if (-1 == ft_ldcdpush_back(pars->outlist, tmp, 0))
		return (-2);
    }
    if (-1 == ft_ldcdpush_back(pars->oplist, pars->tokin, 0))
        return (-2);
    return (0);
}

int		pushwno(t_parser_p pars)
{
    ft_putendl("\npushwno-------------------------");
    ft_pushonstack(pars);
    pars->state = pstate_wno;
    return (0);
}

int		pushwredirarg(t_parser_p pars)
{
    ft_putendl("\npushwredir-------------------------");
    ft_pushonstack(pars);
    pars->state = pstate_wredirarg;
    return (0);
}

int		pushwcmd(t_parser_p pars)
{
    ft_putendl("\npushwcmd-------------------------");
    ft_pushonstack(pars);
    pars->state = pstate_wcmd;
    return (0);
}

int		pushwsep(t_parser_p pars)
{
    ft_putendl("\npushwsep-------------------------");
    ft_pushonstack(pars);
    pars->state = pstate_wsep;
    return (0);
}

int		pushwnl(t_parser_p pars)
{
    ft_putendl("\npushwnl-------------------------");
    ft_pushonstack(pars);
    pars->state = pstate_wnl;
    return (0);
}

int		pushout(t_parser_p pars)
{
    ft_putendl("\npushout-------------------------");
    if (-1 == ft_ldcdpush_back(pars->outlist, pars->tokin, 0))
	return (-1);
	pars->state = pstate_wno;
    return (0);
}

int		rpnend(t_parser_p pars)
{
    t_token	*tmp;

    pars->state = pstate_end;
    while (0 < ft_ldcdsize(pars->oplist))
    {
	if (!(tmp = (t_token *)ft_ldcdpop_back(pars->oplist)))
	    return (-1);
	if (-1 == ft_ldcdpush_back(pars->outlist, tmp, 0))
	    return (-1);
    }
    return (ft_ldcdpush_back(pars->outlist, pars->tokin, 0));
}

t_parsfunc	g_parsfunc_matrix[NB_PARS_STATES - 1][NB_PARSIN_GROUPS] =
{
	      /* usrinfilename	, redir		, cmdarg    , cmd	    , | &&      ||, bg	    ,   ;	, \n	, end*/
/* start    */{NULL		, NULL		, NULL	    , &pushwno	    , NULL	, NULL	    , &pushwnl	, &pushwnl	, &rpnend},
/* empty    */{NULL		, &pushwredirarg, &pushwno  , &pushwno	    , &pushwcmd	, &pushwsep , &pushwnl	, &pushwnl	, &rpnend},
/* wredirarg*/{&pushout		, NULL		, NULL	    , NULL	    , NULL	, NULL	    ,  NULL	,   NULL	,    NULL},
/* wcmd	    */{NULL		, NULL		, NULL	    , &pushwno	    , NULL	, NULL	    ,   NULL	,   NULL	, NULL},
/* wcmdorsep*/{NULL		, NULL		, NULL	    , &pushwno	    , NULL	, NULL	    ,  &pushwnl, &pushwnl	, &rpnend},
/* wcmdornl*/{NULL		, NULL		, NULL	    , &pushwno	    , NULL	, NULL	    ,  NULL	, &pushwnl	, &rpnend},
};

t_parser_p  ft_parsernew(t_ldcd toklist)
{
    t_parser_p	newpars;

    if (!toklist)
	return (NULL);
    if (!(newpars = (t_parser_p)ft_memalloc(sizeof(t_parser))))
	return (NULL);
    if ((!(newpars->outlist = ft_ldcdnew())) || (!(newpars->oplist = ft_ldcdnew())))
    {
	ft_parserdel(&newpars);
	return (NULL);
    }
    newpars->toklist = toklist;
    newpars->state = pstate_start;
    return (newpars);
}

void	    ft_parserdel(t_parser_p *parsp)
{
    if (!parsp || !*parsp)
	return ;
    ft_ldcddel(&((*parsp)->toklist), NULL);
    ft_ldcddel(&((*parsp)->outlist), NULL);
    ft_ldcddel(&((*parsp)->oplist), NULL);
    ft_memdel((void **)parsp);
}

int	    ft_parsrpn(t_parser_p pars)
{
    int	    ind;
    int	    err;

    while (pars->state != pstate_end)
    {
	ft_putnbr(pars->state);
    if (!(pars->tokin = ft_ldcdpop_front(pars->toklist)))
	    return (-1);
if ('l' == ft_getchar())
{
	ft_putendl("\n\nOUTLIST------------------");
	ft_putldcd(pars->outlist, &ft_putvtoken);

	ft_putendl("\n\nOpLIST------------------");
	ft_putldcd(pars->oplist, &ft_putvtoken);

	ft_putendl("\n\ntokLIST------------------");
	ft_putldcd(pars->toklist, &ft_putvtoken);
}
        if (0 > (ind = ft_getparsin_ind(pars->tokin->type))
	    || !g_parsfunc_matrix[pars->state][ind])
	    return (-2);
	if ((err = g_parsfunc_matrix[pars->state][ind](pars)))
	    return (err);
    }
    return (0);
}

int	    ft_parse(t_parser_p pars)
{
    int	    err;

    if ((err = ft_parsrpn(pars)))
	return (err);
    return (0);
}
