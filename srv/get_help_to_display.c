/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** get_help_to_display.c
*/

#include "myftp.h"

t_rply_code const	*get_txt_display(int code)
{
	int	i = -1;

	while (st_rply_code[i].id != -1) {
		if (st_rply_code[i].code == code)
			return (&st_rply_code[i]);
		i++;
	}
	return (NULL);
}

t_help_code const	*get_help_display(char *str)
{
	int	i = 0;

	while (st_help_code[i].id != -1) {
		if (strncmp(st_help_code[i].cmd,
			str, strlen(st_help_code[i].cmd)) == 0)
			return (&st_help_code[i]);
		i++;
	}
	return (NULL);
}
