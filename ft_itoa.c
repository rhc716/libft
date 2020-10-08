/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:30:03 by hroh              #+#    #+#             */
/*   Updated: 2020/10/08 13:00:02 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*re;
	int		len;

	len = get_len(n);
	re = (char *)malloc(sizeof(char) * (len + 1));
	if (n < 0)
	{
		re[0] = '-';
		n *= -1;
	}
	re[len] = 0;
	len--;
	while (len >= 0)
	{
		re[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (re);
}
