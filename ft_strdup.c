/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:56:59 by hroh              #+#    #+#             */
/*   Updated: 2020/10/07 19:08:00 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*re;
	size_t	len;

	len = strlen(str);
	if (!(re = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(re, str, len);
	return (re);
}
