/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:28:44 by vhacman           #+#    #+#             */
/*   Updated: 2025/01/31 00:48:54 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_split function takes two arguments: s (a string) and c (the separator).
It allocates memory for an array (array) that will store the resulting words
from the string s. The function also uses a variable word_len to store the
length of the current word, and i as the index for inserting words into the 
array.
The function first allocates memory for the array, with one extra slot for the
NULL terminator. Then, inside a loop, it skips over any separators (c) at the
beginning of each word using the line while (*s == c && *s) s++;.
Once a non-separator character is found, the function enters the block 
to process the word.
It uses the ft_strchr function to locate the first occurrence of the separator c.
If c isn't found, it means the rest of the string is a single word, so word_len
is set to the remaining length of the string using ft_strlen(s). If c is found,
word_len is calculated as the distance from s to the separator.
The function then creates a substring of the current word with 
ft_substr(s, 0, word_len) and stores it in the array array[i++]. 
Afterward, the pointer s is moved forward by word_len characters using 
s += word_len;, so it can process the next word in the next loop iteration.
Finally, the function returns the array of words, with the last element 
being NULL to indicate the end of the array.*/

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_len;
	int		i;

	array = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !array)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			array[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	array[i] = NULL;
	return (array);
}

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
/*
int	main(void)
{
	char	**words;
	int		i;

	i = 0;
	words = ft_split("Hello World 42 split function", ' ');
	if (words)
	{
		while (words[i])
		{
			printf("Word %d: %s\n", i, words[i]);
			i++;
		}
	}
	ft_free_split(words);
	return (0);
}*/
