/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:12:46 by sde-oliv          #+#    #+#             */
/*   Updated: 2025/01/02 14:07:12 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	printf("BUFFER_SIZE %d\n\n", BUFFER_SIZE);
	fd1 = open("text_test.txt", O_RDONLY);
	fd2 = open("text_test2.txt", O_RDONLY);
	while (1)
	{
		line1 = get_next_line_bonus(fd1);
		if (!line1)
			break ;
		printf("%s", line1);
		free(line1);
	}
	printf("\n\n");
	while (1)
	{
		line2 = get_next_line_bonus(fd2);
		if (!line2)
			break ;
		printf("%s", line2);
		free(line2);
	}
	close(fd1);
	close(fd2);
}
