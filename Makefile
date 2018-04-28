##
## EPITECH PROJECT, 2018
## PSU_myftp_2017
## File description:
## Makefile
##

NAME_SRV	=	server

NAME_CLT	=	myftp

SRC_SRV		=	srv/srv_free_struct.c		\
			srv/error_handling.c		\
			custom_error.c			\
			srv/create_socket.c		\
			srv/first_connection.c		\
			srv/get_help_to_display.c	\
			srv/send_msg_client.c		\
			srv/string_manipulation.c	\
			srv/authentification.c		\
			srv/is_a_command.c		\
			srv/help_and_noop_cmd.c		\
			srv/directory_cmd.c		\
			srv/delete_cmd.c		\
			srv/clear_close.c		\
			srv/launch_server.c		\
			srv/create_data_socket.c	\
			srv/activ_passiv_cmd.c		\
			srv/list_cmd.c			\
			srv/retr_cmd.c			\
			srv/stor_cmd.c			\
			srv/data_transfer_cmd.c		\
			srv/detect_cmd.c		\
			srv/get_port_infos.c		\
			srv/get_port_activ.c		\
			srv/create_data_port_socket.c	\
			srv/server.c

SRC_CLT		=	client/clt_free_struct.c	\
			custom_error.c			\
			client/usage_clt.c		\
			client/create_socket_clt.c	\
			client/error_clt.c		\
			client/handle_server.c		\
			client/client.c

INCS		=	-I./includes

OBJ_SRV		=	$(SRC_SRV:.c=.o)

OBJ_CLT		=	$(SRC_CLT:.c=.o)

CC		=	gcc

CFLAGS		=	$(INCS) -W -Wall -Wextra -Werror -g

RM		=	rm -rf

all: $(NAME_SRV) $(NAME_CLT)

$(NAME_SRV):$(OBJ_SRV)
	$(CC) -o $(NAME_SRV) $(OBJ_SRV) $(CFLAGS)

$(NAME_CLT):	$(OBJ_CLT)
	$(CC) -o $(NAME_CLT) $(OBJ_CLT) $(CFLAGS)

clean:
	$(RM) $(OBJ_CLT) $(OBJ_SRV)

fclean: clean
	$(RM) $(NAME_SRV)
	$(RM) $(NAME_CLT)

re: fclean all
