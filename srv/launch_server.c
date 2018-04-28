/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** launch_server.c
*/

#include "myftp.h"

int	launch_server(t_srv *srv)
{
	srv->client_ip = inet_ntoa(srv->s_in_client.sin_addr);
	printf("Connection Establishment: %s\n", srv->client_ip);
	handle_client(srv);
	while (1) {
		while (clt_not_auth(srv) != 2);
		while (detect_command(srv) == 1);
	}
	kill(srv->pid, SIGTERM);
	return (0);
}

int	server_fork(t_srv *srv)
{
	while (1) {
		srv->client_fd = accept(srv->fd,
		(struct sockaddr *)&srv->s_in_client,
		&srv->s_in_size);
		if (srv->client_fd == -1)
			return (my_error("Accept failed\n", 84));
		srv->pid = fork();
		if (srv->pid == 0) {
			launch_server(srv);
		} else if (srv->pid < 0)
			return (my_error("pid failed\n", 84));
	}
	return (0);
}
