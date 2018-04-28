/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** create_data_port_socket.c
*/

#include "myftp.h"

int	setup_data_port_info(t_srv *srv)
{
	struct	sockaddr_in	s_in;
	socklen_t		s_in_len = sizeof(s_in);

	srv->data_fd = create_data_socket(srv);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(srv->port_data);
	s_in.sin_addr.s_addr = inet_addr(srv->port_addr);
	getsockname(srv->data_fd, (struct sockaddr *)&s_in, &s_in_len);
	return (0);
}

int	create_data_port(t_srv *srv)
{
	create_data_socket(srv);
	setup_data_port_info(srv);
	return (0);
}
