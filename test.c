
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd = open("read_error.txt", O_RDONLY);
	char *main_buffer = get_next_line(fd);
	printf("Line: %s",main_buffer);
	main_buffer = get_next_line(fd);
	printf("Line: %s",main_buffer);
	main_buffer = get_next_line(fd);
	printf("Line: %s",main_buffer);
	main_buffer = get_next_line(fd);
	printf("Line: %s",main_buffer);
	main_buffer = get_next_line(fd);
	printf("Line: %s",main_buffer);
	close(fd);
}
