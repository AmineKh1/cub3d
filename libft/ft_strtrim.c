/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:35:42 by heloufra          #+#    #+#             */
/*   Updated: 2021/12/20 03:54:17 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;

	first = 0;
	last = ft_strlen(s1) - 1;
	while (first < last + 1 && ft_strchr(set, s1[first]) != NULL)
	{
		first++;
	}
	while (last >= 0 && ft_strchr(set, s1[last]) != NULL)
	{
		last--;
	}
	if (first > last)
		return (ft_strdup(""));
	return (ft_substr(s1, first, last - first + 1));
}
