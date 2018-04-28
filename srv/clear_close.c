/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** clear_close.c
*/

#include "myftp.h"

int	clear_close(t_srv *srv)
{
	if (close(srv->fd) != -1)
		if (close(srv->fd) == -1)
			return (my_error("Can't close proprely !\n", 1));
	if (close(srv->client_fd) != -1)
		if (close(srv->client_fd) == -1)
			return (my_error("Can't close client_fd proprely !\n",
			1));
	if (close(srv->data_fd) != -1)
		if (close(srv->data_fd) == -1)
			return (my_error("Can't close data_fd proprely !\n",
			1));
	return (0);
}
