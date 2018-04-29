/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** retr_cmd.c
*/

#include "myftp.h"

int	check_file(t_srv *srv, char *file)
{
	struct	stat	st;

	srv->filefd = open(file, O_RDONLY);
	if (srv->filefd == -1)
		return (my_error("Can't open the file\n", 84));
	if ((stat(file, &st) == - 1) && S_ISREG(st.st_mode))
		return (my_error("Can't open the file, bad rights\n", 84));
	return (0);
}

int	launch_retr(t_srv *srv)
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
	if (close(srv->filefd) == -1)
		return (my_error("close retr filefd failed\n", 84));
	if (close(srv->data_fd) == -1)
		return (my_error("close retr data_fd failed\n", 84));
	free(buffer);
	return (0);
}

int	start_passiv_or_activ_retr(t_srv *srv)
{
	if (srv->mode == PASSIV)
		accept_data_socket(srv);
	if (srv->mode == ACTIV)
		connect_data_socket(srv);
	return (0);
}

int	check_valid_retr(t_srv *srv, char *buffer)
{
	if (srv->mode == ANY)
		send_txt_client(srv, 425);
	if (srv->mode == PASSIV || srv->mode == ACTIV) {
		start_passiv_or_activ_retr(srv);
		srv->scnd = epur_str(buffer);
		srv->scnd[strlen(srv->scnd) - 1] = '\0';
		if (check_file(srv, srv->scnd) == 84)
			send_txt_client(srv, 550);
		else
			launch_retr(srv);
	}
	return (0);
}

int	retr_cmd(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "RETR", 4) == 0 && size == 5) {
		if (srv->mode == ANY)
			send_txt_client(srv, 425);
		else
			send_txt_client(srv, 554);
	}
	if (strncmp(buffer, "RETR", 4) == 0 && size > 5)
		check_valid_retr(srv, buffer);
	return (0);
}
