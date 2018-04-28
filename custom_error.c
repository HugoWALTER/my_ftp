/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** custom_error.c
*/

#include "myftp.h"

int	my_error(char *str, int ret)
{
	fprintf(stderr, str);
	return (ret);
}
