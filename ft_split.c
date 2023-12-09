/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:30:41 by hfazaz            #+#    #+#             */
/*   Updated: 2023/12/05 20:02:48 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
		{
			s++;
		}
		if (*s)
		{
			count++;
			while (*s && *s != c)
			{
				s++;
			}
		}
	}
	return (count);
}

static char	*extract_word(const char *s, char c, int *index)
{
	int		i;
	int		start;
	char	*word;

	i = *index;
	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	word = ft_substr(s, start, i - start);
	*index = i;
	return (word);
}

static void	free_memory(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		index;
	int		word_count;
	char	**str;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	str = ft_calloc(word_count + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	index = 0;
	while (i < word_count)
	{
		str[i] = extract_word(s, c, &index);
		if (!str[i])
		{
			free_memory(str);
			return (NULL);
		}
		i++;
	}
	return (str);
}
