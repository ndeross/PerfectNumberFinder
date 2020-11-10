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

int main(int argc, char* argv[]) {

int start, end, iter, sum; 
 
int n; 
 

start = atoi(argv[1]); 
end = atoi(argv[2]);  

for(n = start; n <= end; n++) { 

iter = 1; 
int sum = 0; 

while (iter < n) { 

if(n%iter == 0) 
	sum = sum + iter; 
	iter++; 
}


if (sum == n) { printf("%d ", n); 
		printf("\n"); } 

}
 
exit(0); 

}
