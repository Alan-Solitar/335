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
ALL_OBJ0=CreateAndTestHash.o 
PROGRAM_0=CreateAndTestHash
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1=TestBinomialQueue.o
PROGRAM_1=TestBinomialQueue
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)


run1linear: 	
		./$(PROGRAM_0) words.txt query_words.txt linear

run1quadratic: 	
		./$(PROGRAM_0) words.txt query_words.txt quadratic

run1double: 	
		./$(PROGRAM_0) words.txt query_words.txt double

run1chaining: 	
		./$(PROGRAM_0) words.txt query_words.txt chaining

run0binomial5:
		./$(PROGRAM_1) 5_numbers.txt 0

run0binomial20:
		./$(PROGRAM_1) 20_numbers.txt 0

run0binomial100:
		./$(PROGRAM_1) 100_numbers.txt 0

run0binomial1000:
		./$(PROGRAM_1) 1000_numbers.txt 0

run0binomial10000:
		./$(PROGRAM_1) 10000_numbers.txt 0

run1binomial5:
		./$(PROGRAM_1) 5_numbers.txt 1

run1binomial20:
		./$(PROGRAM_1) 20_numbers.txt 1

run1binomial100:
		./$(PROGRAM_1) 100_numbers.txt 1

run1binomial1000:
		./$(PROGRAM_1) 1000_numbers.txt 1

run1binomial10000:
		./$(PROGRAM_1) 10000_numbers.txt 1

#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1))



(:
