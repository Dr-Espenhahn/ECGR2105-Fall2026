#define the names of extra cpp & h files
EXTRAFILES = utils classes 

# define the name of executible (.exe)
PROGRAM_NAME = test 


# Default rule (creates .cpp, .h, and .o as necessary and creates .exe)
compile: main.o $(addsuffix .o,$(EXTRAFILES))
	g++ main.o $(addsuffix .o,$(EXTRAFILES)) -o $(PROGRAM_NAME)

# Only create .cpp and .h files (no .o or .exe)
generate: main.cpp $(addsuffix .cpp,$(EXTRAFILES))
	@echo Created file skeletons.

# Removes all files
delete:
	del *.o
	del *.cpp
	del *.h
	del *.exe

# Removes object files
clean:
	del *.o



# main.cpp -> main.o
main.o: main.cpp $(addsuffix .h,$(EXTRAFILES))
	g++ main.cpp -c

# Create all (non-main).o
%.o: %.cpp %.h
	g++ $< -c

main.cpp:
	$(file >main.cpp,#include <iostream>)
	$(foreach FILE,$(EXTRAFILES),$(file >>main.cpp,#include "$(FILE).h"))
	echo using namespace std; >> main.cpp
	echo. >> main.cpp
	echo int main^(^) { >> main.cpp
	echo. >> main.cpp
	echo     return 0; >> main.cpp
	echo } >> main.cpp

%.cpp: %.h
	echo #include ^<iostream^> >> $@
	echo #include "$*.h" >> $@
	echo using namespace std; >> $@

%.h:
	echo #ifndef $(shell powershell -Command "'$*'.ToUpper()")_H >> $@
	echo #define $(shell powershell -Command "'$*'.ToUpper()")_H >> $@
	echo. >> $@
	echo. >> $@
	echo. >> $@
	echo #endif >> $@

