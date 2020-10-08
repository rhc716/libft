/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:06:53 by hroh              #+#    #+#             */
/*   Updated: 2020/10/08 16:07:44 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_word_length(char *start, int *len, char c)
{
	int i;

	start += (*len);
	len = 0;
	i = 0;
	while (start[i] && start[i] == c)
		i++;
	while (start[i] && start[i] != c)
	{
		(*len)++;
		i++;
	}
}

static int	get_words_count(char const *str, char c)
{
	int i;
	int wd_cnt;

	i = 0;
	wd_cnt = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			wd_cnt++;
			while (str[i] && str[i] == c)
				i++;
		}
		i++;
	}
	if (str[i - 1] != c)
		wd_cnt++;
	return (wd_cnt);
}

static char	**all_free(char **re)
{
	int	i;

	i = 0;
	while (re[i])
	{
		free(re[i]);
		i++;
	}
	free(re);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**re;
	char	*wd_start;
	int		wd_cnt;
	int		i;
	int		wd_len;

	if (!s)
		return (NULL);
	wd_cnt = get_words_count(s, c);
	if (!(re = (char **)malloc(sizeof(char *) * (wd_cnt + 1))))
		return (NULL);
	i = 0;
	wd_start = (char *)s;
	while (i < wd_cnt)
	{
		get_word_length(wd_start, &wd_len, c);
		if (!(re[i] = (char *)malloc(sizeof(char) * (wd_len + 1))))
			return (all_free(re));
		ft_strlcpy(re[i], wd_start, wd_len + 1);
		i++;
	}
	re[i] = NULL;
	return (re);
}
