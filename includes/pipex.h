/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:42:17 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/24 16:44:47 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>

void	ft_fexit(int code, char *msg);
char	*ft_getcmd(char **paths, char *cmd);
char	**ft_getpathv(char **envp);
void	ft_freestrs(char **strs);
void	ft_exec(char **argv, char **envp);

#endif