/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** handle_server.c
*/

#include "myftp.h"

int	send_to_serv(t_clt *clt)
{
	char	buffer[BUFF_SIZE];
	int	n = read(1, &buffer, BUFF_SIZE);

	buffer[n] = '\0';
	if (write(clt->fd, buffer, strlen(buffer)) == -1)
		return (my_error("Error: Can't write on server\n", 84));
	return (1);
}

int	read_server(t_clt *clt)
{
	char	buffer[BUFF_SIZE];
	int	n = read(clt->fd, &buffer, BUFF_SIZE);

	buffer[n] = '\0';
	if (n > 0)
		printf("%s", buffer);
	if (strncmp(buffer, "221", 3) == 0)
		return (0);
	return (1);
}

int	handle_server(t_clt *clt)
{
	char	buffer[BUFF_SIZE];
	int	n = read(clt->fd, &buffer, BUFF_SIZE);

	buffer[n - 1] = '\0';
	printf("%s\n", buffer);
	while (1) {
		if (send_to_serv(clt) == 0)
			return (0);
		if (read_server(clt) == 0)
			return (0);
	}
	return (0);
}
