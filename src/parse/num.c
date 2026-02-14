/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:08:53 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 18:41:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

t_tree	*new_num_leaf(int val);

t_tree	*num(t_token **token_p)
{
	t_tree	*node = new_num_leaf((*token_p)->val);
	*token_p = (*token_p)->next;
	return (node);
}
