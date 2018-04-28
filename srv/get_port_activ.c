/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** get_port_activ.c
*/

#include "myftp.h"

int	check_host_port_validity(char *str)
{
	int	i = 0;
	int	nb_comma = 0;

	while (str[i]) {
		if (str[i] == ',') {
			nb_comma++;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (my_error("Only number are allowed.\n", 84));
	}
	if (nb_comma != 5)
		return (my_error("You must specified 5 commas.\n", 84));
	return (0);
}

int	extract_p1(char *str, int i)
{
	int	p1 = 0;
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * strlen(str));

	if (tmp == NULL)
		return (84);
	while (str[i] != ',') {
		tmp[k] = str[i];
		if (str[i] == ',')
			break;
		i++;
		k++;
	}
	p1 = atoi(tmp);
	free(tmp);
	return (p1);
}

int	get_p1(char *str)
{
	int	i = 0;
	int	nb_comma = 0;

	while (str[i]) {
		if (str[i] == ',')
			nb_comma++;
		if (nb_comma == 4)
			break;
		i++;
	}
	i += 1;
	return (extract_p1(str, i));
}

int	extract_p2(char *str, int i)
{
	int	p2 = 0;
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * strlen(str));

	if (tmp == NULL)
		return (84);
	while (str[i]) {
		tmp[k] = str[i];
		i++;
		k++;
	}
	p2 = atoi(tmp);
	free(tmp);
	return (p2);
}

int	get_p2(char *str)
{
	int	i = 0;
	int	nb_comma = 0;

	while (str[i]) {
		if (str[i] == ',')
			nb_comma++;
		if (nb_comma == 5)
			break;
		i++;
	}
	i += 1;
	return (extract_p2(str, i));
}
