/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:50 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/06 15:38:22 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** strcclen devolve posição de caractere procurado na string, usando len
*/

size_t	ft_strclen(const char *str, const char c)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

/*
** strlen descobre o tamanho da string
*/

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** strdel libera memoria da string armazenada e deleta o conteudo da string apontada
*/

void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

/*
** memcpy copia n caracteres de src para dest
*/

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

/*
** stjoin junta as strings fornecidas no argumento, e retorna uma string
** alocada new_str, depois libera mem com strdel, de dest
*/

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
