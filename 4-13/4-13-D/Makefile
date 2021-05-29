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
	cat in1.txt | ./$(EXEC) > out1.txt
	diff out1.txt stdout1.txt
	cat in2.txt | ./$(EXEC) > out2.txt
	diff out2.txt stdout2.txt