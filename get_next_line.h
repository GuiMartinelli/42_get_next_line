/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:18:52 by guferrei          #+#    #+#             */
/*   Updated: 2021/07/04 23:23:35 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		get_next_line(int fd, char **line);
char	*safety_first(int fd, char **ptr);
int		gnl_strchr(char *ptr);
char	*gnl_strjoin(char *src, char **dest);
int		gnl_strlen(char *str);
void	gnl_strcpy(char *src, char *dest);

#endif
