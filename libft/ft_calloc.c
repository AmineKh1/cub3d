/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:35:52 by heloufra          #+#    #+#             */
/*   Updated: 2022/01/05 12:48:32 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		n;

	n = count * size;
	p = malloc(n);
	if (!p)
		return (NULL);
	while (n--)
	{
		((unsigned char *)p)[n] = 0;
	}
	return (p);
}
