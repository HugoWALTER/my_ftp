/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** server.c
*/

#include "myftp.h"

int	usage_srv(t_srv *srv)
{
	printf("USAGE: ./server port path\n\tport\tis the port on which \
the server socket listens\n\tpath\tis the path to the home directory for \
the Anonymous user\n");
	free(srv);
	return (0);
}

t_srv	*init_data_struct(t_srv *lm)
{
	lm->data_fd = 0;
	lm->port_data = 0;
	lm->port1 = 0;
	lm->port2 = 0;
	lm->filefd = 0;
	lm->port_addr = NULL;
	lm->nb_comma = 0;
	lm->bad_user = 0;
	return (lm);
}

int	init_struct(t_srv **val)
{
	t_srv	*lm;

	lm = malloc(sizeof(*lm));
	if (lm == NULL)
		return (84);
	lm->port = 0;
	lm->path = NULL;
	lm->pe = NULL;
	lm->fd = 0;
	lm->s_in_size = 0;
	lm->client_fd = 0;
	lm->client_ip = NULL;
	lm->pid = 0;
	lm->srv_auth = 0;
	lm->scnd = NULL;
	lm->pwd = NULL;
	lm->mode = ANY;
	lm = init_data_struct(lm);
	*val = lm;
	return (0);
}

int	init_values(t_srv *srv)
{
	srv->s_in_size = sizeof(srv->s_in_client);
	return (0);
}

int	main(int ac, char **av)
{
	t_srv	*srv;

	if (init_struct(&srv) == 84)
		return (xsrv_free(srv));
	if (ac == 2 && strcmp(av[1], "--help") == 0)
		return (usage_srv(srv));
	if (error_handling(ac, av, srv) == 84)
		return (xsrv_free(srv));
	printf("PORT: %d\nPATH: %s\n", srv->port, srv->path);
	if (init_values(srv) == 84)
		return (xsrv_free(srv));
	if (setup_srv_info(srv) == 84)
		return (srv_err("Setup info failed\n", 84, srv));
	if (server_fork(srv) == 84)
		return (srv_err("Problem during fork\n", 84, srv));
	clear_srv(srv);
	return (0);
}
