/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:29:17 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/20 15:04:35 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_atoi(const char *str);
int		ft_count_c(char *s, char c);
int		ft_count_lines(int fd, int line_length, int img_w);
int		ft_line_length(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

//ft_print_f

int		ft_printf(const char *format, ...);
int		ft_chexi(int tmp);
int		ft_chexxi(int tmp);
int		ft_print_c(va_list args);
int		ft_print_s(va_list args);
int		ft_print_i(va_list args);
int		ft_print_u(va_list args);
int		ft_print_x(va_list args, char c);
int		ft_print_p(va_list args);
char	*ft_putadd(unsigned long n);
char	*ft_puthexi(unsigned int n, char c);
char	*ft_utoa(unsigned int n);

// get_next_line
//this part lets you controll the BUFFER_SIZE without adding it when compiling
//this is really usefull when used inside libft
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_free_gnl(char **p);
int		ft_strlen_gnl(char *s);
int		ft_strchr_gnl(char *s, int c, int flag);
char	*ft_strnjoin_gnl(char *s1, char *s2, int n);
char	*ft_strndup_gnl(char *str, int n);
void	*ft_calloc_gnl(size_t nelem, size_t elsize);
char	*ft_update_nl_gnl(char **next_line, int position);
char	*ft_output_gnl(char **next_line, int position, int bytes);
char	*get_next_line(int fd);

#endif
