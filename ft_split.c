/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:25:15 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 19:25:16 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	count_words(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !is_sep(s[i]))
			i++;
	}
	return (count);
}

static int	word_len(const char *s, int start)
{
	int	len;

	len = 0;
	while (s[start + len] && !is_sep(s[start + len]))
		len++;
	return (len);
}

static char	*copy_word(const char *s, int start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s)
{
	char	**arr;
	int		i;
	int		j;
	int		len;

	arr = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i]))
			i++;
		if (s[i])
		{
			len = word_len(s, i);
			arr[j++] = copy_word(s, i, len);
			i += len;
		}
	}
	arr[j] = 0;
	return (arr);
}
