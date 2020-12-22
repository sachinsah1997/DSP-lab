#include <stdio.h> 

void towerOfHanoi(int n, char source, char destination, char auxilary) 
{ 
	//if there is only one disk then we just have to move the disk from source to destination.
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from %c to %c", source, destination); 
		return; 
	}
	// recursion method is called. top 1 disk is removed from source and added in auxilary with help of destination. 
	towerOfHanoi(n-1, source, auxilary, destination); 
	printf("\n Move disk %d from %c to %c", n, source, destination); 
	// recursion method is called. top 1 disk is removed from source and added in destination with help of auxilary. 
	towerOfHanoi(n-1, auxilary, destination, auxilary); 
} 

int main() 
{ 
	// no of disks in source is 3
	int n=3;
	// no of rods is 3 
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0; 
} 
