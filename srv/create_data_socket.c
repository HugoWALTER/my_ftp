/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** create_data_socket.c
*/

#include "myftp.h"

int	accept_data_socket(t_srv *srv)
{
	struct sockaddr_in	s_in_client;
	socklen_t		s_in_size = sizeof(s_in_client);

	srv->data_fd = accept(srv->data_fd, (struct sockaddr *)&s_in_client,
	&s_in_size);
	if (srv->data_fd == -1)
		if (close(srv->data_fd) == -1)
			return (my_error("Close in accept failed\n", 84));
	return (0);
}

int	connect_data_socket(t_srv *srv)
{
	struct sockaddr_in	s_in_client;

	srv->data_fd = connect(srv->data_fd, (struct sockaddr *)&s_in_client,
	sizeof(s_in_client));
	if (srv->data_fd == -1)
		if (close(srv->data_fd) == -1)
			return (my_error("Close in connect failed\n", 84));
	return (0);
}

int	create_data_socket(t_srv *srv)
{
	struct	protoent	*pe;
	int			opt = 1;

	pe = getprotobyname("TCP");
	if (!pe)
		return (my_error("Resolve protocol TCP failed\n", 84));
	srv->data_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (srv->data_fd == -1)
		return (my_error("Can't create data socket\n", 84));
	if (setsockopt(srv->data_fd, SOL_SOCKET, SO_REUSEADDR,
		(char *)&opt, sizeof(opt)) == -1)
		return (my_error("Can't setsockopt data socket\n", 84));
	return (srv->data_fd);
}

int	setup_data_info(t_srv *srv)
{
	struct	sockaddr_in	s_in;
	socklen_t		s_in_len = sizeof(s_in);

	srv->data_fd = create_data_socket(srv);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(srv->port_data);
	s_in.sin_addr.s_addr = srv->s_in.sin_addr.s_addr;
	getsockname(srv->data_fd, (struct sockaddr *)&s_in, &s_in_len);
	if (srv->mode == ANY || srv->mode == PASSIV) {
		if (bind(srv->data_fd, (const struct sockaddr *)&s_in,
			sizeof(s_in)) == -1)
			return (srv_err("Can't bind data\n", 84, srv));
		if (listen(srv->data_fd, 42) == -1)
			return (srv_err("Can't listen data\n", 84, srv));
	}
	return (0);
}

int	create_data(t_srv *srv)
{
	create_data_socket(srv);
	setup_data_info(srv);
	return (0);
}
