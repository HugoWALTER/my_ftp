/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** string_manipulation.c
*/

#include "myftp.h"

char	*revstr(char *str)
{
	int	i = 0;
	int	len = strlen(str) - 1;
	char	op = '\0';

	while (i < len) {
		op = str[i];
		str[i] = str[len];
		str[len] = op;
		i++;
		len--;
	}
	return (str);
}

char	*epur_str(char *str)
{
	int	i = strlen(str) - 1;
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * strlen(str) + 1);

	if (tmp == NULL)
		return (NULL);
	while (str[i] != ' ') {
		tmp[k] = str[i];
		i--;
		k++;
	}
	tmp[k] = '\0';
	tmp = revstr(tmp);
	return (tmp);
}
