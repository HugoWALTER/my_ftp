/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** delete_cmd.c
*/

#include "myftp.h"

int	delete_command(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "DELE", 4) == 0 && size == 5)
		send_txt_client(srv, 550);
	if (strncmp(buffer, "DELE", 4) == 0 && size > 5) {
		srv->scnd = epur_str(buffer);
		srv->scnd[strlen(srv->scnd) - 1] = '\0';
		if (access(srv->scnd, F_OK) == -1)
			send_txt_client(srv, 550);
		if (remove(srv->scnd) == 0)
			send_txt_client(srv, 250);
		else
			send_txt_client(srv, 551);
	}
	return (0);
}
