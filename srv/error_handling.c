/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** error_handling.c
*/

#include "myftp.h"

int	srv_err(char *str, int ret, t_srv *srv)
{
	fprintf(stderr, str);
	if (srv->fd != -1)
		if (close(srv->fd) == -1)
			return (my_error("Can't close socket\n", 1));
	if (srv->client_fd != -1)
		if (close(srv->client_fd) == -1)
			return (my_error("Can't close socket (client_fd)\n",
			1));
	if (srv->data_fd != -1)
		if (close(srv->data_fd) == -1)
			return (my_error("Can't close socket (data_fd)\n", 1));
	return (ret);
}

int     is_number(char *str)
{
	int	i = 0;

	while (str[i])
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (84);
	return (0);
}

int	error_handling(int ac, char **av, t_srv *srv)
{
	if (ac != 3)
		return (my_error("Please use at least 3 args\n", 84));
	if (ac == 3) {
		if (is_number(av[1]) == 84)
			return (my_error("PORT must be a number\n", 84));
		srv->port = atoi(av[1]);
		if (srv->port <= 0 || srv->port > 65535)
			return (my_error("PORT must be between 0 and 63535\n",
			84));
		srv->path = av[2];
		if (chdir(srv->path) == -1)
			return (my_error("Error can't change the path\n", 84));
	}
	return (0);
}
