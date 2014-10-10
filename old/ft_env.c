int		ft_env(t_cmd cmd)
{
	int		i;

	i = 0;
	while ((*(cmd->env))[i])
	{
		ft_putendl((*(cmd->env))[i]);
		++i;
	}
	return (0);
}
