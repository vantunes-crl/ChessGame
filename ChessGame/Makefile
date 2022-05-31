NAME = ChessGame

INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -g

SRCS = main.cpp main_game.cpp table.cpp pawn.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	clang++ ${FLAGS} -c $< -o $@

$(NAME): $(OBJS)
	clang++ $(OBJS) $(INCLUDE) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all