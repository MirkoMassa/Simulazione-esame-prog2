OBJ = compito.o ospedale.o grafo.o
CXXFLAGS=-Wall

compito: $(OBJ)
	g++ -o compito $(OBJ)

compito.o: grafo.h ospedale.h
	g++ -c compito.cc

ospedale.o: grafo.h ospedale.h
	g++ -c ospedale.cc

grafo.o: grafo.h ospedale.h
	g++ -c grafo.cc

.PHONY: clean cleanall
clean:
	rm -f *.o
cleanall:
	rm -f compito *.o
