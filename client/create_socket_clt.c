/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** create_socket_clt.c
*/

#include "myftp.h"

int	create_clt_socket(t_clt *clt)
{
	clt->pe = getprotobyname("TCP");
	if (!clt->pe)
		return (my_error("Resolve protocol TCP failed\n", 84));
	clt->fd = socket(AF_INET, SOCK_STREAM, clt->pe->p_proto);
	if (clt->fd == -1)
		return (my_error("Can't create socket\n", 84));
	return (clt->fd);
}

int	setup_clt_info(t_clt *clt)
{
	clt->fd = create_clt_socket(clt);
	clt->s_in.sin_family = AF_INET;
	clt->s_in.sin_port = htons(clt->port);
	clt->s_in.sin_addr.s_addr = inet_addr(clt->ip);
	if (connect(clt->fd, (struct sockaddr *)&clt->s_in,
	sizeof(clt->s_in)) == -1) {
		if (close(clt->fd) == -1)
			return (my_error("Can't close connection\n", 84));
	}
	return (0);
}
