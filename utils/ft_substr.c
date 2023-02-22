/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:47:38 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/13 12:05:41 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		str = (char *) malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] && i < start)
		i++;
	while (len-- > 0 && s[i])
		str[l++] = s[i++];
	str[l] = '\0';
	return (&str[0]);
}
