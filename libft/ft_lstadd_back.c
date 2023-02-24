/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:22:05 by heloufra          #+#    #+#             */
/*   Updated: 2022/01/05 08:37:56 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tracer;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tracer = *lst;
	while (tracer)
	{
		if (!tracer->next)
			break ;
		tracer = tracer->next;
	}
	tracer->next = new;
}
