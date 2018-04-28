/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** free_struct
*/

#include "myftp.h"

int	xsrv_free(t_srv *srv)
{
	free(srv);
	return (84);
}

int	clear_srv(t_srv *srv)
{
	free(srv);
	return (0);
}
