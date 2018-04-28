/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** myftp.h
*/

#ifndef	MYFTP_H_
#define	MYFTP_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "help.h"
#include "client.h"

static	const	int		BUFF_SIZE = 1024;
static	const	int		READ_SIZE = 4096;
static	const	char	*const	NAME_USER = "Anonymous";

enum	s_enum
{
	PASSIV,
	ACTIV,
	ANY
};

typedef	struct	s_srv
{
	int			port;
	char			*path;
	struct	protoent	*pe;
	struct	sockaddr_in	s_in;
	struct	sockaddr_in	s_in_client;
	int			fd;
	socklen_t		s_in_size;
	int			client_fd;
	char			*client_ip;
	pid_t			pid;
	int			srv_auth;
	char			*scnd;
	t_rply_code	const	*rc;
	t_help_code	const	*hc;
	char			*pwd;
	int			mode;
	int			data_fd;
	int			port_data;
	int			port1;
	int			port2;
	int			filefd;
	char			*port_addr;
	int			nb_comma;
	int			bad_user;
}		t_srv;

int			xsrv_free(t_srv *);
int			clear_srv(t_srv *);
int			my_error(char *, int);
int			usage_srv(t_srv *);
int			is_number(char *);
int			error_handling(int, char **, t_srv *);
int			srv_err(char *, int, t_srv *);
t_rply_code	const	*get_txt_display(int);
t_help_code	const	*get_help_display(char *);
char			*get_current_dir_name(void);
int			create_socket(t_srv *);
int			setup_srv_info(t_srv *);
int			handle_client(t_srv *);
int			txt_to_send(t_srv *, char *);
int			send_help_client(t_srv *, char *);
int			send_txt_client(t_srv *, int);
char			*revstr(char *);
char			*epur_str(char *);
int			detect_user(t_srv *, char *, int);
int			detect_password(t_srv *, char *);
int			clt_not_auth(t_srv *);
int			clt_already_auth(t_srv *, char *);
int			is_a_command(char *);
int			help_and_noop_command(t_srv *, char *, int);
int			directory_command(t_srv *, char *, int);
int			delete_command(t_srv *, char *, int);
int			clear_close(t_srv *);
int			launch_server(t_srv *);
int			server_fork(t_srv *);
int			init_values(t_srv *);
int			detect_command(t_srv *);
int			init_pwd(t_srv *, char *);
int			accept_data_socket(t_srv *);
int			create_data_socket(t_srv *);
int			setup_data_info(t_srv *);
int			create_data(t_srv *);
int			activ_passiv_command(t_srv *, char *, int);
int			print_passiv_info(t_srv *);
int			fill_port_passiv(t_srv *);
int			port_command(t_srv *, char *);
int			data_dup2_function(t_srv *, char *, int);
int			launch_listing(t_srv *);
int			launch_specified_listing(t_srv *, char *);
int			list_cmd(t_srv *, char *, int);
int			check_file(t_srv *, char *);
int			launch_retr(t_srv *);
int			retr_cmd(t_srv *, char *, int);
int			check_valid_retr(t_srv *, char *);
int			creation_file(t_srv *, char *);
int			launch_stor(t_srv *);
int			check_valid_stor(t_srv *, char *);
int			stor_cmd(t_srv *, char *, int);
int			data_transfer_cmd(t_srv *, char *, int);
int			checking_commands(t_srv *, char *, int);
int			connect_data_socket(t_srv *);
int			check_list_cmd(t_srv *);
int			create_data_port(t_srv *);
int			setup_data_port_info(t_srv *);
char			*fill_port_addr(t_srv *, char *, int);
char			*get_port_addr(t_srv *);
int			get_port_p1_and_p2(t_srv *, char *);
int			check_host_port_validity(char *);
int			extract_p1(char *, int);
int			get_p1(char *);
int			extract_p2(char *, int);
int			get_p2(char *);
int			create_data_port(t_srv *);
int			start_passiv_or_activ_stor(t_srv *);
int			start_passiv_or_activ_retr(t_srv *);
int			detect_bad_user(t_srv *, char *, int);
int			cdup_command(t_srv *, char *, int);
int			check_cdup_directory(t_srv *);

#endif	/*! MYFTP_H_ */
