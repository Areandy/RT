NAME	= RT

#files
SRC		= main.c \
			secondary.c \
			render_text.c \
			rotate.c \
			get_normal.c \
			hit_or_miss.c \
			render.c \
			actions.c \
			actions_2.c \
			vector_operators_1.c \
			vector_operators_2.c \
			anaglyph.c \
			anaglyph_2.c \
			ui.c \
			pure_trash.c \
			shading.c \
			ray_trace.c \
			obj_hit.c \
			sdl_event.c \
			textures.c \
			parser/parser.c \
			parser/add_obj_funcs.c \
			parser/add_light_funcs.c \
			parser/get_light_sources.c \
			parser/cleaners.c \
			parser/gimy_gimy.c \
			parser/pokemons.c 

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

FL = -F Frameworks/ -rpath Frameworks/ -framework SDL2 -F Frameworks/ -rpath Frameworks/ -framework SDL2_image  -framework SDL2_ttf
SDLINC = -F Frameworks/
#compiler
CC		= gcc
FLAGS	= -g -Wall -Wextra -Werror

#ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT), libft.a)
FT_INC	= -I ./libft/
FT_LNK	= -L ./libft/ -lft

#directories
SRCDIR	= ./src/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME) 

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/scenes
	@mkdir -p $(OBJDIR)/parser

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) $(FT_INC) $(SDLINC)-I $(INCDIR) -o $@ -c $<
	@echo "(+) $@"

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(FT_LNK) $(FL) -lm -o $(NAME)
	@echo "$(GRN)$(NAME) is compiled!$(EOC)"

leak:
	@valgrind --leak-check=full  ./rtv1 scene.rtv1

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT) fclean

re: fclean all

GRN = \033[1;32m
EOC = \033[0m
