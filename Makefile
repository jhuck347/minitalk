# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 17:32:02 by juhuck            #+#    #+#              #
#    Updated: 2025/06/25 17:32:07 by juhuck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = client
SVR     = server
CLNBN   = client_bonus
SVRBN   = server_bonus

LIBFT   = ./libft/libft.a
SRC_DIR = src/
OBJ_DIR = obj/

CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -I inc/
RM      = rm -f

SRCCL   = $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
SRCSV   = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))
SRCCLB  = $(addprefix $(SRC_DIR), $(addsuffix .c, $(CLNBN)))
SRCSVB  = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVRBN)))

OBJCL   = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
OBJSV   = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))
OBJCLB  = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLNBN)))
OBJSVB  = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVRBN)))

start:
	@make all
	@make bonus

$(LIBFT):
	@make -C ./libft

all: $(NAME) $(SVR)

$(NAME): $(OBJCL) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJCL) $(LIBFT) -o $(NAME)

$(SVR): $(OBJSV) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSV) $(LIBFT) -o $(SVR)

bonus: $(CLNBN) $(SVRBN)

$(CLNBN): $(OBJCLB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJCLB) $(LIBFT) -o $(CLNBN)

$(SVRBN): $(OBJSVB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSVB) $(LIBFT) -o $(SVRBN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME) $(SVR) $(CLNBN) $(SVRBN)
	@make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re start
