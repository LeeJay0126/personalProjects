OBJS = Rookies.o getRookies.o

RookieOut: $(OBJS)
	g++ -o RookieOut $(OBJS)
	rm -f $(OBJS)

Rookies.o:
	g++ -c Rookies.cpp
	

getRookies.o:
	g++ -c getRookies.cpp

clean:
	rm -f core StockTest $(OBJS)