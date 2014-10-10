/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 20:25:41 by tseguier          #+#    #+#             */
/*   Updated: 2014/06/27 09:15:18 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_pipex.h"
#include "libft.h"

t_pipe	ft_pipenew(void)
{
	t_pipe	newpipe;

	newpipe = (t_pipe)ft_memalloc(sizeof(struct s_pipe));
	if (!newpipe)
		return (NULL);
	newpipe->pipe0[0] = -1;
	newpipe->pipe0[1] = -1;
	newpipe->pipe1[0] = -1;
	newpipe->pipe1[1] = -1;
	if (-1 == pipe(newpipe->pipe0))
		newpipe->status = PIPE_ERROR;
	else
	{
		newpipe->pipein = newpipe->pipe0;
		newpipe->pipeout = newpipe->pipe1;
		newpipe->status = PIPE_EMPTY;
	}
	return (newpipe);
}

void	ft_pipeplug(t_pipe pipex, t_cmd cmd, int flags)
{
	if (pipex->status == -1)
		return ;
	if (flags & PIPE_WR)
	{
		cmd->fdout = pipex->pipein[1];
		close(pipex->pipein[0]);
	}
	if (pipex->status == PIPE_READ_OK && flags & PIPE_RD)
	{
		cmd->fdin = pipex->pipeout[0];
		close(pipex->pipeout[1]);
	}
}

void	ft_pipenext(t_pipe pipex, int flags)
{
	int		*temp;

	if (-1 != pipex->pipeout[0])
	{
		close(pipex->pipeout[0]);
		pipex->pipeout[0] = -1;
	}
	if (-1 != pipex->pipein[1])
	{
		close(pipex->pipein[1]);
		pipex->pipein[1] = -1;
	}
	if (-1 == pipe(pipex->pipeout))
	{
		pipex->status = PIPE_ERROR;
		return ;
	}
	temp = pipex->pipein;
	pipex->pipein = pipex->pipeout;
	pipex->pipeout = temp;
	pipex->status = (flags & PIPE_WR) ? PIPE_READ_OK : PIPE_EMPTY;
}

void	ft_pipedel(t_pipe *pipex_p)
{
	ft_memdel((void **)pipex_p);
	*pipex_p = NULL;
}
