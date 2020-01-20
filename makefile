output:
	g++ calcolatrice.cpp evaluate.cpp token.cpp -o calcolatrice

main.o:
	g++ -c main.cpp

evaluate.o:
	g++ -c evaluate.cpp main.cpp

token.o:
	g++ -c token.cpp evaluate.cpp main.cpp

clean:
	rm *.o calcolatrice
