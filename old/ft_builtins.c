/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 23:53:41 by tseguier          #+#    #+#             */
/*   Updated: 2014/06/27 11:30:37 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_builtins.h"
#include "ft_error.h"
#define ENV_SEP '='

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

char	*ft_getenv(const char *name, char **env)
{
	int		i;
	char	*ret;
	size_t	namelen;

	i = 0;
	if (!env || !name)
		return (NULL);
	namelen = ft_strlen(name);
	while (env[i] && (ft_strncmp(env[i], name, namelen)
						|| env[i][namelen] != ENV_SEP))
		++i;
	ret = env[i] ? ft_strdup(env[i] + namelen + 1) : NULL;
	return (ret);
}

int		ft_setenv(char *name, char *val, int over, char ***env)
{
	int		i;
	size_t	namelen;
	int		err;

	i = 0;
	if (!name || !env || !*env)
		return ((env && !*env) ? -2 : -1);
	namelen = ft_strlen(name);
	while ((*env)[i] && ft_strncmp((*env)[i], name, namelen))
		++i;
	if (!(*env)[i])
		ft_strtabrealloc(env, 1);
	if (over && (*env)[i])
		ft_strdel(&((*env)[i]));
	if (!(*env)[i])
	{
		if (!((*env)[i] = ft_strjoin(name, "=")))
			return (-3);
	}
	val = val ? val : "";
	if ((*env)[i][namelen + 1])
		err = ft_strsepjoin(&((*env)[i]), val, ":");
	else
		err = ft_strsepjoin(&((*env)[i]), val, "");
	return (err);
}

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
