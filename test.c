#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("test.txt", O_RDONLY);
  next_line = get_next_line(fd);
  count++;
  printf("[%d]:%s", count, next_line);
  next_line = get_next_line(fd);
  count++;
  printf("[%d]:%s", count, next_line);
  next_line = NULL;
	free(next_line);
  close(fd);
  return (0);
}