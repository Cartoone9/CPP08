# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niroy <niroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 22:11:33 by jramiro           #+#    #+#              #
#    Updated: 2025/09/28 16:44:01 by jramiro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutant

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -g3 -std=c++98
INCS = -I./hdrs

SRCS = srcs/main.cpp \

O_DIR = .objs
OBJS = $(SRCS:%.cpp=$(O_DIR)/%.o)

RESET = \033[0m
GREEN = \033[0;32m
RED	= \033[0;31m
BLUE = \033[0;36m
YELLOW = \033[0;33m

BUILT = .built_makefile
COUNTER = .counter_makefile
COMPILED = .did_compile_makefile

CLEANUP = rm -rf $(BUILT) $(COUNTER) $(COMPILED) $(O_DIR)
ONFAIL  = || { $(CLEANUP); exit 1; }

all: reset_counter $(NAME)
	@if [ ! -f $(BUILT) ]; then \
		echo "$(NAME): $(YELLOW)$(NAME)$(RESET) is already up to date."; \
	fi
	@rm -f $(BUILT)
	@rm -f $(COUNTER)
	@rm -f $(COMPILED)

$(O_DIR)/%.o : %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ $(ONFAIL)
	@touch $(COMPILED)
	@count=`cat $(COUNTER)`; \
	count=`expr $$count + 1`; \
	echo $$count > $(COUNTER); \
	echo -n "\r$(NAME): compiling... $$count/$(words $(SRCS))"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(ONFAIL)
	@if [ -f "$(COMPILED)" ]; then \
		echo ""; \
		fi
	@echo "$(NAME): $(GREEN)$(NAME)$(RESET) has been compiled."
	@rm -f $(COUNTER)
	@rm -f $(COMPILED)
	@touch $(BUILT)

clean:
	@rm -rf $(O_DIR) $(BUILT) $(COUNTER) $(COMPILED)
	@echo "$(NAME): $(RED)$(O_DIR)$(RESET) has been deleted."

fclean:
	@rm -rf $(O_DIR) $(NAME) $(BUILT) $(COUNTER) $(COMPILED)
	@echo "$(NAME): $(RED)$(O_DIR)$(RESET) and $(RED)$(NAME)$(RESET) have been deleted."
	@rm -f Tom_shrubbery

re: fclean all

reset_counter:
	@echo 0 > $(COUNTER)

.PHONY: all clean fclean re reset_counter
