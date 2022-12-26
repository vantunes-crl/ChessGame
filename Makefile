NAME = ChessGame

TEST = ChessTest

INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -g -pthread

SRCS =  MLPModel/MLP.cpp ChessPieces/horse.cpp ChessPieces/bishop.cpp ChessPieces/pawn.cpp ChessPieces/king.cpp ChessPieces/queen.cpp ChessPieces/rook.cpp BackTrackAlgorithm/BackTrack.cpp \
GUI/GUI.cpp 

# 
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
