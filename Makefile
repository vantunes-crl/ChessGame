NAME = ChessGame

INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp pawn.cpp horse.cpp

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