CC=g++

SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

EXEC=maincpp

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

.cpp.o:
	$(CC) -o $@ -c $< -DMYLINUX

clean:
	rm -rf $(OBJS)

check:
	cat in.txt | ./$(EXEC) > out.txt
	diff out.txt stdout.txt