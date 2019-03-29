SRC = $(wildcard *.cpp)
NAME = project_7

$(NAME): $(SRC)
	g++ -g $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)