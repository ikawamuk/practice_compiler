/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:50:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 15:19:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stddef.h>

typedef enum {
	TK_RESERVED,
	TK_IDENT,
	TK_NUM,
	TK_EOF,
	TK_ERROR
}	t_tk_type;

typedef struct s_token t_token;

struct s_token
{
	t_tk_type	type;
	const char	*str;
	size_t		len;
	t_token		*next;
	// for digit
	int			val;
};

#endif
