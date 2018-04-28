/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** client.h
*/

#ifndef	CLIENT_H_
#define	CLIENT_H_

#include "myftp.h"

typedef	struct	s_clt
{
	struct	protoent	*pe;
	struct	sockaddr_in	s_in;
	int			fd;
	int			port;
	char			*ip;
}		t_clt;

int			usage_clt(t_clt *);
int			xclt_free(t_clt *);
int			clear_clt(t_clt *);
int			create_clt_socket(t_clt *);
int			setup_clt_info(t_clt *);
int			clt_err(char *, int, t_clt *);
int			clt_error_handling(char **);
int			handle_server(t_clt *);
int			send_to_serv(t_clt *);
int			read_server(t_clt *);

#endif	/* !CLIENT_H_ */
