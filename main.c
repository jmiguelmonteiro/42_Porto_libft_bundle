/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:30:11 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/05 16:42:29 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

void	test_ft_bzero(void)
{
	char	str1[20] = "to be deleted";
	char	str2[20] = "to be deleted";

	printf("--- Test ft_bzero ---\n");
	//bzero
	printf("bzero: %s\n", str1);
	bzero(str1 + 6, 7);
	printf("bzero: %s\n", str1);

	//ft_bzero
	printf("ft_bzero: %s\n", str2);
	ft_bzero(str2 + 6, 7);
	printf("ft_bzero: %s\n\n", str2);
}

void	test_ft_memset(void)
{
	char	str1[20] = "to be deleted";
	char	str2[20] = "to be deleted";

	printf("--- Test ft_memset ---\n");

	//memset
	printf("memset: %s\n", str1);
	memset(str1 + 6, '*', 7);
	printf("memset: %s\n", str1);

	//ft_memset
	printf("ft_memset: %s\n", str2);
	ft_memset(str2 + 6, '*', 7);
	printf("ft_memset: %s\n\n", str2);
}

void	test_ft_strlen(void)
{
	char	str1[20] = "to be deleted";

	printf("--- Test ft_strlen ---\n");

	//strlen
	printf("strlen: %s: %zu\n", str1, strlen(str1));

	//ft_strlen
	printf("ft_strlen: %s: %zu\n\n", str1, ft_strlen(str1));
}

int	main(void)
{
	char	a = '1';
	char	b = 0x80;
	char	c = 'a';

	printf("ft_isalpha(c): %d\n", ft_isalpha(c));
	printf("ft_isalpha(a): %d\n", ft_isalpha(a));
	printf("ft_isdigit 9: %d\n", ft_isdigit('9'));
	printf("ft_isdigit v: %d\n", ft_isdigit('v'));
	printf("ft_isalnum 9: %d\n", ft_isalnum('9'));
	printf("ft_isalnum d: %d\n", ft_isalnum('d'));
	printf("ft_isalnum ?: %d\n", ft_isalnum('?'));
	printf("isascii(a): %d\n", isascii(a));
	printf("ft_isascii(a): %d\n", ft_isascii(a));
	printf("isascii(b): %d\n", isascii(b));
	printf("ft_isascii(b): %d\n", ft_isascii(b));
	printf("isprint(a): %d\n", isprint(a));
	printf("ft_isprint(a): %d\n", ft_isprint(a));
	printf("isprint(b): %d\n", isprint(b));
	printf("ft_isprint(b): %d\n", ft_isprint(b));
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
}
