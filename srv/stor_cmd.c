/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** stor_cmd.c
*/

#include "myftp.h"

int	creation_file(t_srv *srv, char *file)
{
	srv->filefd = open(file, O_CREAT | O_WRONLY, 0644);
	if (srv->filefd == -1)
		return (my_error("Can't create the file\n", 84));
	return (0);
}

int	launch_stor(t_srv *srv)
{
	char	*buffer = NULL;
	int	rd = 0;

	buffer = malloc(sizeof(char) * READ_SIZE + 1);
	if (buffer == NULL)
		return (my_error("buffer retr failed\n", 84));
	send_txt_client(srv, 150);
	while ((rd = read(srv->filefd, buffer, READ_SIZE)) > 0)
		write(srv->data_fd, buffer, rd);
	send_txt_client(srv, 226);
	if (close(srv->fd) == -1)
		return (my_error("close retr fd failed\n", 84));
	if (close(srv->data_fd) == -1)
		return (my_error("close retr data_fd failed\n", 84));
	free(buffer);
	return (0);
}

int	start_passiv_or_activ_stor(t_srv *srv)
{
	if (srv->mode == PASSIV)
		accept_data_socket(srv);
	if (srv->mode == ACTIV)
		connect_data_socket(srv);
	return (0);
}

int	check_valid_stor(t_srv *srv, char *buffer)
{
	if (srv->mode == ANY)
		send_txt_client(srv, 425);
	if (srv->mode == PASSIV || srv->mode == ACTIV) {
		start_passiv_or_activ_stor(srv);
		srv->scnd = epur_str(buffer);
		if (creation_file(srv, srv->scnd) == 84)
			send_txt_client(srv, 555);
		else
			launch_stor(srv);
	}
	return (0);
}

int	stor_cmd(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "STOR", 4) == 0 && size == 5) {
		if (srv->mode == ANY)
			send_txt_client(srv, 425);
		else
			send_txt_client(srv, 530);
	}
	if (strncmp(buffer, "STOR", 4) == 0 && size > 5)
		check_valid_stor(srv, buffer);
	return (0);
}
