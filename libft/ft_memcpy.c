/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:14:10 by heloufra          #+#    #+#             */
/*   Updated: 2022/01/05 08:54:44 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*un_dst;
	unsigned char	*un_src;
	size_t			i;

	i = 0;
	un_dst = (unsigned char *)dst;
	un_src = (unsigned char *)src;
	while (i < n)
	{
		un_dst[i] = un_src[i];
		i++;
	}
	return (dst);
}
