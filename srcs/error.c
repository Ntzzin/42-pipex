/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:34:16 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/24 16:56:39 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_fexit(int code, char *msg)
{
	if (!msg)
		perror("Error");
	else
		ft_printf("printf: Error: %s\n", msg);
	exit(code);
}