/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telias-p <telias-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:44:02 by telias-p          #+#    #+#             */
/*   Updated: 2021/03/06 14:26:45 by telias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

/*
** MAX FILE DESCRIPTOR, RLIMIR_NOFILE determina num max de arq a serem abertos
*/

# define MAX_FILE_DESCRIPTOR	RLIMIT_NOFILE

int		get_next_line(int fd, char **line);

void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *dest, char *src);
size_t	ft_strclen(const char *str, const char chr);
void	ft_strdel(char **str);

#endif
