/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/07 11:00:08 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/07 14:39:16 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H
# include "libft.h"
# include "ft_token.h"
# include "ft_lexer_type.h"

void				ft_lexdel(t_lexer_p *lex_p, int dellist);

t_lexer				*ft_lexnew(char *strin);

int				ft_getinput_ind(char c);

int				ft_lexerize(t_lexer_p lex);

#endif /* !FT_LEXER_H */
