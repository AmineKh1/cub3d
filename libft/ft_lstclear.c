/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 03:57:39 by heloufra          #+#    #+#             */
/*   Updated: 2022/01/04 04:05:56 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tracer;
	t_list	*next;

	tracer = *lst;
	while (tracer)
	{
		next = tracer->next;
		ft_lstdelone(tracer, del);
		tracer = next;
	}
	*lst = NULL;
}
