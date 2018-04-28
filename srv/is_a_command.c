/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** is_a_command.c
*/

#include "myftp.h"

int	is_a_command(char *str)
{
	if ((strncmp(str, "USER", 4) != 0) && (strncmp(str, "PASS", 4) != 0) &&
		(strncmp(str, "CWD", 3) != 0) &&
		(strncmp(str, "CDUP", 4) != 0) &&
		(strncmp(str, "QUIT", 4) != 0) &&
		(strncmp(str, "DELE", 4) != 0) &&
		(strncmp(str, "PWD", 3) != 0) &&
		(strncmp(str, "PASV", 4) != 0) &&
		(strncmp(str, "PORT", 4) != 0) &&
		(strncmp(str, "HELP", 4) != 0) &&
		(strncmp(str, "NOOP", 4) != 0) &&
		(strncmp(str, "RETR", 4) != 0) &&
		(strncmp(str, "STOR", 4) != 0) &&
		(strncmp(str, "LIST", 4) != 0) &&
		(str[0] != '\n'))
		return (1);
	return (0);
}
