#include <fcntl.h>
#include <unistd.h>


char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1]; 
	## penser malloc buf
	static char	*left;
	int n;

		
	n = 1;
	while (n > 0 && ft_strchr(buf, '\n') != NULL)
	{
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = '\0';
		left = ft_join(left, buf);
	}
	return (ft_split(&left));
}

int main(void)
{
	int fd = open("fichier.txt", O_RDONLY);
}
