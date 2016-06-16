CXX= g++
CXXFLAGS= -I./ -I./lua -g -llua -ldl
OBJ=main.o


all: $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -omain

$(OBJ): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@


.PHONY: clean
clean:
	@rm -rf $(OBJ)
