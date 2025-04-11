/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/11 18:24:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strltrim(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (ft_substr(s1, i, ft_strlen(s1) - i));
}

static char	*ft_strrtrim(char const *s1, char const *set)
{
	int		i;

	i = ft_strlen(s1);
	while (s1[i - 1] && ft_strrchr(set, s1[i - 1]))
		i--;
	return (ft_substr(s1, 0, i));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*rs1;
	int		i;

	*str = (char *) s1;
	i = ft_strlen(s1);
	while (str[i - 1] && ft_strrchr(set, str[i - 1]))
		i--;
	str[i] = '\0';
	
	ls1 = ft_strltrim(s1, set);
	if (ls1)
	{
		rs1 = ft_strrtrim(ls1, set);
		free (ls1);
		if (rs1)
			return (rs1);
	}
	return (NULL);
}
