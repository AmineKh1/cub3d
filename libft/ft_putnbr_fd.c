/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:59:06 by heloufra          #+#    #+#             */
/*   Updated: 2021/12/19 18:17:57 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (n < 0)
	{
		ln = -ln;
		ft_putchar_fd('-', fd);
	}
	if (ln / 10)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(((ln % 10) + '0'), fd);
}
