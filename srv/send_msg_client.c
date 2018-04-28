/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** send_msg_client.c
*/

#include "myftp.h"

int	txt_to_send(t_srv *srv, char *str)
{
	if (write(srv->client_fd, str, strlen(str)) == -1)
		return (1);
	return (0);
}

int	send_help_client(t_srv *srv, char *str)
{
	srv->hc = get_help_display(str);
	if (srv->hc == NULL)
		txt_to_send(srv, "xxx: ERROR WITH STRUCT HELP\n");
	else
		txt_to_send(srv, srv->hc->txt);
	return (0);
}

int	send_txt_client(t_srv *srv, int code)
{
	char	*tmp = calloc(BUFF_SIZE, sizeof(char));

	if (tmp == NULL)
		return (my_error("Can't calloc message to send\n", 84));
	srv->rc = get_txt_display(code);
	if (srv->rc == NULL)
		txt_to_send(srv, "xxx: ERROR WITH STRUCT\r\n");
	tmp[0] = '\0';
	tmp = strcat(tmp, srv->rc->s_code);
	tmp = strcat(tmp, " ");
	if (code == 257) {
		tmp = strcat(tmp, "\"");
		tmp = strcat(tmp, srv->pwd);
	}
	tmp = strcat(tmp, srv->rc->txt);
	tmp[strlen(tmp) + 1] = '\0';
	txt_to_send(srv, tmp);
	free(tmp);
	return (0);
}
