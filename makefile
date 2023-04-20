a.out: menu.o system.o account.o
	g++ $^

menu.o: menu.cpp system.h account.h
	g++ -c menu.cpp

system.o: system.h system.cpp account.h
	g++ -c system.cpp

account.o: account.h account.cpp
	g++ -c account.cpp

clean:
	rm *.o a.out *.h.gch