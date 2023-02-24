/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:31:07 by heloufra          #+#    #+#             */
/*   Updated: 2021/12/20 07:44:27 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*mapped_s;

	mapped_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapped_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped_s[i] = f(i, s[i]);
		i++;
	}
	mapped_s[i] = '\0';
	return (mapped_s);
}
