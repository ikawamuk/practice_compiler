/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:50:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:07:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H


typedef enum {
	TK_RESERVED,
	TK_NUM,
	TK_EOF
}	t_tk_type;

typedef struct s_token t_token;

struct s_token
{
	t_tk_type	type;
	union {
		int		val;
		char	op;
	}			data;
	t_token		*next;
};

#endif
