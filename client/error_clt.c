/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** error_clt.c
*/

#include "myftp.h"

int	clt_err(char *str, int ret, t_clt *clt)
{
	fprintf(stderr, str);
	if (clt->fd != -1)
		if (close(clt->fd) == -1)
			return (my_error("Can't close socket\n", 1));
	return (ret);
}

int	clt_error_handling(char **av)
{
	int	port = atoi(av[2]);

	if (port <= 0 || port > 65535)
		return (my_error("Port must be between 1 and 65535\n", 84));
	return (0);
}
