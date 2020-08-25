# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jconcent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 12:27:21 by jconcent          #+#    #+#              #
#    Updated: 2020/08/20 14:39:56 by jconcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libft.a

ARRAYPATH:= ft_array/
ARRAY:= ft_array_clear ft_array_insert ft_array_resize ft_array_reserve ft_array_print ft_array_add ft_array_pop

PRINTFPATH:= ft_printf/
PRINTF:= display float float_and_decimal float_utility ft_printf get_numbers search_flags string_and_hexadecimal upper_type utility

ISPATH:= ft_is/
IS:= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_isspace

LSTPATH:= ft_lst/
LST:= ft_clear_list ft_list_len ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_lstpushback

MEMPATH:= ft_mem/
MEM:= ft_bzero ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset

PUTPATH:= ft_put/
PUT:= ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd

STRPATH:= ft_str/
STR:= ft_atoi ft_clear_table ft_itoa ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
		ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat \
		ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsort ft_strsplit ft_strstr ft_strsub ft_strtrim \
		ft_tolower ft_toupper ft_wordcounter get_next_line

CC:=gcc
OBJPATH:=obj/
SRCPATH:=src/
HPATH:=include/
CFLAGS:=-Wall -Wextra -Werror -I $(HPATH)

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"

FILES+=$(addprefix $(ARRAYPATH), $(ARRAY))
FILES+=$(addprefix $(PRINTFPATH), $(PRINTF))
FILES+=$(addprefix $(ISPATH), $(IS))
FILES+=$(addprefix $(LSTPATH), $(LST))
FILES+=$(addprefix $(MEMPATH), $(MEM))
FILES+=$(addprefix $(PUTPATH), $(PUT))
FILES+=$(addprefix $(STRPATH), $(STR))

SRC:=$(addprefix $(SRCPATH), $(addsuffix .c, $(FILES)))
OBJ:=$(addprefix $(OBJPATH), $(addsuffix .o, $(FILES)))

CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) " - Compiling $@"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done"

$(OBJPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(OBJPATH)
	@mkdir $(OBJPATH)$(ARRAYPATH)
	@mkdir $(OBJPATH)$(PRINTFPATH)
	@mkdir $(OBJPATH)$(ISPATH)
	@mkdir $(OBJPATH)$(LSTPATH)
	@mkdir $(OBJPATH)$(MEMPATH)
	@mkdir $(OBJPATH)$(PUTPATH)
	@mkdir $(OBJPATH)$(STRPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(OBJPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) $(HPATH) | grep -v Norme -B1 || true

.PHONY: all clean fclean re test norme