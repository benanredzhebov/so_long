/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:12:43 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/17 10:25:41 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ndigits(unsigned int n)
{
	int	digit_count;

	digit_count = 1;
	if (n == 0)
		return (digit_count);
	while (n > 9)
	{
		digit_count++;
		n /= 10;
	}
	return (digit_count);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		dgt;
	int		i;

	dgt = ft_ndigits(n);
	i = dgt;
	str = malloc(sizeof(char) * (dgt + 1));
	if (!str)
		return (NULL);
	while (i > 0)
	{
		str[--i] = (n % 10) + '0';
		n /= 10;
	}
	str[dgt] = '\0';
	return (str);
}

// int main() {
// 	// Test ft_utoa
// 	unsigned int num = 12345;

// 	char *result = ft_utoa(num);

// 	if (result != NULL) {
// 		printf("Result: %s\n", result);
// 		free(result);  // Don't forget to free the allocated memory
// 	}

// 	return 0;
// }
