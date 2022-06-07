NAME = ChessGame

TEST = ChessTest

INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -lgtest -lpthread

SRCS = ChessPieces/pawn.cpp ChessPieces/horse.cpp ChessPieces/bishop.cpp ChessPieces/king.cpp ChessPieces/knight.cpp ChessPieces/queen.cpp ChessPieces/rook.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	clang++ ${FLAGS} -c $< -o $@

$(NAME): $(OBJS)
	clang++ main.cpp $(OBJS) $(INCLUDE) -o $(NAME)

all: $(NAME)

test: $(OBJS)
	clang++ mainTest.cpp $(OBJS) $(INCLUDE) -o $(TEST)
	./$(TEST)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

run: all clean
	./ChessGame

re: fclean all