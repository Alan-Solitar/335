########################################
##
## Makefile
## LINUX compilation 
##
##############################################


#FLAGS
C++FLAG = -g -std=c++0x -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.

#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=TestBinPackingAlgorithms.o
PROGRAM_0=TestBinPackingAlgorithms
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

all:
	make $(PROGRAM_0)

runbins50: 	
		./$(PROGRAM_0) 50
runbins100: 	
		./$(PROGRAM_0) 100
runbins1000: 	
		./$(PROGRAM_0) 1000
runbins10000: 	
		./$(PROGRAM_0) 10000
runbins100000: 	
		./$(PROGRAM_0) 100000
runbins1000000: 	
		./$(PROGRAM_0) 1000000


#Clean obj files

clean:
	(rm -f *.o; rm -f TestTrees; rm -f QueryTrees; rm -f TestRangeQuery)



(:
