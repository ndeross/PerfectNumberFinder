// Nicholas DeRoss
// HW4 - Systems Programming 
// Mr. Molnar 
// 2/19/2020 

#include <string.h>
#include <stdbool.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>

#define BUFSIZE 1000

int main(int argc, char* argv[])
{
  char buf[BUFSIZE];
  const int MAX_ARG = 4;  
  int i = 1; 
  const int EXIT_CONDITION = -1; 
  int argCheck = 4;
  int numChildren;
  int numLow; 
  int numHigh;
  bool parseDone = false;       
  int numProccess; 
   
  numProccess = 0; 


  printf("\n");    
  
  if (argc > MAX_ARG) {                       // Validates correct number of arguments presented terminates if over 
   
      perror("Error too many arguments"); 
      exit(EXIT_CONDITION); 
  } 
  
      
 while (parseDone == false) {                // Loops and gets arguments until parseDone is set to true 
	 
     if(argv[i] != NULL)
		 
     { 
         switch(i)
         { 
             case 1: 
		    if (atoi(argv[i])) { numChildren = atoi(argv[i]);                     							  /* This blockhandles the first argument after ./HW3 */ 
					 if (argv[i+1]) { i++; } else {perror("ERROR: Incorrect argument number"); exit(EXIT_CONDITION); }   
                                        }
						else { perror("Error: Argument 1 invalid"); 
						       exit(EXIT_CONDITION); }   
					
					
                      
                     
             case 2: 
                    if (atoi(argv[i])) { numLow = atoi(argv[i]);                              							/* This block handles the low number parsing */  
					if (argv[i+1]) { i++; } else {perror("ERROR: Incorrect argument number"); exit(EXIT_CONDITION); }
                                       } 
						else { perror("ERROR: Argument 2 invalid "); 
						       exit(EXIT_CONDITION);  }   

	     

 	     case 3:                                                                           // this block handles the high number parsing 
                    if(atoi(argv[i])) { numHigh = atoi(argv[i]);                                                                     
                                         i++; } 
				      
                                                else { perror("ERROR: Argument 3 invalid ");
                                                       exit(EXIT_CONDITION); } 
             case 4: parseDone = true;                                                         // after last argument is parsed, loop is terminated 
			 
             break; 
			
			default: printf("Default Reached in Switch"); 
            
        }
 
      }
      
 }
 
int start = numLow; 
int end = numLow; 

int isParent = 1; // sets is parent to one, priming the loop to run the first time 
int iter = 0;     // primes iterator 
int pid; 


int dividerNumber; 
char* args[] = {"./PerfFinder", NULL, NULL, NULL}; // primes the args array to be sent to the second exe 
char low[5]; // primes "low" array, used for casting int to const char* 
char high[5]; // same deal 
 


dividerNumber = (numHigh - numLow ) / numChildren;      // Finds the number of ints to be handled by a single child, ensures (semi) even number for all children 

while (iter < numChildren && isParent) {                // Creates children and sets the numbers they have to process, also waits until processes finished  
    
start = end; 
end = start + dividerNumber;

isParent = fork();

	if (isParent == 0) {
        
                snprintf(low, BUFSIZE, "%d", start); // loads int value of low number into char array
  
                args[1] = low; 	
	            
                snprintf(high, BUFSIZE, "%d", end); // same here for the high number going to argument 2
 
                args[2] = high;
		printf("\n");   
                execv(args[0], args); // full argument array sent to other program 
      }


    
 iter++;
 
}

wait(); 
 

exit(0);                                      // Exits the child process when its finished with its set of numbers 
      
}
    
     
      
      
                   
                                   
