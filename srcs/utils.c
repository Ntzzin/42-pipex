/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:46:28 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/24 17:37:16 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_freestrs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}


char	**ft_getpathv(char **envp)
{
	char	**temp;
	int		i;

	i = 0;
	temp = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			temp = ft_split(envp[i] + 5, ':');
			if (!temp)
				ft_fexit(EXIT_FAILURE, NULL);
			break;
		}
		i++;
	}
	return (temp);
	//ft_printf("\033[1;31mWarning: PATH env. variable not found\033[0m\n");s
}

char	*ft_getcmd(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*temp;
	int		i;

	i = 0;
	cmd_path = NULL;
	temp = ft_strjoin("/", cmd);
	if (!temp)
		ft_fexit(EXIT_FAILURE, NULL);
	while (paths && paths[i])
	{
		cmd_path = ft_strjoin(paths[i], temp);
		if (!cmd_path)
			ft_fexit(EXIT_FAILURE, NULL);
		if (access(cmd_path, F_OK) == 0)
			break;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free(temp);
	if (!cmd_path)
		return ("");
	return (cmd_path);
}

void	ft_exec(char **argv, char **envp)
{
	char	**paths;
	char	*cmd_path;
	
	paths = ft_getpathv(envp);
	cmd_path = ft_getcmd(paths, argv[0]);
	printf("cmd found is: '%s'\n", cmd_path);
	if (execve(cmd_path, argv, envp) == -1)
	{
		if (paths && paths[0] && !ft_strlen(cmd_path))
		{
			ft_freestrs(paths);
			ft_freestrs(argv);
			ft_fexit(127, "command not found");
		}
		if (paths)
			ft_freestrs(paths);
		if (ft_strlen(cmd_path))
			free(cmd_path);
		ft_freestrs(argv);
		ft_fexit(127, NULL);
	}
}
