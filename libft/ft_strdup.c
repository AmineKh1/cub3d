/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:42:59 by heloufra          #+#    #+#             */
/*   Updated: 2021/12/20 03:41:46 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (p);
	i = 0;
	while (*s1)
	{
		p[i++] = *s1++;
	}
	p[i] = '\0';
	return (p);
}
