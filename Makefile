PROGRAM = burakole

CC = g++
CFLAGS = -std=c++17 -g -Wall -pedantic -Wno-long-long -O2

all: compile doc

run: compile
		./$(PROGRAM)

clean:
		rm -rf build/*.o $(PROGRAM) build/ doc/ 2>/dev/null

compile: $(PROGRAM)

doc: src/CMatrix.h src/CMatrixDense.h src/CMatrixSparse.h src/CUnaryOperation.h src/CBinaryOperation.h src/CException.h src/CMessage.h src/CParser.h src/CCalculator.h
		doxygen Doxyfile

$(PROGRAM): build/main.o build/CMatrix.o build/CMatrixDense.o build/CMatrixSparse.o build/CUnaryOperation.o build/CBinaryOperation.o build/CException.o build/CParser.o build/CCalculator.o
		$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.cpp
		mkdir -p build
		$(CC) $(CFLAGS) -c $< -o $@


build/CBinaryOperation.o: src/CBinaryOperation.cpp src/CBinaryOperation.h \
  src/CMatrix.h src/CException.h src/CMessage.h
build/CCalculator.o: src/CCalculator.cpp src/CCalculator.h src/CMatrix.h \
  src/CUnaryOperation.h src/CBinaryOperation.h src/CParser.h \
  src/CException.h src/CMessage.h
build/CException.o: src/CException.cpp src/CException.h src/CMessage.h
build/CMatrix.o: src/CMatrix.cpp src/CMatrix.h src/CMatrixDense.h \
  src/CMatrixSparse.h
build/CMatrixDense.o: src/CMatrixDense.cpp src/CMatrixDense.h src/CMatrix.h \
  src/CException.h src/CMessage.h
build/CMatrixSparse.o: src/CMatrixSparse.cpp src/CMatrixSparse.h src/CMatrix.h \
  src/CException.h src/CMessage.h
build/CParser.o: src/CParser.cpp src/CParser.h src/CMatrix.h src/CException.h \
  src/CMessage.h
build/CUnaryOperation.o: src/CUnaryOperation.cpp src/CUnaryOperation.h \
  src/CMatrix.h src/CBinaryOperation.h src/CException.h src/CMessage.h
build/main.o: src/main.cpp src/CCalculator.h src/CMatrix.h


