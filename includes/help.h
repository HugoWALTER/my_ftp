/*
** EPITECH PROJECT, 2018
** PSU_myftp_2017
** File description:
** help.h
*/

#ifndef	HELP_H_
#define	HELP_H_

typedef	struct	s_rply_code
{
	int	id;
	int	code;
	char	*s_code;
	char	*txt;
}		t_rply_code;

static	const	t_rply_code	st_rply_code[] = {
	{ 0, 120, "120", "Service ready in nnn minutes.\r\n" },
	{ 1, 125, "125",
		"Data connection already open; transfer starting.\r\n" },
	{ 2, 150, "150",
		"File status okay; about to open data connection.\r\n" },
	{ 3, 200, "200", "Command okay.\r\n" },
	{ 4, 214, "214", "Help message.\r\n" },
	{ 5, 220, "220", "Service ready for new user.\r\n" },
	{ 6, 221, "221", "Service closing control connection.\r\n" },
	{ 7, 226, "226", "Closing data connection.\r\n" },
	{ 8, 227, "227", "Entering Passive Mode (" },
	{ 9, 230, "230", "User logged in, proceed.\r\n" },
	{ 10, 250, "250", "Requested file action okay, completed.\r\n" },
	{ 11, 257, "257", "\" created.\r\n" },
	{ 12, 331, "331", "User name okay, need password.\r\n" },
	{ 13, 332, "332", "Need account for login.\r\n" },
	{ 14, 530, "530", "Permission denied.\r\n" },
	{ 15, 540, "530", "Please login with USER and PASS.\r\n" },
	{ 16, 215, "214", "USER PASS CWD CDUP QUIT DELE PWD\r\n\
\tPASV PORT HELP NOOP RETR STOR LIST\r\n" },
	{ 17, 550, "550", "File doesn't exist.\r\n" },
	{ 18, 551, "550",
		"Can't remove directory or file doesn't exist.\r\n" },
	{ 19, 552, "550", "Failed to change directory.\r\n" },
	{ 20, 251, "250", "Directory successfully changed.\r\n" },
	{ 21, 252, "200", "Directory successfully changed.\r\n" },
	{ 22, 500, "500", "Unknow command.\r\n" },
	{ 23, 503, "503", "Login with USER first.\r\n" },
	{ 24, 504, "530", "Can't change from guest user.\r\n" },
	{ 25, 231, "230", "Already logged in.\r\n" },
	{ 26, 425, "425", "Use PORT or PASV first.\r\n" },
	{ 27, 426, "425", "Can't create data socket.\r\n" },
	{ 28, 201, "200", "Entering active mode.\r\n" },
	{ 29, 553, "550", "Can't list directory.\r\n" },
	{ 30, 554, "550", "Failed to open the file.\r\n" },
	{ 31, 555, "550", "Failed to create the file.\r\n" },
	{ 32, 505, "500", "Illegal PORT command.\r\n" },
	{ 33, 333, "331", "Please specify the password.\r\n" },
	{ 34, 534, "530", "Login incorrect.\r\n" },
	{ 35, 216, "214", "Help ok.\r\n" },
	{ 36, 556, "550", "Permission denied.\r\n" },
	{ -1, -1, "-1", "Error (RFC compliant)\r\n" }
};

typedef	struct	s_help_code
{
	int	id;
	char	*cmd;
	char	*txt;
}		t_help_code;

static	const	t_help_code	st_help_code[] = {
	{ 0, "USER",
	"USER <SP> <username> <CRLF> : Specify user for authentication\r\n" },
	{ 1, "PASS",
	"PASS <SP> <password> <CRLF> : Specify password for authentication\r\n"
		},
	{ 2, "CWD", "CWD <SP> <pathname> <CRLF> : Change working directory\r\n"
		},
	{ 3, "CDUP",
	"CDUP <CRLF> : Change working directory to parent directory\r\n" },
	{ 4, "QUIT", "QUIT <CRLF> :  Disconnection\r\n" },
	{ 5, "DELE",
	"DELE <SP> <pathname> <CRLF> : Delete file on the server\r\n" },
	{ 6, "PWD", "PWD  <CRLF> : Print working directory\r\n" },
	{ 7, "PASV",
	"PASV <CRLF> : Enable \"passive\" mode for data transfer\r\n" },
	{ 8, "PORT",
	"PORT <SP> <host-port> <CRLF> : Enable \"active\" mode to transfer\r\n"
		},
	{ 9, "HELP",
	"HELP [<SP> <string>] <CRLF> : List available commands\r\n" },
	{ 10, "NOOP", "NOOP <CRLF> : Do nothing\r\n" },
	{ 11, "RETR",
	"RETR <SP> <pathname> <CRLF> : Download file from server to client\r\n"
		},
	{ 12, "STOR",
	"STOR <SP> <pathname> <CRLF> : Upload file from client to server\r\n" },
	{ 13, "LIST",
	"LIST [<SP> <pathname>] <CRLF> : List files in the C.W.D\r\n" },
	{ -1, "ERROR", "Error no help found\r\n" }
};

#endif	/* !HELP_H_ */
