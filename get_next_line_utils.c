/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:50 by telias-p          #+#    #+#             */
/*   Updated: 2021/04/05 20:31:44 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *str, const char c)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin_free(char *dest, char *src)
{
	char	*new_str;
	int		i;
	int		dest_len;
	int		src_len;

	if (!dest || !src)
		return (NULL);
	i = -1;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	new_str = malloc((dest_len + src_len + 1) * sizeof(*new_str));
	if (!new_str)
	{
		ft_strdel(&dest);
		return (NULL);
	}
	while (dest[++i])
		new_str[i] = dest[i];
	i = -1;
	while (src[++i])
		new_str[dest_len++] = src[i];
	new_str[dest_len] = '\0';
	ft_strdel(&dest);
	return (new_str);
}
