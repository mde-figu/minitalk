SERVER		= server
CLIENT		= client
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
LIBS		= -L./libft -lft
LIBFT		= libft.a
LIBFT_PATH	= ./libft

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : main_server.o fail.o includes/minitalk.h
	@$(CC) main_server.o fail.o $(LIBS) -o $@
	@printf "\e[38;5;226m./$@ successfully build✅\e[0m\n"

$(CLIENT) : main_client.o fail.o includes/minitalk.h
	@$(CC) main_client.o fail.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build✅\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;220m.o files deleted🚽\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;220mBinaries deleted🚽\e[0m\n"

re: fclean all
