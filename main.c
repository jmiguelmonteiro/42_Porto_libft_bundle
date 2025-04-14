/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:30:11 by josemigu          #+#    #+#             */
/*   Updated: 2025/04/14 20:02:05 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"
#include "stdlib.h"
#include <limits.h>

void hexDump(char *desc, void *addr, int len) 
{
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf("  %s\n", buff);

            // Output the offset.
            printf("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf(" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) {
            buff[i % 16] = '.';
        } else {
            buff[i % 16] = pc[i];
        }

        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf("  %s\n", buff);
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

void	test_ft_memcpy(void)
{
	char	src1[] = "source";
	char	dest1[10];
	char	src2[] = "source";
	char	dest2[10];

	printf("--- Test ft_memcpy ---\n");
	//memcpy
	memcpy(dest1, src1, sizeof(src1));
	printf("memcpy src: %s dest: %s\n", src1, dest1);
	//ft_memcpy
	ft_memcpy(dest2, src2, sizeof(src2));
	printf("ft_memcpy src: %s dest: %s\n\n", src2, dest2);
}

void	test_ft_memmove(void)
{
	char	s1[100] = "0123456789";
	char	s2[100] = "0123456789";
/* 	char	s3[100] = "0123456789";
	char	s4[100] = "0123456789";
 */
	printf("--- Test ft_memmove ---\n");
	//ft_memmove
	memmove(s1 + 0, s1 + 1, 4);
	printf("ft_memmove Resultado: %s\n", s1);
	memmove(s2 + 1, s2 + 0, 4);
	printf("ft_memmove Resultado: %s\n", s2);
	printf("\n");
}

void	test_ft_strlcat(void)
{
	char	dst11[] = "Ola";
	char	dst12[] = "Ola";
	char	dst13[] = "Ola";
	char	src[] = "42";
	int		n;

	printf("--- Test ft_strlcat ---\n");
	n = ft_strlcat(dst13, src, 2);
	printf("ft_strlcat Resultado: '%s' '%s' %d\n", dst11, src, n);
	n = ft_strlcat(dst12, src, 5);
	printf("ft_strlcat Resultado: '%s' '%s' %d\n", dst12, src,n);
	n = ft_strlcat(dst11, src, 7);
	printf("ft_strlcat Resultado: '%s' '%s' %d\n", dst13, src,n);
	printf("\n");
}

void	test_ft_toupper(void)
{
	printf("--- Test ft_toupper ---\n");
	//ft_toupper
	printf("ft_toupper 'a': %c\n", ft_toupper('a'));
	printf("ft_toupper 'S': %c\n", ft_toupper('S'));
	printf("ft_toupper '-': %c\n", ft_toupper('-'));
	printf("\n");
}

void	test_ft_strchr(void)
{
	char	*str = "Test";
	char	*str_nil = "";

	printf("--- Test ft_strchr ---\n");
	//ft_strchr
	printf("ft_strchr 'Test' 'e': %p %p\n", str, ft_strchr(str, 'e'));
	printf("ft_strchr 'Test' 'a': %p %p\n", str, ft_strchr(str, 'a'));
	printf("ft_strchr 'Test' '\\0': %p %p\n", str, ft_strchr(str, '\0'));
	printf("ft_strchr '\\0' '\\0': %p %p\n", str_nil, ft_strchr(str_nil, '\0'));
	printf("ft_strchr '\\0' 'a': %p %p\n", str_nil, ft_strchr(str_nil, 'a'));
	printf("\n");
}

void	test_ft_strrchr(void)
{
	char	*str = "test";
	char	*str_nil = "";

	printf("--- Test ft_strrchr ---\n");
	//ft_strrchr
	printf("ft_strrchr 'test' 't': %p %p\n", str, ft_strrchr(str, 't'));
	printf("ft_strrchr 'test' 'a': %p %p\n", str, ft_strrchr(str, 'a'));
	printf("ft_strrchr 'test' '\\0': %p %p\n", str, ft_strrchr(str, '\0'));
	printf("ft_strrchr '\\0' '\\0': %p %p\n", str_nil, ft_strrchr(str_nil, '\0'));
	printf("ft_strrchr '\\0' 'a': %p %p\n", str_nil, ft_strrchr(str_nil, 'a'));
	printf("\n");
}

void	test_ft_strncmp(void)
{
	printf("--- Test ft_strncmp ---\n");
	//ft_strncmp
	printf("ABC ABC 3: %d\n", ft_strncmp("ABC", "ABC", 3));
	printf("ABC ABD 2: %d\n", ft_strncmp("ABC", "ABD", 2));
	printf("ABC AB 5: %d\n", ft_strncmp("ABC", "AB", 5));
	printf("ABA ABZ 5: %d\n", ft_strncmp("ABA", "ABZ", 5));
	printf("ABJ ABC 5: %d\n", ft_strncmp("ABJ", "ABC", 5));
	printf("ABC\\200 ABC\\0 5: %d\n", ft_strncmp("ABC\200", "ABC\0", 5));
	printf("\n");
}

