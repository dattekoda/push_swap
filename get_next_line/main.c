// main.c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*line;
	int		fd;
	char	c;

	fd = 0;
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		c = *line;
		free(line);
		if (c == '\n')
			break ;
	}
	close(fd);
	return (0);
}

// int main(void)
// {
// 	char	*line;
// 	int		fd;
// 	char	c;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }