/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:40:11 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:11:35 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int counter;
	int word;

	counter = 0;
	word = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] != c && (s[counter + 1] == c || s[counter + 1] == '\0'))
			word++;
		counter++;
	}
	return (word);
}

static int	word_len(char *s, char c)
{
	int counter;
	int countletter;

	counter = 0;
	countletter = 0;
	while (s[counter] == c && s[counter + 1] != '\0')
		counter++;
	while (s[counter] != c && s[counter] != '\0')
	{
		counter++;
		countletter++;
	}
	return (countletter);
}

static char	*fill(char *tmp, char c)
{
	int		counter1;
	int		len;
	char	*word1;

	len = word_len(tmp, c);
	counter1 = 0;
	word1 = (char *)malloc(len + 1);
	if (!word1)
		return (NULL);
	while (counter1 < len)
	{
		word1[counter1] = *tmp;
		counter1++;
		tmp++;
	}
	word1[counter1] = '\0';
	return (word1);
}

static char	**delete(char **del, int counter)
{
	int runner;

	runner = 0;
	while (runner <= counter)
	{
		free(del[counter]);
		runner++;
	}
	free(del);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		word;
	int		runner;
	int		runner2;

	word = count_word(s, c);
	runner = 0;
	runner2 = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * word + 1);
	if (!split)
		return (NULL);
	while (runner < word && s[runner2] != '\0')
	{
		while (s[runner2] == c)
			runner2++;
		split[runner] = fill(&((char *)s)[runner2], c);
		if (!split[runner])
			return (delete(split, runner));
		runner++;
		runner2 = runner2 + word_len(&((char *)s)[runner2], c);
	}
	split[runner] = NULL;
	return (split);
}
