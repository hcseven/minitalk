NAMESERVER = server
NAMECLIENT = client
NAMESERVERBNS = server_bonus
NAMECLIENTBNS = client_bonus
NAME = none.c
LIB = ./printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
SRCSERVERBNS = bonus_server.c
SRCCLIENTBNS = bonus_client.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
OBJSERVERBNS = $(SRCSERVERBNS:.c=.o)
OBJCLIENTBNS = $(SRCCLIENTBNS:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)

$(NAME) : all

bonus: $(LIB) $(NAMESERVERBNS) $(NAMECLIENTBNS)

$(LIB):
	make -C ./printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)

$(NAMESERVERBNS) : $(OBJSERVERBNS)
	$(CC) $(OBJSERVERBNS) -o $(NAMESERVERBNS) $(LIB)

$(NAMECLIENTBNS) : $(OBJCLIENTBNS)
	$(CC) $(OBJCLIENTBNS) -o $(NAMECLIENTBNS) $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJSERVERBNS) $(OBJCLIENTBNS)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT) $(NAMESERVERBNS) $(NAMECLIENTBNS)

ffclean: fclean
	make fclean -C ./printf

.c.o:
	$(CC) $(FLAGS) -c $^ -o $@

re:fclean all

.PHONY : re fclean clean all ffclean norm