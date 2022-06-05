NAME = ChessGame

INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -g

SRCS = main.cpp ChessPieces/pawn.cpp ChessPieces/horse.cpp ChessPieces/bishop.cpp ChessPieces/king.cpp ChessPieces/knight.cpp ChessPieces/queen.cpp ChessPieces/rook.cpp

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

run: all clean
	./ChessGame

re: fclean all