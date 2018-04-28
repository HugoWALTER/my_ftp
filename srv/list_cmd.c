/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** list_cmd.c
*/

#include "myftp.h"

int	data_dup2_function(t_srv *srv, char *cmd, int tmpfd)
{
	send_txt_client(srv, 150);
	if (system(cmd) != 0)
		send_txt_client(srv, 553);
	else
		send_txt_client(srv, 226);
	if (dup2(tmpfd, 1) == -1)
		return (my_error("dup2 failed in list\n", 84));
	if (close(srv->data_fd) == -1)
		return (my_error("Fail to close data_fd list\n", 84));
	if (close(tmpfd) == -1)
		return (my_error("Fail to close tmpfd list\n", 84));
	return (0);
}

int	launch_listing(t_srv *srv)
{
	int	tmpfd = 0;
	char	*cmd = NULL;
	char	*pwd = NULL;

	pwd = getcwd(pwd, BUFF_SIZE);
	cmd = calloc(500, sizeof(char));
	if (cmd == NULL)
		return (my_error("Fail to calloc cmd\n", 84));
	cmd = strcat(cmd, "ls -l");
	cmd = strcat(cmd, " ");
	cmd = strcat(cmd, pwd);
	cmd = strcat(cmd, " | sed 1d");
	tmpfd = dup(tmpfd);
	if (tmpfd == -1)
		return (my_error("first dup2 failed in list\n", 84));
	if (dup2(srv->data_fd, 1) != -1)
		data_dup2_function(srv, cmd, tmpfd);
	return (0);
}

int	launch_specified_listing(t_srv *srv, char *buffer)
{
	int	tmpfd = 0;
	char	*cmd = NULL;
	char	*pwd = NULL;

	srv->scnd = epur_str(buffer);
	pwd = getcwd(pwd, BUFF_SIZE);
	cmd = calloc(500, sizeof(char));
	if (cmd == NULL)
		return (my_error("Fail to calloc cmd\n", 84));
	cmd = strcat(cmd, "ls -la");
	cmd = strcat(cmd, " ");
	cmd = strcat(cmd, srv->scnd);
	cmd = strcat(cmd, " | sed 1d");
	tmpfd = dup(tmpfd);
	if (tmpfd == -1)
		return (my_error("first dup2 failed in list\n", 84));
	if (dup2(srv->data_fd, 1) != -1)
		data_dup2_function(srv, cmd, tmpfd);
	return (0);
}

int	check_list_cmd(t_srv *srv)
{
	if (srv->mode == ANY)
		send_txt_client(srv, 425);
	if (srv->mode == PASSIV || srv->mode == ACTIV) {
		if (srv->mode == PASSIV)
			accept_data_socket(srv);
		if (srv->mode == ACTIV)
			connect_data_socket(srv);
	}
	return (0);
}

int	list_cmd(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "LIST", 4) == 0 && size == 5) {
		check_list_cmd(srv);
		if (srv->mode == PASSIV || srv->mode == ACTIV)
			launch_listing(srv);
	}
	if (strncmp(buffer, "LIST", 4) == 0 && size > 5) {
		check_list_cmd(srv);
		if (srv->mode == PASSIV || srv->mode == ACTIV)
			launch_specified_listing(srv, buffer);
	}
	return (0);
}
