/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 07:36:29 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/11 07:36:30 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft_files/libft.h"

static void	sort_out_percent(va_list args, const char str, int *totalchars)
{
	if (ft_strchr("id", str) != NULL)
		ft_percentage_id(args, totalchars);
	else if (ft_strchr("xX", str) != NULL)
		ft_percentage_x(args, str, totalchars);
	else if (ft_strchr("c%", str) != NULL)
		ft_percentage_chars(args, str, totalchars);
	else if (ft_strchr("u", str) != NULL)
		ft_percentage_u(args, totalchars);
	else if (ft_strchr("p", str) != NULL)
		ft_percentage_p(args, totalchars);
	else if (ft_strchr("s", str) != NULL)
		ft_percentage_s(args, totalchars);
}

int	ft_printf(const char *str, ...)
{
	int		totalchars;
	va_list	args;

	totalchars = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str != '%')
		{
			write(1, str, 1);
			str++;
			totalchars++;
		}
		if (*str && *str == '%')
			sort_out_percent(args, *(str + 1), &totalchars);
		if (*str == '\0')
			return (totalchars);
		str += 2;
	}
	va_end(args);
	return (totalchars);
}
/*
#include <stdio.h>

int	main()
{
	printf("\033[35mC TESTS\033[0m\n\n");
	//plain printf
	printf("\033[34mcheck no input\033[0m\n");
	int myversion;
    int real; 
	
	myversion = ft_printf("no percentage\n");
	real = printf("no percentage\n");
	if (myversion == real)
		printf("\033[32m[1] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[1] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);

	//c as character
	printf("\033[34mcheck c as a char\033[0m\n");
	myversion = ft_printf("CHAR: %c\n", 'A');
	real = printf("CHAR: %c\n", 'A');
	if (myversion == real)
		printf("\033[32m[2] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[2] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);

	//c as char passed
	printf("\033[34mcheck c as a char passed\033[0m\n");
	char c = 'p';
	myversion = ft_printf("CHAR: %c\n", c);
	real = printf("CHAR: %c\n", c);
	if (myversion == real)
		printf("\033[32m[3] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[3] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	
	//c is a space
	printf("\033[34mcheck c as a space\033[0m\n");
	myversion = ft_printf("CHAR: %c\n", ' ');
	real = printf("CHAR: %c\n", ' ');
	if (myversion == real)
		printf("\033[32m[4] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[4] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	
	//c is a null terminate
	printf("\033[34mcheck c as a null terminate\033[0m\n");
	myversion = ft_printf("CHAR: %c\n", '\0');
	real = printf("CHAR: %c\n", '\0');
	if (myversion == real)
		printf("\033[32m[5] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[5] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	
	//string tests
	printf("\033[35mS TESTS\033[0m\n\n");

	printf("\033[34mcheck empty str\033[0m\n");
	myversion = ft_printf("STR: %s\n", "");
	real = printf("STR: %s\n", "");
	if (myversion == real)
		printf("\033[32m[5] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[5] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	
	printf("\033[34mcheck null str\033[0m\n");
	char *thestr = NULL;
	myversion = ft_printf("STR: %s\n", thestr);
	real = printf("STR: %s\n", thestr);
	if (myversion == real)
		printf("\033[32m[5] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[5] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	
	printf("\033[34mcheck normal str\033[0m\n");
	myversion = ft_printf("STR: %s\n", "Hello!");
	real = printf("STR: %s\n", "Hello!");
	if (myversion == real)
		printf("\033[32m[5] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[5] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	

	//P tests
	printf("\033[35mP TESTS\033[0m\n\n");

	printf("\033[34mcheck null pointer\033[0m\n");
	myversion = ft_printf("STR: %p\n", thestr);
	real = printf("STR: %p\n", thestr);
	if (myversion == real)
		printf("\033[32m[5] %i == %i: Test PASSED!\033[0m\n\n", myversion, real);
	else
		printf("\033[31m[5] %i != %i: Test FAILED!\033[0m\n\n", myversion, real);
	
}
*/
