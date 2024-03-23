/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:07:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/17 10:27:46 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(va_list args)
{
	char	c;
	int		result;

	result = 0;
	c = va_arg(args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	result++;
	return (result);
}

int	ft_print_s(va_list args)
{
	char	*str;
	int		i;
	int		result;

	result = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		result++;
		i++;
	}
	return (result);
}

int	ft_print_i(va_list args)
{
	int		i;
	int		n;
	char	*str;
	int		result;

	result = 0;
	n = va_arg(args, int);
	str = ft_itoa(n);
	if (str == NULL)
	{
		write(1, "Conversion Error", 18);
		return (-1);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		result++;
		i++;
	}
	free(str);
	return (result);
}

int	ft_print_u(va_list args)
{
	char			*str;
	unsigned int	n;
	int				i;
	int				result;

	result = 0;
	i = 0;
	n = va_arg(args, unsigned int);
	str = ft_utoa(n);
	if (!str)
	{
		write(1, "Conversion Error", 18);
		return (-1);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		result++;
		i++;
	}
	free(str);
	return (result);
}

// int main()
// {
// 	// Example 1: Printing a character
// 	ft_printf("Character: %c\n", 'A');
// 	printf("Character: %c\n", 'A');

// 	// Example 2: Printing a string
// 	ft_printf("String: %s\n", "Hello, World!");
// 	printf("String: %s\n", "Hello, World!");

// 	// Example 3: Printing an integer
// 	ft_printf("Integer: %d\n", 42348);
// 	printf("Integer: %d\n", 42348);

//     // Example 4: Printing an unsigned integer
// 	ft_printf("Unsigned Integer: %u\n", 123);
// 	printf("Unsigned Integer: %u\n", 123);

// 	return 0;
// }
