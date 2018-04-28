/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** help_and_noop_cmd.c
*/

#include "myftp.h"

int	help_and_noop_command(t_srv *srv, char *buffer, int size)
{
	if (strncmp(buffer, "NOOP", 4) == 0)
		send_txt_client(srv, 200);
	if (strncmp(buffer, "HELP", 4) == 0 && size == 5) {
		send_txt_client(srv, 214);
		send_txt_client(srv, 215);
		send_txt_client(srv, 216);
	}
	if (strncmp(buffer, "HELP", 4) == 0 && size > 5) {
		srv->scnd = epur_str(buffer);
		send_txt_client(srv, 214);
		send_help_client(srv, srv->scnd);
		send_txt_client(srv, 216);
	}
	return (0);
}
