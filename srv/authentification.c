/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** authentification.c
*/

#include "myftp.h"

int	detect_bad_user(t_srv *srv, char *buffer, int size)
{
	if (srv->bad_user == 1 && strncmp(buffer, "PASS", 4) == 0
	&& size >= 5 && srv->srv_auth == 0) {
		srv->bad_user = 0;
		return (send_txt_client(srv, 534));
	}
	if (srv->bad_user == 1 && srv->srv_auth == 0
		&& strncmp(buffer, "PASS", 4) == 0 && size == 5)
		send_txt_client(srv, 503);
	return (0);
}

int	detect_user(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "USER", 4) == 0 && size == 5 && srv->srv_auth == 0)
		send_txt_client(srv, 530);
	if (strncmp(buffer, "USER", 4) == 0 && size > 5
	&& (srv->srv_auth == 0 || srv->srv_auth == 1)) {
		srv->scnd = epur_str(buffer);
		if (strncmp(srv->scnd, NAME_USER, 9) == 0) {
			srv->srv_auth = 1;
			send_txt_client(srv, 331);
		} else {
			send_txt_client(srv, 333);
			srv->bad_user = 1;
		}
	}
	if (srv->srv_auth == 0 && strncmp(buffer, "PASS", 4) == 0
		&& srv->bad_user == 0)
		send_txt_client(srv, 503);
	detect_bad_user(srv, buffer, size);
	if (srv->srv_auth == 1 && strncmp(buffer, "USER", 4) == 0 && size == 5)
		send_txt_client(srv, 530);
	return (0);
}

int	detect_password(t_srv *srv, char *buffer)
{
	if (srv->srv_auth == 1 && strncmp(buffer, "PASS", 4) == 0) {
		send_txt_client(srv, 230);
		srv->srv_auth = 2;
		return (srv->srv_auth);
	}
	return (0);
}

int	clt_not_auth(t_srv *srv)
{
	char	buffer[512];
	int	n = read(srv->client_fd, &buffer, 512);
	int	size = strlen(buffer);

	buffer[n] = '\0';
	if (n > 0)
		printf("$> %s", buffer);
	detect_user(srv, buffer, size);
	if (detect_password(srv, buffer) == 2)
		return (srv->srv_auth);
	if (strncmp(buffer, "QUIT", 4) == 0) {
		send_txt_client(srv, 221);
		if (shutdown(srv->client_fd, SHUT_RDWR) == -1)
			return (my_error("Can't close client\n", 84));
		return (0);
	}
	else if (strncmp(buffer, "USER", 4) != 0
		&& strncmp(buffer, "PASS", 4) != 0 && buffer[0] != '\n')
		send_txt_client(srv, 540);
	memset(buffer, 0, sizeof(buffer));
	return (0);
}

int	clt_already_auth(t_srv *srv, char *buffer)
{
	if (strncmp(buffer, "USER", 4) == 0)
		send_txt_client(srv, 504);
	if (strncmp(buffer, "PASS", 4) == 0)
		send_txt_client(srv, 231);
	return (0);
}
