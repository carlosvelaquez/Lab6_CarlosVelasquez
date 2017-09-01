out: Numero.o Binario.o Hexadecimal.o Octal.o Decimal.o main.o
	g++ Numero.o Binario.o Hexadecimal.o Octal.o Decimal.o main.o -o out

main.o:	main.cpp Numero.h Binario.h Hexadecimal.h Octal.h
	g++ -c main.cpp

Decimal.o: Numero.h Decimal.h Decimal.cpp
	g++ -c Decimal.cpp

Numero.o: Numero.h Numero.cpp
	g++ Numero.cpp -c

Binario.o: Numero.h Binario.h Binario.cpp
	g++ Binario.cpp -c

Octal.o: Numero.h Octal.h Octal.cpp
	g++ Octal.cpp -c

Hexadecimal.o: Numero.h Hexadecimal.h Hexadecimal.cpp
	g++ Hexadecimal.cpp -c

clean:
	rm *.o out
