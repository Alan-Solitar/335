########################################
##
## Makefile
## LINUX compilation 
##
##############################################

#FLAGS
C++FLAG = -g -std=c++11 -Wall

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
ALL_OBJ0=CreateGraphAndTest.o 
PROGRAM_0=CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1=FindPaths.o
PROGRAM_1=FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ2=TestRandomGraph.o
PROGRAM_2=TestRandomGraph
$(PROGRAM_2): $(ALL_OBJ2)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)
		make $(PROGRAM_2)


run0graph1: 	
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries1.txt

run0graph2: 	
		./$(PROGRAM_0) Graph2.txt AdjacencyQueries2.txt

run1graph1: 	
		./$(PROGRAM_1) Graph1.txt 1

run1graph2: 
		./$(PROGRAM_1) Graph2.txt 1

run2five: 	
		./$(PROGRAM_2) 5

run2ten:
		./$(PROGRAM_2) 10

run2twenty:
		./$(PROGRAM_2) 20

run2fifty:
		./$(PROGRAM_2) 50

run2hundred:
		./$(PROGRAM_2) 100

run2thousand:
		./$(PROGRAM_2) 1000
		
run2hundredthousand:
		./$(PROGRAM_2) 100000


#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1))



(:
