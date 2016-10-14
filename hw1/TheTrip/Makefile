CC=g++ -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
CLEAN=rm -f
# Name of the program
PM=run
# Object files
OF=*.o
# Source files
SF= main.cpp


$(PM):  $(OF)
	$(CC) -o $@ $^

$(OF): $(SF)
	$(CC) -c $^

clean:
	$(CLEAN) *.o
	$(CLEAN) $(PM)
