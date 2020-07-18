GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = supermercado

all: $(PROGRAMA) zip

$(PROGRAMA): Estabelecimento.o Cliente.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) *.o

main.o:	main.cpp
	$(GCC) $(GCC_FLAGS) -c main.cpp

Estabelecimento.o: Estabelecimento.cpp Estabelecimento.hpp
	$(GCC) $(GCC_FLAGS) -c Estabelecimento.cpp

Cliente.o: Cliente.cpp Cliente.hpp
	$(GCC) $(GCC_FLAGS) -c Cliente.cpp

run: $(PROGRAMA)
	./supermercado

clean:
	rm -f *.o
	rm $(PROGRAMA)

.PHONY: all zip

