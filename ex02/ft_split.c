/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 12:35:58 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/10 13:00:10 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_is_sep(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !ft_is_sep(str[i], charset))
		i++;
	return (i);
}

char	*ft_word_dup(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	result = malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_is_sep(str[i], charset))
		i++;
		if (str[i] != '\0')
		{
			len = ft_word_len(&str[i], charset);
			result[j] = ft_word_dup(&str[i], len);
			j++;
			i += len;
		}
	}
	result[j] = 0;
	return (result);
}

#include <stdio.h>
int main(int argc, char **argv)
{
    char **result;
    int i;

    if (argc != 3)
        return (1);
    result = ft_split(argv[1], argv[2]);
    if (!result)
        return (1);
    i = 0;
    while (result[i] != 0)
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}
