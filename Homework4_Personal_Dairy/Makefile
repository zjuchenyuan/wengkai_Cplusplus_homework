# Project: Homework4

CPP      = g++
RM       = rm -f
OBJ	= pdadd.o pdlist.o pdshow.o pdremove.o Dairy.o
BIN	= pdadd pdlist pdshow pdremove

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean:clean-custom
	${RM} $(OBJ) $(BIN)

Dairy.o: Dairy.cpp
	$(CPP) -c Dairy.cpp -o Dairy.o

pdadd: pdadd.cpp Dairy.o
	$(CPP) -c pdadd.cpp -o pdadd.o
	$(CPP) Dairy.o pdadd.o -o pdadd 

pdlist: pdlist.cpp Dairy.o
	$(CPP) -c pdlist.cpp -o pdlist.o
	$(CPP) Dairy.o pdlist.o -o pdlist

pdshow: pdshow.cpp Dairy.o
	$(CPP) -c pdshow.cpp -o pdshow.o
	$(CPP) Dairy.o pdshow.o -o pdshow 

pdremove: pdremove.cpp Dairy.o
	$(CPP) -c pdremove.cpp -o pdremove.o
	$(CPP) Dairy.o pdremove.o -o pdremove

