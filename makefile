all: report.exe

report.exe: report.o temp_functions.o
	gcc -o report.exe temp_functions.o report.o
	
report.o: report.c
	gcc -c --std=c99 -o report.o report.c
	
temp_functions.o: temp_functions.c
	gcc -c --std=c99 -o temp_functions.o temp_functions.c

clean:
	del *.o
	del report.exe
