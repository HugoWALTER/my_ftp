/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** client.c
*/

#include "myftp.h"

int	init_struct_clt(t_clt **val)
{
	t_clt	*lm;

	lm = malloc(sizeof(*lm));
	if (lm == NULL)
		return (84);
	lm->fd = 0;
	lm->port = 0;
	lm->ip = NULL;
	*val = lm;
	return (0);
}

int	init_values_clt(t_clt *clt, char **av)
{
	clt->ip = av[1];
	clt->port = atoi(av[2]);
	return (0);
}

int	main(int ac, char **av)
{
	t_clt	*clt;

	if (init_struct_clt(&clt) == 84)
		return (xclt_free(clt));
	if (ac == 2 && strcmp(av[1], "-help") == 0)
		return (usage_clt(clt));
	if (ac != 3)
		return (my_error("You must use 3 args (see -help)\n", 1));
	if (clt_error_handling(av) == 84)
		return (my_error("Error in client handling\n", 1));
	if (init_values_clt(clt, av) == 84)
		return (xclt_free(clt));
	if (setup_clt_info(clt) == 84)
		return (clt_err("Setup clt info failed\n", 84, clt));
	handle_server(clt);
	clear_clt(clt);
	return (0);
}
