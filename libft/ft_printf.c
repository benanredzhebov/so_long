/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:42:28 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/17 10:46:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(va_list args, const char *format, int *i)
{
	int	result;

	result = 0;
	*i = *i + 1;
	if (format[*i] == 'c')
		result += ft_print_c(args);
	else if (format[*i] == 's')
		result += ft_print_s(args);
	else if (format[*i] == 'i' || format[*i] == 'd')
		result += ft_print_i(args);
	else if (format[*i] == 'u')
		result += ft_print_u(args);
	else if (format[*i] == 'x' || format[*i] == 'X')
		result += ft_print_x(args, format[*i]);
	else if (format[*i] == 'p')
		result += ft_print_p(args);
	else if (format[*i] == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		result++;
	}
	return (result);
}

int	checkformat(va_list args, const char *format, int *i, int *result)
{
	int	tmp;

	tmp = check(args, format, i);
	if (tmp == -1)
		return (-1);
	else
		*result += tmp;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	result = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (checkformat(args, format, &i, &result) == -1)
				return (-1);
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}

// int	main()
// {
// 	//Test with different format specifiers
// 	ft_printf("Hello, %s!\n", "world");
// 	printf("Hello, %s!\n", "world");

// 	ft_printf("Number: %d\n", 42);
// 	printf("Number: %d\n", 42);

// 	ft_printf("Character: %c\n", 'A');
// 	printf("Character: %c\n", 'A');

// 	ft_printf("Hexadecimal: %x\n", 255);
// 	printf("Hexadecimal: %x\n", 255);

// 	int len1 = ft_printf("Pointer address: %p\n", (void *)-1);
// 	int len2 = printf("Pointer address: %p\n", (void *)-1);

// 	printf("%i %i\n", len1, len2);

// 	//Test with a custom format specifier ('%')
// 	ft_printf("Double percent: %%\n");
// 	printf("Double percent: %%\n");

// 	return 0;
// }

// int	main(void)
// {

// 	int len = printf("Leo\n");
// 	printf("Original = %i\n", len);

// 	len = ft_printf("Leo\n");
// 	printf("Mine = %i\n", len);

// 	len = ft_printf("%c\n", 'v');
// 	printf("Original = %i\n", len);

// 	len = ft_printf("%c\n", 'v');
// 	printf("Mine = %i\n", len);

// 	len = printf("%s\n", "String");
// 	printf("Original = %i\n", len);

// 	len = ft_printf("%s\n", "String");
// 	printf("Mine = %i\n", len);

// 	len = printf("%%\n");
// 	printf("Original = %i\n", len);

// 	len = ft_printf("%%\n");
// 	printf("Mine = %i\n", len);
// }
