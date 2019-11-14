/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudouy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:26:40 by acoudouy          #+#    #+#             */
/*   Updated: 2019/11/13 13:39:24 by acoudouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int					i;
	char				*tab;
	int					j;

	i = -1;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
	{
		tab[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		tab[j] = s2[i];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static	char		*ft_nulltab(char *tab)
{
	tab = malloc(1);
	tab[0] = 0;
	return (tab);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*tab;

	tab = 0;
	i = 0;
	if (len == 0 || s == 0)
		return (ft_nulltab(tab));
	while (s[i] && i < start)
		i++;
	if (i != start)
		return (ft_nulltab(tab));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
	{
		free(tab);
		return (0);
	}
	i = -1;
	while (s[start + ++i] && i < len)
		tab[i] = s[start + i];
	tab[i] = '\0';
	return (tab);
}
