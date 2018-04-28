/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** data_transfer_cmd.c
*/

#include "myftp.h"

int	data_transfer_cmd(t_srv *srv, char *buffer, int size)
{
	retr_cmd(srv, buffer, size);
	stor_cmd(srv, buffer, size);
	list_cmd(srv, buffer, size);
	return (0);
}
