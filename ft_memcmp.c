/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:43:41 by hroh              #+#    #+#             */
/*   Updated: 2020/10/06 16:49:26 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;
	unsigned char *t_s1;
	unsigned char *t_s2;

	i = 0;
	t_s1 = s1;
	t_s2 = s2;
	while (i < n)
	{
		if (t_s1[i] != t_s2[i])
		{
			return (t_s1[i] - t_s2[i]);
		}
		i++;
	}
	return (0);
}
