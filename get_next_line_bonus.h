/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:04:24 by guferrei          #+#    #+#             */
/*   Updated: 2021/07/04 23:23:06 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define OPEN_MAX 1024

int		get_next_line(int fd, char **line);
char	*safety_first(int fd, char **ptr);
int		gnl_strchr(char *ptr);
char	*gnl_strjoin(char *src, char **dest);
int		gnl_strlen(char *str);
void	gnl_strcpy(char *src, char *dest);

#endif
