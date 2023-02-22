/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:51:55 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/13 12:05:49 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] == str2[i] && --n > 0 && str1[i] && str2[i])
		i++;
	if (n == 0)
		return (0);
	return (str1[i] - str2[i]);
}
