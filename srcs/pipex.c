/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:46:31 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/23 16:59:17 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	char	**cmd1_args;
	char	**cmd2_args;

	if (argc != 4)
		return (1);
	cmd1_args = ft_split(argv[2], ' ');
	cmd2_args = ft_split(argv[3], ' ');


	return (0);
}
