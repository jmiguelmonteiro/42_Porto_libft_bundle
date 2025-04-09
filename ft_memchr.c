/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/09 13:14:28 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_s;

	i = 0;
	ptr_s = (const unsigned char *) s;
	while (i < n)
	{
		if (ptr_s[i] == c)
			return ((void *)&ptr_s[i]);
		i++;
	}
	return (NULL);
}
