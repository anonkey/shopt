#include <stdlib.h>
#include "ft_astnode.h"
#include "libft.h"

t_astnode_p	ft_astnode_new(void *data, int flag)
{
    t_astnode_p	    newnode;

    if (!(newnode = (t_astnode_p)ft_memalloc(sizeof(t_astnode))))
	return (NULL);
    newnode->data = data;
    newnode->flag = flag;
    return (newnode);
}

void		ft_astnode_del(t_astnode_p *nodep, void(*del)(void **), int rec)
{
    if (!nodep || !*nodep)
	return ;
    if (del)
	(*del)(&((*nodep)->data));
    if (rec)
    {
	ft_astnode_del(&((*nodep)->brother), del, rec);
	ft_astnode_del(&((*nodep)->child), del, rec);
    }
    ft_memdel((void **)nodep);
}

int		ft_astnode_add(t_astnode_p node, t_astnode_p toadd, int flag)
{
    t_astnode_p	    iter;

    toadd->parent = flag == ASTADD_BRO ? node->parent : node;
    toadd->brother = NULL;
    toadd->child = NULL;
    iter = node;
    if (flag == ASTADD_BRO)
    {
        while (iter->brother)
	   iter = iter->brother;
	 iter->brother = toadd;
    }
    else
    {
	if (iter->child)
	{
	    iter = iter->child;
	    while (iter->brother)
		iter = iter->brother;
	    iter->brother = toadd;
	}
	else
	    iter->child = toadd;
    }
    return (0);
}
