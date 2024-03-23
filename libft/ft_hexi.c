/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:13:28 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/17 10:24:55 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_hexi(unsigned int n)
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

int	ft_chexi(int tmp)
{
	if (tmp >= 10 && tmp <= 15)
		return (tmp + 'a' - 10);
	return (tmp + '0');
}

int	ft_chexxi(int tmp)
{
	if (tmp >= 10 && tmp <= 15)
		return (tmp + 'A' - 10);
	return (tmp + '0');
}

void	ft_helphexi(char *str, unsigned int n, int dgt, char c)
{
	int	tmp;

	str[dgt] = '\0';
	dgt--;
	while (dgt >= 0)
	{
		tmp = n % 16;
		if (tmp > 9)
		{
			if (c == 'x')
				str[dgt] = ft_chexi(tmp);
			else if (c == 'X')
				str[dgt] = ft_chexxi(tmp);
		}
		else
			str[dgt] = tmp + 48;
		n /= 16;
		dgt--;
	}
}

char	*ft_puthexi(unsigned int n, char c)
{
	char	*str;
	int		dgt;

	dgt = ft_count_hexi(n);
	str = malloc(sizeof(char) * (dgt + 1));
	if (str == NULL)
		return (NULL);
	ft_helphexi(str, n, dgt, c);
	return (str);
}

// int main()
// {
// 	unsigned int num = 305;

// 	// Convert to lowercase hexadecimal
// 	char *hexLower = ft_puthexi(num, 'x');
// 	if (hexLower != NULL) {
// 		printf("Lowercase Hexadecimal: %s\n", hexLower);
// 		free(hexLower);
// 	}
// 	// Convert to uppercase hexadecimal
// 	char *hexUpper = ft_puthexi(num, 'X');
// 	if (hexUpper != NULL) {
// 		printf("Uppercase Hexadecimal: %s\n", hexUpper);
// 		free(hexUpper);
// 	}

// 	return 0;
// }
