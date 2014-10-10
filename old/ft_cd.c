int		ft_cd(t_cmd cmd)
{
	char	*temp;
	char	*cwd;
	char	*home;
	int		ret;

	home = NULL;
	temp = ft_getenv("PWD", *(cmd->env));
	if (!cmd->av[1])
		home = ft_getenv("HOME", *(cmd->env));
	if ((!home && !cmd->av[1])
		|| (ret = cmd->av[1] ? chdir(cmd->av[1]) : chdir(home)))
	{
		ft_printerror("cd", cmd->av[1], 2, 1);
		return (-1);
	}
	cwd = getcwd(NULL, 0);
	ft_setenv("PWD", cwd, 1, cmd->env);
	if (temp)
		ft_setenv("OLDPWD", temp, 1, cmd->env);
	else
		ft_setenv("OLDPWD", cwd, 1, cmd->env);
	ft_strdel(&temp);
	ft_strdel(&cwd);
	return (0);
}


