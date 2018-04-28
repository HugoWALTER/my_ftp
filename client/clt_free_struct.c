/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** free_struct
*/

#include "myftp.h"

int	xclt_free(t_clt *clt)
{
	free(clt);
	return (84);
}

int	clear_clt(t_clt *clt)
{
	free(clt);
	return (0);
}
