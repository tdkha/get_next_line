/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:39 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/06 09:00:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ---------------------------------------------------------------- */
/*						BUFFER INTERACTIONS							*/
/* ---------------------------------------------------------------- */

static void	*free_all_buffers(char *main_buffer, char *temp_buffer)
{
	if (main_buffer)
		free(main_buffer);
	if (temp_buffer)
		free(temp_buffer);
	main_buffer = NULL;
	temp_buffer = NULL;
	return (NULL);
}

static char	*get_line_from_main_buffer(char *main_buffer)
{
	char	*newline;
	int		i;

	i = 0;
	i = find_next_line_break(main_buffer, i);
	newline = (char *) malloc (sizeof(char) * (i + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (main_buffer[i] && main_buffer[i] != '\n')
	{
		newline[i] = main_buffer[i];
		i++;
	}
	if (main_buffer[i] == '\n')
	{
		newline[i] = main_buffer[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

static char	*reform_main_buffer(char *main_buffer)
{
	int		i;
	int		j;
	char	*new_main_buffer;

	i = 0;
	j = 0;
	if (!*main_buffer)
		return (free(main_buffer), NULL);
	i = find_next_line_break(main_buffer, i);
	new_main_buffer = (char *) malloc (((ft_strlen(main_buffer) - i) + 1));
	if (!new_main_buffer)
	{
		free(main_buffer);
		return (NULL);
	}
	while (main_buffer[i])
		new_main_buffer[j++] = main_buffer[i++];
	new_main_buffer[j] = '\0';
	if (!*main_buffer)
		return (free(main_buffer), free(new_main_buffer), NULL);
	free(main_buffer);
	return (new_main_buffer);
}

/* ---------------------------------------------------------------- */
/*							MAIN FUNCTIONS							*/
/* ---------------------------------------------------------------- */

char	*get_next_line(int fd)
{
	static char	*main_buffer;
	char		*temp_buffer;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0  || BUFFER_SIZE > INT_MAX)
		return (NULL);
	temp_buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (NULL);
	while (!ft_strchr(main_buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_all_buffers(main_buffer, temp_buffer));
		temp_buffer[bytes] = '\0';
		if (main_buffer == NULL)
			main_buffer = ft_strdup(temp_buffer);
		else
			main_buffer = ft_strjoin(main_buffer, temp_buffer);
		if (!main_buffer)
			return (free_all_buffers(main_buffer, temp_buffer));
		free(temp_buffer);
	}
	temp_buffer = get_line_from_main_buffer(main_buffer);
	main_buffer = reform_main_buffer(main_buffer);
	return (temp_buffer);
}
