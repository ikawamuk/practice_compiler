/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:11:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 21:18:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

t_tree	*new_ident_leaf(const char *str);

t_tree	*ident(t_token **token_p)
{
	t_tree	*node = new_ident_leaf((*token_p)->str);
	*token_p = (*token_p)->next;
	return (node);
}