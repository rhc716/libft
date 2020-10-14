/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:06:53 by hroh              #+#    #+#             */
/*   Updated: 2020/10/12 15:47:43 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			continue;
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

static int	get_word_length(char *start, int *start_move, char c)
{
	int word_len;

	word_len = 0;
	while (start[*start_move] == c)
		(*start_move)++;
	while (start[*start_move] != c)
	{
		word_len++;
		(*start_move)++;
	}
	while (start[*start_move] == c)
		(*start_move)++;
	return (word_len);
}

static int	split_string_words(char **re, char *start, char c, int wd_cnt)
{
	int	i;
	int	word_len;
	int	start_move;

	i = 0;
	word_len = 0;
	start_move = 0;
	while (i < wd_cnt)
	{
		start += start_move;
		start_move = 0;
		word_len = get_word_length(start, &start_move, c);
		if (!(re[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
		{
			all_free(re);
			return (-1);
		}
		ft_strlcpy(re[i++], start, word_len + 1);
	}
	re[i] = NULL;
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**re;
	int		wd_cnt;
	char	*start;
	int		i;

	if (!s)
		return (NULL);
	wd_cnt = get_words_count(s, c);
	if (!(re = (char **)malloc(sizeof(char *) * (wd_cnt + 1))))
		return (NULL);
	i = 0;
	start = (char *)s;
	while (start[i] == c)
		i++;
	start += i;
	if (split_string_words(re, start, c, wd_cnt) == -1)
		return (NULL);
	return (re);
}
