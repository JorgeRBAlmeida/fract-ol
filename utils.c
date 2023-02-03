/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:04:11 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/03 16:54:17 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n <= 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_argv2cmp(char **argv, const char *range)
{
	int	i;

	i = 0;
	if (argv[2][1] != '\0')
		return (1);
	while (argv[2][0] && range[i] && (argv[2][0] != range[i]))
		i ++;
	if (range[i])
		return (0);
	else
		return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length ++;
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}