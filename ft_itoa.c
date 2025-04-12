/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:15:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/12 13:20:09 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_itoa_10(long n)
{
	int		len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		signal;
	int		len;
	long	nn;
	char	*result;

	signal = 1;
	if (n < 0)
	{
		signal = -1;
		nn = n * -1;
	} else
		nn = n;
	len = len_itoa_10(n);
	result = ft_calloc(len + 1, sizeof (*result));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (nn > 9)
	{
		result[len - 1] = (char) (nn % 10 + 48);
		nn /= 10;
		len--;
	}
	if (signal == -1)
		result[len] = '-';
		
	printf("ft_itoa in: %d %s\n", n, result);
	
	return (result);
}
