.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
SRC=src
TEST=test

all: directories $(BIN)/ut_all $(BIN)/geo

$(BIN)/ut_all: $(OBJ)/ut_shape.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(BIN)/geo: $(OBJ)/geo.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(OBJ)/ut_shape.o: $(TEST)/ut_shape.cpp $(SRC)/shape.h $(SRC)/circle.h $(SRC)/rectangle.h $(SRC)/sort.h $(SRC)/triangle.h $(SRC)/picture.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/geo.o: $(SRC)/geo.cpp $(SRC)/shape.h $(SRC)/circle.h $(SRC)/rectangle.h $(SRC)/sort.h $(SRC)/triangle.h $(SRC)/picture.h
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJ) $(BIN)

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/* $(TEST)/*
