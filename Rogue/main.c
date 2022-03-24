#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
generate_world(void);
void main() {
	 char t[100];
	 while (1==1) {
		  COORD coord;
		 coord.X = 0;
		 coord.Y=0;
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
		 char* sq;
		 for (int y = 0; y < 30; y++)
		 {
			 for (size_t x = 0; x < 100; x++)
			 {
			
				 printf("\033[1;32mq");
			 }
			 printf("\n");
		 }
		
		
	 }
	
	
}


