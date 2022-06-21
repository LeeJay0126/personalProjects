OBJS = User.o UserUtil.o LoginTester.o
CC = g++

LoginTest: $(OBJS)
	g++ -o LoginTest $(OBJS)

UserUtil.o: 
	g++ -c UserUtil.cpp

LoginTest.o: 
	$(CC) -c LoginTest.cpp
	

User.o:
	g++ -c User.cpp
	
clean:
	rm -f core User $(OBJS)