OBJS = Player.o PlayerUtil.o TestLinkedList.o
CC = g++

LinkedTest: $(OBJS)
	g++ -o LinkedTest $(OBJS)

UserUtil.o: 
	g++ -c UserUtil.cpp

TestLinkedList.o: 
	$(CC) -c TestLinkedList.cpp
	
Player.o:
	g++ -c Player.cpp
	
clean:
	rm -f core Player $(OBJS)