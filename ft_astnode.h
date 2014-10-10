#ifndef FT_AST_H
# define FT_AST_H
# define ASTADD_BRO 0
# define ASTADD_CHILD 1

typedef struct	    s_astnode
{
    struct s_astnode	*parent;
    struct s_astnode	*brother;
    struct s_astnode	*child;
    void		*data;
    int	    		flag;
}		    t_astnode;

typedef t_astnode   *t_astnode_p;

t_astnode_p	ft_astnode_new(void *data, int flag);

void		ft_astnode_del(t_astnode_p *nodep, void(*del)(void **), int rec);

int		ft_astnode_add(t_astnode_p node, t_astnode_p toadd, int flag);
#endif /* !FT_AST_H */
