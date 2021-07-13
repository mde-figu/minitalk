SERVER		= server
CLIENT		= client
CC			= clang
FLAGS		= -Wall -Werror -Wextra
LIBS		= -L./libft -lft
LIBFT		= libft.a
LIBFT_PATH	= ./libft

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C $(LIBFT_PATH)

$(SERVER) : main_server.o fail.o include/minitalk.h
	@$(CC) main_server.o fail.o $(LIBS) -o $@
	@printf "\e[38;5;226m./$@ successfully build✅\e[0m\n"

$(CLIENT) : main_client.o fail.o include/minitalk.h
	@$(CC) main_client.o fail.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build✅\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I include

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;220m.o files deleted🚽\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;200mBinaries deleted🚽\e[0m\n"

re: fclean all
