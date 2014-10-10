/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 23:27:32 by tseguier          #+#    #+#             */
/*   Updated: 2014/06/28 19:46:19 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTINS_H
# define FT_BUILTINS_H
# include "ft_cmd.h"
# define ENV_SEP '='

int		ft_env(t_cmd cmd);

char	*ft_getenv(const char *name, char **env);

int		ft_setenv_built(t_cmd cmd);

int		ft_history(t_cmd cmd);

int		ft_cd(t_cmd cmd);

int		ft_unsetenv(t_cmd cmd);

int		ft_exit(t_cmd cmd);

int		ft_setenv(char *name, char *val, int over, char ***env);

int		ft_echo(t_cmd cmd);

int		ft_basename(t_cmd cmd);

#endif
