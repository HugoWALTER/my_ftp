/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** usage_clt.c
*/

#include "myftp.h"

int	usage_clt(t_clt *clt)
{
	printf("USAGE: ./myftp host port\n");
	free(clt);
	return (0);
}
