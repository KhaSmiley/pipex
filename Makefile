NAME			=	pipex

NAME_B			=	pipex_bonus

LIBFT			=	libft.a

DIR_SRCS		=	srcs

DIR_BONUS		=	bonus

DIR_OBJS		=	.objs

SRCS_NAMES		=	free_tab.c pipex.c utils.c utils_two.c

SRCS_BONUS		=	free_tab_bonus.c here_doc_bonus.c pipex_bonus.c utils_bonus.c utils_bonus_two.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_BONUS:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

DEPS_B			=	${SRCS_BONUS:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_BONUS))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))

INC				=	-Iinclude -Ilibft/include

LIB				=	-Llibft -lft

CC				=	cc

CDFLAGS 		= 	-MMD -MP

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

bonus: $(NAME_B)

$(NAME): $(DIR_OBJS) $(OBJS) 
	make -C libft
	$(CC) $(CFLAGS) ${INC} $(CDFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[31;7mpipex\033[0m"
	
$(NAME_B): $(DIR_OBJS) $(OBJS_B)
	make -C libft
	$(CC) $(CFLAGS) ${INC} $(OBJS_B) $(LIB) -o $(NAME_B)
	@echo "\033[34;7mpipex bonus\033[0m"


$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@ 

$(OBJS_B) : $(DIR_OBJS)/%.o : $(DIR_BONUS)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@ 

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}
	rm -rf ${NAME_B}

re:	fclean all

-include $(DEPS)
-include $(DEPS_B)

.PHONY:	all clean fclean re bonus
# .SILENT: