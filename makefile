out: Numero.o Binario.o Hexadecimal.o Octal.o main.cpp
	g++ Binario.o Hexadecimal.o Octal.o main.cpp -o out

Numero.o: Numero.h Numero.cpp
	g++ Numero.cpp -c

Binario.o: Numero.h Binario.h Binario.cpp
	g++ Binario.cpp -c

Octal.o: Numero.h Octal.h Octal.cpp
	g++ Octal.cpp -c

Hexadecimal.o: Numero.h Hexadecimal.h Hexadecimal.cpp
	g++ Hexadecimal.cpp -c

clean:
	rm Binario.o Hexadeimal.o Octal.o
