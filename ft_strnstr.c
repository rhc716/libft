/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 04:03:47 by hroh              #+#    #+#             */
/*   Updated: 2020/10/08 16:09:33 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j])
			{
				if (big[i + j] != little[j])
				{
					i++;
					break ;
				}
				if (little[j + 1] == 0)
					return ((char *)big + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
