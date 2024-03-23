/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:50:30 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/17 10:27:44 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_add(unsigned long n)
{
	int	dgt;

	dgt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		dgt++;
		n /= 16;
	}
	return (dgt);
}

char	*ft_putadd(unsigned long n)
{
	char	*str;
	int		dgt;
	int		tmp;

	dgt = ft_count_add(n);
	str = malloc(sizeof(char) * (dgt + 1));
	if (str == NULL)
		return (NULL);
	str[dgt] = '\0';
	dgt--;
	while (dgt >= 0)
	{
		tmp = n % 16;
		if (tmp > 9)
			str[dgt] = ft_chexi(tmp);
		else
			str[dgt] = tmp + '0';
		n /= 16;
		dgt--;
	}
	return (str);
}

// int main(void)
// {
// 	unsigned long n = 15;

// 	// Call ft_putadd to get the hexadecimal representation
// 	char *result = ft_putadd(n);

// 	if (result != NULL)
// 	{
// 		printf("Decimal: %lu\n", n);
// 		printf("Hexadecimal: %s\n", result);

// 		// Free the dynamically allocated memory
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}

// 	return 0;
// }
