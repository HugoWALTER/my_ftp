/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** detect_cmd.c
*/

#include "myftp.h"

int	checking_commands(t_srv *srv, char *buffer, int size)
{
	clt_already_auth(srv, buffer);
	help_and_noop_command(srv, buffer, size);
	directory_command(srv, buffer, size);
	delete_command(srv, buffer, size);
	activ_passiv_command(srv, buffer, size);
	data_transfer_cmd(srv, buffer, size);
	return (0);
}

int	detect_command(t_srv *srv)
{
	char	buffer[512];
	int	n = read(srv->client_fd, &buffer, 512);
	int	size = strlen(buffer);

	buffer[n - 1] = '\0';
	if (n > 0)
		printf("$> %s\n", buffer);
	checking_commands(srv, buffer, size);
	if (strncmp(buffer, "QUIT", 4) == 0) {
		send_txt_client(srv, 221);
		if (shutdown(srv->client_fd, SHUT_RDWR) == -1)
			return (my_error("Can't close client\n", 84));
		return (0);
	} else if (is_a_command(buffer) == 1)
		send_txt_client(srv, 500);
	memset(buffer, 0, sizeof(buffer));
	return (1);
}
