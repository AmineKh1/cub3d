/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:27:22 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/13 12:06:21 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ft_strlen_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (base[i] == '\0' && i > 1)
		return (i);
	return (0);
}

void	ft_putnbr_base(unsigned long int nbr, char *base, int *count)
{
	unsigned int		i;
	unsigned long int	nb;

	i = ft_strlen_check(base);
	nb = nbr;
	if (i != 0)
	{
		if (nb >= i)
		{
			ft_putnbr_base(nb / i, base, count);
			ft_putchar_fd(base[nb % i], 1, count);
		}
		if (nb < i)
		{
			ft_putchar_fd(base[nb], 1, count);
		}
	}
}
