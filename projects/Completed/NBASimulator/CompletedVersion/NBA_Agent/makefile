OBJS = User.o UserUtil.o mainProgram.o PlayerUtil.o Player.o Rookies.o RookiesUtil.o
CC = g++

MainTester: $(OBJS)
	g++ -o MainTester $(OBJS)

PlayerUtil.o: 
	g++ -c PlayerUtil.cpp

Player.o: 
	g++ -c Player.cpp
	
UserUtil.o: 
	g++ -c UserUtil.cpp
	
mainProgram.o: 
	$(CC) -c mainProgram.cpp
	
User.o:
	g++ -c User.cpp
	
Rookies.o:
	g++ -c Rookies.cpp
	
RookiesUtil.o:
	g++ -c RookiesUtil.cpp
	
clean:
	rm -f core User $(OBJS)