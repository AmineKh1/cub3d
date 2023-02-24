/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:58:11 by heloufra          #+#    #+#             */
/*   Updated: 2021/12/20 07:44:10 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*un_s1;
	unsigned char	*un_s2;
	size_t			i;

	i = 0;
	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (un_s1[i] != un_s2[i] || !un_s1[i])
			return (un_s1[i] - un_s2[i]);
		i++;
	}
	return (0);
}
