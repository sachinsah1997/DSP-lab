#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#define r 10

typedef struct node {
	int data;
	struct node  *next;
	struct node  *prev;
} NODE;

typedef struct deque {
	int count;
	NODE *head;
} DEQUE;

// Instantiates our doubly ended queue using a doubly linked list
DEQUE *createDeque(void) {
	NODE *np;
	DEQUE *bins;
	bins = malloc (sizeof (DEQUE));
	np = malloc (sizeof (NODE));
	assert (bins != NULL && np != NULL);
	bins -> head = np;
	np -> next = np;
	np -> prev = np;
	bins -> count = 0;
	return (bins);
}

// Returns the number of items in the deque
int numItems (DEQUE *bins) {
	return (bins -> count);
}

// Adds an integer to the front of the deque
void addFirst (DEQUE *bins, int x) {
	NODE *np;
	np = malloc (sizeof (NODE));
	assert  (np != NULL);
	np -> data = x;
	np -> next = bins -> head -> next;
	np -> prev = np -> next -> prev;
	np -> next -> prev = np;
	bins -> head -> next = np;
	bins -> count++;
}

// Adds an integer to the end of the deque
void addLast (DEQUE *bins, int x) {
	NODE *np;
	np = malloc (sizeof (NODE));
	assert (np != NULL);
	np -> data = x;
	np -> next = bins -> head;
	np -> prev = bins -> head -> prev;
	np -> prev -> next = np;
	bins -> head -> prev = np;
	bins -> count++;
}

// Removes & frees an integer from the front of the deque
int removeFirst (DEQUE *bins) {
	int x;
	assert (bins != NULL && bins -> count != 0);
	bins -> head -> next = bins -> head -> next -> next;
	x = bins -> head -> next -> prev -> data;
	free (bins -> head -> next -> prev);
	bins -> head -> next -> prev = bins -> head;
	bins -> count--;
	return (x);
}

// Removes & frees an integer from the end of the deque
int removeLast (DEQUE *bins) {
	int x;
	assert (bins != NULL && bins -> count != 0);
	bins -> head -> prev = bins -> head -> prev -> prev;
	x = bins -> head -> prev -> next -> data;
	free (bins -> head -> prev -> next);
	bins -> head -> prev -> next = bins -> head;
	bins -> count--;
	return (x);
}

// Returns integer of the first item in the deque
int getFirst (DEQUE *bins) {
	return (bins -> head -> next -> data);
}

// Returns integer of the last item in the deque
int getLast (DEQUE *bins) {
	return (bins -> head -> prev -> data);
}


int main (void) {
	int i,j,k,x,y,z;
	int num;
	int max = 0;

    	// Creates main deque which acts as a buffer
	DEQUE *toBeSorted;
	toBeSorted = createDeque();
	 int n;
	scanf("%d", &n);
	
	if(n > 0){
	for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        if(temp >=0){
        addLast(toBeSorted, temp);
        }else{
        printf("INVALID INPUT");
	    return 0;     
        }
            
        }}else{
	    printf("INVALID INPUT");
	    return 0;
	}

	
    	// Create 'r' amount of bins. 'r' represents the base of the numbers
	DEQUE *bins[r];
	for (i = 0; i < r; i++) {
		bins[i] = createDeque();
	}

	// Loop through all significant digits until finished
	int atTheEnd = 0;
	i = 0;


	// Continue looping for all significant digits
	while (!atTheEnd) {
		atTheEnd = 1; // Only remains true if we are calculating for the highest significant digit.

        	// Remove from main deque and place into respective bins
		while(numItems(toBeSorted) != 0) {
			z = removeFirst(toBeSorted);
			y = (z / ((int)pow(10,i))) % 10;
			addLast(bins[y], z);

			if ((z / ((int)pow(10,i))) > 0) {
				atTheEnd = 0;
			}
		}

        	// Removes from bins in order then places back into main deque
		for (j = 0; j < r; j++) {
			while (numItems(bins[j]) != 0) {
				z = removeFirst(bins[j]);
				addLast(toBeSorted,z);
			}
		}

		i++;
	}

    	// Print sorted numbers
	for (i = 0; i < numItems(toBeSorted); i++) {
		k = removeFirst(toBeSorted);
		printf ("%d ", k);
		addLast(toBeSorted,k);
	}

}