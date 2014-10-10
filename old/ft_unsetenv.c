int		ft_unsetenv(t_cmd cmd)
{
	int		i;
	size_t	namelen;

	i = 0;
	if (!cmd->av[1])
	{
		ft_putendl_fd("Usage : unsetenv name", 2);
		return (-1);
	}
	namelen = ft_strlen(cmd->av[1]);
	while ((*(cmd->env))[i]
			&& ft_strncmp((*(cmd->env))[i], cmd->av[1], namelen))
		++i;
	if (!(*(cmd->env))[i])
	{
		ft_printerror("unsetenv", cmd->av[1], 13, 1);
		return (-2);
	}
	ft_strdel(&((*(cmd->env))[i]));
	while ((*(cmd->env))[++i])
		(*(cmd->env))[i] = (*(cmd->env))[i + 1];
	(*(cmd->env))[i] = NULL;
	return (0);
}
