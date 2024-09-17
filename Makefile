# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhuck <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 18:23:14 by jhuck             #+#    #+#              #
#    Updated: 2024/09/17 19:10:20 by jhuck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SVR = server
CLNBN = client_bonus
SVRBN = server_bonus

LIBFT = ./libs/libft/libft.a
PRINTF = ./libs/ft_printf/libftprintf.a
LIBS = libs/
SRC_DIR = src/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I
RM = rm -f

SRCCLRCCL = $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
SRCSV = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))
SRCCLB = $(addprefix $(SRC_DIR), $(addsuffix .c, $(CLNBN)))
SRCSVB = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVRBN)))

OBJCL = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
OBJSV = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))
OBJCLB = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLNBN)))
OBJSVB = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVRBN)))


start:				
	@make all
	@make bonus

$(LIBFT):
	@make -C ./libft

all: $(NAME) $(SVR)		

$(NAME): $(OBJCL) $(LIBFT) $(PRINTF)
		@$(CC) $(CFLAGS) $(LIBS) $(OBJCL) $(LIBFT) $(PRINTF) -o $(NAME)

$(SVR):	$(OBJSV) $(LIBFT) $(PRINTF)
		@$(CC) $(CFLAGS) $(LIBS) $(OBJSV) $(LIBFT) $(PRINTF) -o $(SVR)
					
bonus:	$(CLNBN) $(SVRBN)

$(CLNBN):	$(OBJCLB) $(LIBFT) $(PRINTF)
			@$(CC) $(CFLAGS) $(LIBS) $(OBJCLB) $(LIBFT) $(PRINTF) -o $(CLNBN)

$(SVRBN):	$(OBJSVB) $(LIBFT) $(PRINTF)
			@$(CC) $(CFLAGS) $(LIBS) $(OBJSVB) $(LIBFT) $(PRINTF) -o $(SVRBN)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(LIBS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
			
fclean:				clean
					@$(RM) $(NAME) $(SVR) $(CLNBN) $(SVRBN)
					@$(RM) $(LIBFT)

re:					fclean all

.PHONY:				start all clean fclean re bonus
