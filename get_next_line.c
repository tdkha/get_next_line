/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:39 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/07 09:08:00 by ktieu            ###   ########.fr       */
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
	while (main_buffer[i] && main_buffer[i] != '\n')
    {
        i++;
    }

    newline = ft_substr(main_buffer, 0, i);
	return (newline);
}

static char	*reform_main_buffer(char *main_buffer, int i)
{
	char	*new_main_buffer;

	new_main_buffer = ft_substr(main_buffer, i + 1, ft_strlen(main_buffer) - i - 1);
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
		main_buffer = ft_strjoin(main_buffer, temp_buffer);
		if (!main_buffer)
			return (free_all_buffers(main_buffer, temp_buffer));
	}
	free(temp_buffer);
	if (!main_buffer)
        return (NULL);
	temp_buffer = get_line_from_main_buffer(main_buffer);
	main_buffer = reform_main_buffer(main_buffer, ft_strlen(temp_buffer));
	return (temp_buffer);
}
