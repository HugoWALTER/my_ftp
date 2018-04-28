/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** create_socket.c
*/

#include "myftp.h"

int	create_socket(t_srv *srv)
{
	srv->pe = getprotobyname("TCP");
	if (!srv->pe)
		return (my_error("Resolve protocol TCP failed\n", 84));
	srv->fd = socket(AF_INET, SOCK_STREAM, srv->pe->p_proto);
	if (srv->fd == -1)
		return (my_error("Can't create server socket\n", 84));
	return (srv->fd);
}

int	setup_srv_info(t_srv *srv)
{
	srv->fd = create_socket(srv);
	srv->s_in.sin_family = AF_INET;
	srv->s_in.sin_port = htons(srv->port);
	srv->s_in.sin_addr.s_addr = INADDR_ANY;
	if (bind(srv->fd, (const struct sockaddr *)&srv->s_in,
		sizeof(srv->s_in)) == -1)
		return (srv_err("Can't bind server\n", 84, srv));
	if (listen(srv->fd, 42) == -1)
		return (srv_err("Can't listen server\n", 84, srv));

	return (0);
}
