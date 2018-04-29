/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** activ_passiv_cmd.c
*/

#include "myftp.h"

int	print_passiv_info(t_srv *srv)
{
	for (int i = 0 ; srv->client_ip[i] ; i++) {
		if (srv->client_ip[i] == '.')
			txt_to_send(srv, ",");
		else
			dprintf(srv->client_fd, "%c", srv->client_ip[i]);
	}
	dprintf(srv->client_fd, ",%d,%d)\r\n", srv->port1, srv->port2);
	return (0);
}

int	fill_port_passiv(t_srv *srv)
{
	struct	sockaddr_in	s_in;
	socklen_t		s_in_len = sizeof(s_in);

	send_txt_client(srv, 227);
	getsockname(srv->data_fd,
	(struct sockaddr *)&s_in, &s_in_len);
	srv->port1 = (ntohs(s_in.sin_port) / 256);
	srv->port2 = (ntohs(s_in.sin_port) % 256);
	srv->port_data = (srv->port1 * 256) + srv->port2;
	printf("PORT (data) to connect: %d\n", srv->port_data);
	print_passiv_info(srv);
	return (0);
}

int	port_command(t_srv *srv, char *buffer)
{
	srv->scnd = epur_str(buffer);
	srv->scnd[strlen(srv->scnd) - 1] = '\0';
	if (check_host_port_validity(srv->scnd) == 84)
		return (txt_to_send(srv, "PORT must be valid\r\n"));
	srv->port_addr = get_port_addr(srv);
	get_port_p1_and_p2(srv, srv->scnd);
	if (srv->port_data <= 0 || srv->port_data > 65535)
		return (txt_to_send(srv,
		"PORT must be between 1 and 63535\r\n"));
	create_data_port(srv);
	send_txt_client(srv, 201);
	return (0);
}

int	activ_passiv_command(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "PASV", 4) == 0) {
		srv->mode = PASSIV;
		create_data(srv);
		if (srv->data_fd != -1)
			fill_port_passiv(srv);
		else
			send_txt_client(srv, 426);
	}
	if (strncmp(buffer, "PORT", 4) == 0 && size == 5)
		send_txt_client(srv, 500);
	if (strncmp(buffer, "PORT", 4) == 0 && size > 5) {
		srv->mode = ACTIV;
		port_command(srv, buffer);
	}
	return (0);
}
