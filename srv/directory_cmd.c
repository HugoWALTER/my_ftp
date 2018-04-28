/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** directory_cmd.c
*/

#include "myftp.h"

int	init_pwd(t_srv *srv, char *buffer)
{
	char	*pwd = NULL;

	if (strncmp(buffer, "PWD", 3) == 0) {
		pwd = getcwd(pwd, BUFF_SIZE);
		srv->pwd = strdup(pwd);
		srv->pwd = strcpy(srv->pwd, pwd);
		send_txt_client(srv, 257);
	}
	return (0);
}

int	check_cdup_directory(t_srv *srv)
{
	if (strcmp("..", srv->scnd) == 0) {
		if (chdir(srv->scnd) == -1)
			send_txt_client(srv, 552);
		else
			send_txt_client(srv, 251);
	}
	return (0);
}

int	cdup_command(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "CDUP", 4) == 0 && size == 5) {
		if (chdir("..") == -1)
			send_txt_client(srv, 552);
		else
			send_txt_client(srv, 251);
	}
	if (strncmp(buffer, "CDUP", 4) == 0 && size > 5) {
		srv->scnd = epur_str(buffer);
		check_cdup_directory(srv);
	}
	return (0);
}

int	directory_command(t_srv *srv, char *buffer, int size)
{
	init_pwd(srv, buffer);
	if (strncmp(buffer, "CWD", 3) == 0 && size == 4)
		send_txt_client(srv, 552);
	if (strncmp(buffer, "CWD", 3) == 0 && size > 4) {
		srv->scnd = epur_str(buffer);
		if (chdir(srv->scnd) == -1)
			send_txt_client(srv, 552);
		else
			send_txt_client(srv, 251);
	}
	cdup_command(srv, buffer, size);
	return (0);
}
