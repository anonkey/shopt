/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 21:08:32 by tseguier          #+#    #+#             */
/*   Updated: 2014/06/26 16:20:15 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include "ft_cmd.h"
# define PIPE_READ_OK 1
# define PIPE_ERROR -1
# define PIPE_EMPTY 0
# define PIPE_RD 1
# define PIPE_WR 2
# define PIPE_RDWR ((PIPE_RD) | (PIPE_WR))

typedef struct	s_pipe
{
	int			pipe0[2];
	int			pipe1[2];
	int			*pipein;
	int			*pipeout;
	t_cmd		cmd;
	int			status;
}				t_spipe;

typedef t_spipe	*t_pipe;

t_pipe			ft_pipenew(void);

void			ft_pipeplug(t_pipe pipex, t_cmd cmd, int flags);

void			ft_pipenext(t_pipe pipex, int flags);

void			ft_pipedel(t_pipe *pipex_p);

#endif
