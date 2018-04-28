/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** first_connection.c
*/

#include "myftp.h"

int	handle_client(t_srv *srv)
{
	static const char	*const first_cxn =
	"220 Service ready for new user.\r\n";
	if (write(srv->client_fd, first_cxn, strlen(first_cxn)) == -1)
		return (1);
	return (0);
}
