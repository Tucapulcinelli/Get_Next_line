/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:58 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/06 15:33:18 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** strchr procura por caractere especifico na string.
*/

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	else
		return (NULL);
}

/*
** strdup retorna um ponteiro pra dest(nova string), que é copia de src
*/

static char	*ft_strdup(const char *src)
{
	char *dest;

	if (!(dest = (char *)malloc(ft_strlen(src) + 1)))
		return (0);
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

/*
** substr retorna uma parte da string.
*/

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!s || (sub_str == NULL))
	{
		return (NULL);
	}
	i = 0;
	while ((i < len) && ((start + i) < ft_strlen(s)) && (s[start + i] != '\0'))
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

/*
** outputs especifica as saidas (-1 erro, 0 EOF e 1 final da linha)
*/

static int	outputs(int n, char **buff, char **line)
{
	char *temp;

	if (n < 0)// condição inicial, fd deve existir
		return (-1);
	*line = ft_substr(*buff, 0, ft_strclen(*buff, '\n'));// procura por \n na buff, marca a posição, em seguida pega essa substring e coloca na line, apontada. (0 pos incio string)
	if (!line)
		return (-1);// retorna erro se nao achar a linha
	if (ft_strchr(*buff, '\n'))// procura por \n na buff
	{
		temp = ft_strdup(ft_strchr(*buff, '\n') + 1);// duplica a buff+1 na temp
		ft_strdel(&*buff);// libera a buff
		*buff = temp; //retorna temp pra buff
		return (1);// fim da linha
	}
	ft_strdel(&*buff);// libera a buff, caso não entre na condição acima.
	return (0);// fim do arquivo
}

/*
** get next line, lê uma linha por vez, de um arquivo fd, determinada pelo
** tamanho do BUFFER_SIZE.
*/

int			get_next_line(int fd, char **line)
{
	static char	*buff_line[MAX_FILE_DESCRIPTOR]; // buff_line do fd (limitado por MAX_FILE_DESCRIPTOR)
	char		*new_line;
	int			nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FILE_DESCRIPTOR || !line)// checa condições de inicio
		return (-1);// retorna erro caso uma das condições seja encontrada
	if (!(buff_line[fd]))
		if (!(buff_line[fd] = ft_strdup("")))// checa buff_line esta vazia, se não, retorna erro
			return (-1);
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));//aloca a string em new_line, tam do BUFFER+1
	if (!new_line)// checa se alocou, se não retorna erro
		return (-1);
	while ((nbytes = read(fd, new_line, BUFFER_SIZE)) > 0)// enquanto nbytes(fd, new_line e BUFFER_SIZE) for maior que 0, continua lendo.
	{
		new_line[nbytes] = '\0';// acrescenta \0 ao final da new_line
		buff_line[fd] = ft_strjoin_free(buff_line[fd], new_line);// adiciona new_line em buff_line, libera new_line
		if (ft_strchr(buff_line[fd], '\n'))// se achar \n em buff_line, sai do loop e chama strdel abaixo
			break ;
	}
	ft_strdel(&new_line); // libera new_line
	return (outputs(nbytes, &buff_line[fd], line));// retorna uma das opções de saida
}
