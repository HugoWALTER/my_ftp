/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** get_port_infos.c
*/

#include "myftp.h"

char	*fill_port_addr(t_srv *srv, char *tmp, int i)
{
	if (srv->scnd[i] == ',') {
		tmp[i] = '.';
		srv->nb_comma++;
		i++;
	}
	tmp[i] = srv->scnd[i];
	return (tmp);
}

char	*get_port_addr(t_srv *srv)
{
	char	*tmp = malloc(sizeof(char) * strlen(srv->scnd) + 1);
	int	i = 0;

	if (tmp == NULL)
		return (NULL);
	while (srv->scnd[i]) {
		tmp = fill_port_addr(srv, tmp, i);
		if (srv->nb_comma == 4)
			break;
		i++;
	}
	tmp[i] = '\0';
	srv->port_addr = strdup(tmp);
	free(tmp);
	return (srv->port_addr);
}

int	get_port_p1_and_p2(t_srv *srv, char *str)
{
	int	p1 = 0;
	int	p2 = 0;

	p1 = get_p1(str);
	p2 = get_p2(str);
	srv->port_data = (p1 * 256) + p2;
	printf("PORT activ to connect: %d\n", srv->port_data);
	return (0);
}
