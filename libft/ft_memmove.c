/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:38:59 by heloufra          #+#    #+#             */
/*   Updated: 2021/12/20 07:46:06 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*un_dst;
	unsigned char	*un_src;

	un_dst = (unsigned char *)dst;
	un_src = (unsigned char *)src;
	if (dst > src)
	{
		while (n--)
			un_dst[n] = un_src[n];
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