void	test_ft_memchr(void)
{
	char	*str = "Test";
	char	*str_nil = "";

	printf("--- Test ft_memchr ---\n");
	//ft_memchr
	printf("ft_memchr 'Test' 't' 10: %p %p\n", str, ft_memchr(str, 't', 10));
	printf("ft_memchr 'Test' 't' 3: %p %p\n", str, ft_memchr(str, 't', 3));
	printf("ft_memchr '\\0' '\\0' 0: %p %p\n", str_nil, ft_memchr(str_nil, '\0', 0));
	printf("ft_memchr '\\0' '\\0' 1: %p %p\n", str_nil, ft_memchr(str_nil, '\0', 1));
	printf("\n");
}

void	test_ft_memcmp(void)
{
	char	*str1 = "ABC";
	char	*str2 = "ABD";
	char	*str3 = "AB";
	char	*str4 = "ABA";
	char	*str5 = "ABZ";
	
	printf("--- Test ft_memcmp ---\n");
	//ft_memcmp
	printf("ABC ABC 3: %d\n", ft_memcmp(str1, str1, 3));
	printf("ABC ABD 2: %d\n", ft_memcmp(str1, str2, 2));
	printf("ABC AB 5: %d\n", ft_memcmp(str1, str3, 5));
	printf("ABA ABZ 5: %d\n", ft_strncmp(str4, str5, 5));
	printf("\n");
}

void	test_ft_strnstr(void)
{
	char	*str1 = "Foo Bar Baz";
	char	*str2 = "Bar";
	
	printf("--- Test ft_strnstr ---\n");
	//ft_strnstr
	printf("'%s' '%s' 4'': %s\n", str1, str2, ft_strnstr(str1, str2, 4));
	printf("'%s' '%s' 7'': %s\n", str1, str2, ft_strnstr(str1, str2, 7));
	printf("'%s' '%s' 5'': %s\n", str1, str2, ft_strnstr(str1, str2, 5));
	printf("\n");
}

void	test_ft_atoi(void)
{
	printf("--- Test ft_atoi ---\n");
	//ft_atoi
	printf("ft_atoi('10'): %d\n", ft_atoi("\007 8"));
	printf("ft_atoi('0'): %d\n", ft_atoi("0"));
	printf("ft_atoi('  \t-020'): %d\n", ft_atoi("  \t-020"));
	printf("atoi('8748327483274873498'): %d\n", atoi("8748327483274873498"));
	printf("ft_atoi('8748327483274873498'): %d\n", ft_atoi("8748327483274873498"));
	printf("atoi('-8748327483274873498'): %d\n", atoi("-8748327483274873498"));
	printf("ft_atoi('-8748327483274873498'): %d\n", ft_atoi("-8748327483274873498"));
	printf("\n");
}

void	test_ft_calloc(void)
{
	void	*ptr;
	void	*ptr2;
	
	printf("--- Test ft_calloc ---\n");
	ptr = ft_calloc(0, 0);
	printf("ft_calloc: %p\n", ptr);
	hexDump("Unique pointer", ptr, 1);
	free(ptr);
	ptr2 = ft_calloc(10, 5);
	printf("ft_calloc: %p\n", ptr2);
	hexDump("Unique pointer", ptr2, 50);
	free(ptr2);
	printf("\n");
}

void	test_ft_strdup(void)
{
	char *test = "Test";
	char *dest_test;
	
	printf("--- Test ft_strdup ---\n");
	dest_test = ft_strdup(test);
	printf("ft_strdup source: %s\n", test);
	printf("ft_strdup dest: %s\n", dest_test);
	printf("\n");
	free(dest_test);
}

void	test_ft_strtrim(void)
{
	char *test = " 3123 45 3";

	printf("--- Test ft_strtrim ---\n");
	printf("ft_strtrim: '%s' '%s'\n", test, ft_strtrim(test, " 3"));
	printf("\n");
}

void	test_ft_split(void)
{
	char *test = " 3123 45 3 dsa d a sf f  sd f fsg sf fsg fdg       fdgdsfg df      ";

	printf("--- Test ft_split ---\n");
	ft_split(test, ' ');
//	printf("ft_split: '%s' %d\n", test, ft_split(test, " "));
	printf("\n");
}

void	test_ft_itoa(void)
{
	char 	*str;
	
	
	printf("--- Test ft_itoa ---\n");
	str = ft_itoa(0);
	printf("ft_itoa: %d '%s'\n", 0, str);
	printf("ft_itoa: %d '%s'\n", 1436, ft_itoa(1436));
	printf("ft_itoa: %d '%s'\n", -36, ft_itoa(-36));
	printf("ft_itoa: %d '%s'\n", 0, ft_itoa(0));
	printf("ft_itoa: %d '%s'\n", INT_MIN, ft_itoa(INT_MIN));
	printf("\n");
}

void	test_ft_putnbr_fd(void)
{
	printf("--- Test ft_putnbr_fd ---\n");
	printf("ft_putnbr_fd: 0\n");
	ft_putnbr_fd(0, 1);
	printf("\nft_putnbr_fd: 1436\n");
	ft_putnbr_fd(1436, 1);
	printf("\nft_putnbr_fd: -36\n");
	ft_putnbr_fd(-36, 1);
	printf("\nft_putnbr_fd: &d\n", INT_MIN);
	ft_putnbr_fd(INT_MIN, 1);
	printf("\nft_putnbr_fd: &d\n", INT_MAX);
	ft_putnbr_fd(INT_MAX, 1);
	printf("\n\n");
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
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	test_ft_calloc();
	test_ft_strdup();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_putnbr_fd();
}
