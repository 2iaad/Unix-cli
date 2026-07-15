# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 17:00:51 by ibouram           #+#    #+#              #
#    Updated: 2024/08/04 18:32:43 by zderfouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARSINGSRC =	parsing/parsing.c parsing/quotes.c parsing/utils.c parsing/env_init.c main.c \
				parsing/add_space.c parsing/syntax_error.c parsing/Tokenizer.c parsing/lin_list.c parsing/signals.c\
				parsing/utils2.c parsing/expanding.c parsing/ft_split2.c parsing/remove_quotes.c parsing/struct.c \
				parsing/her_doc_expd.c parsing/trim_line.c parsing/lin_list2.c parsing/tokenizer2.c parsing/garbage_coll.c\
				parsing/expanding2.c parsing/struct2.c \

EXECUTIONSRC = 	execution/builtins/cd.c execution/builtins/echo.c execution/builtins/exit.c execution/builtins/caller.c \
				execution/builtins/export.c execution/builtins/pwd.c execution/builtins/unset.c execution/pipe_execute/heredoc_helper.c \
				execution/tools/equals_spliter.c execution/tools/helper_utils.c execution/pipe_execute/executer.c \
				execution/tools/lst_utils.c execution/tools/mini_utils.c execution/tools/split.c execution/tools/string_utils.c \
				execution/pipe_execute/exec_tools.c execution/pipe_execute/file_opener.c execution/pipe_execute/heredoc.c \
				execution/pipe_execute/pipex.c execution/pipe_execute/executer_helper.c execution/pipe_execute/file_helper.c \
				execution/pipe_execute/file_opener_s.c execution/tools/helper_builtins.c execution/tools/helper_export.c \
				execution/pipe_execute/executer_helper2.c \

RM = rm -rf
NAME = minishell
CC = cc
FLAGS = -ggdb3 # -fsanitize=address -Wall -Wextra -Werror

# macOS: brew readline is keg-only, needs explicit paths
UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
READLINE := $(shell brew --prefix readline 2>/dev/null)
INCS = -I$(READLINE)/include
LIBS = -L$(READLINE)/lib -lreadline
else
INCS =
LIBS = -lreadline
endif

PARSINGOBJS = $(PARSINGSRC:.c=.o)
EXECUTIONOBJS = $(EXECUTIONSRC:.c=.o)

all: deps $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "DONE"

# install readline dev headers if missing, using whatever package manager exists
deps:
	@echo '#include <readline/readline.h>' | $(CC) $(INCS) -E -x c - >/dev/null 2>&1 || { \
		echo "readline headers missing, installing..."; \
		if command -v brew >/dev/null 2>&1; then brew install readline; \
		elif command -v apt-get >/dev/null 2>&1; then sudo apt-get install -y libreadline-dev; \
		elif command -v dnf >/dev/null 2>&1; then sudo dnf install -y readline-devel; \
		elif command -v pacman >/dev/null 2>&1; then sudo pacman -S --noconfirm readline; \
		elif command -v zypper >/dev/null 2>&1; then sudo zypper install -y readline-devel; \
		elif command -v apk >/dev/null 2>&1; then sudo apk add readline-dev; \
		else echo "no known package manager; install readline dev package manually" && exit 1; fi; \
	}

$(NAME): $(PARSINGOBJS) $(EXECUTIONOBJS)
	@$(CC) $(FLAGS) $^ $(LIBS) -o $@

%.o: %.c minishell.h
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@$(RM) $(PARSINGOBJS) $(EXECUTIONOBJS)

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Clean"

re: fclean all

.PHONY: all deps clean fclean re