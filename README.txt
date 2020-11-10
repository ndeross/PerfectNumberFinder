This program relies on "PerfFinder.exe" 

Make sure "HW4.c" and "PerfFinder.c" are in the same directory 

using make, both can be compiled at the same time with the command: 

make HW4 PerfFinder 

or can be compiled seperate using the comands

HW4: gcc HW4.c -o HW4 

PerfFinder: gcc PerfFinder.c -o PerfFinder 

once compiled and executables are in the same folder, run using 

./HW4 [number of processes] [Lower Bound] [Upper Bound] 
 
