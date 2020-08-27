/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:07:03 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/06 19:37:10 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define ERR_CODE -1
# define BUFFER_SIZE 1
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*ft_concat(char *s1, char *s2, int len);
int		check_n(char *p);
int		get_next_line(int fd, char **line);
int		handling_return(int r, char *buf, char **line, char *p);
#endif
