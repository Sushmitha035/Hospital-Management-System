CPP = g++ 
FLAGS = -O3 -pg -Wall -W
RM  = rm -f
EXEC = final

OBJECTS = \
	 HMS.o \


all: $(OBJECTS) compile touch 


HMS.o : HMS.cpp
					 $(CPP) $(FLAGS) -c HMS.cpp


clean:  
					 $(RM) $(OBJECTS) $(EXEC) 

compile: 
					 $(CPP) $(FLAGS) $(OBJECTS) -o $(EXEC) 

touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "