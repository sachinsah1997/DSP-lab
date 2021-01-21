#include <stdio.h>
#include <stdlib.h>

struct node{
    int position;
    struct node *next;
};

struct node *start_position= NULL;
struct node *current_position= NULL;

int find_survivor(int k){

    struct node* temp = NULL;
    temp = current_position = start_position;

    while (current_position->next != current_position){

        for (int i = 0; i < k-1; i++){
            current_position = temp;
            temp = temp->next;
        }

        current_position->next = temp->next;
        printf("%d has been killed.\n", temp->position);
        free(temp);
        temp = current_position->next;
    }

    start_position = temp;
    return (current_position->position);
}

void create_circle(int position){

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->position = position;
    temp->next = NULL;

    if (start_position == NULL){
        start_position = temp;
    }else{
       current_position->next = temp;
    }

    current_position = temp;
    current_position->next = start_position;
}

void display_circle(){

    current_position = start_position;

    printf("%d   ", current_position->position);
    current_position = current_position->next;
    while (current_position != start_position){
        printf("%d   ", current_position->position);
        current_position = current_position->next;
    }
    printf("\n");
}
 

int main(){

    int survived, skip;

    int total_criminal;
    printf("Enter the no of criminals  : ");
    scanf("%d", &total_criminal);
    
    printf("positions in the circle : ");
    for(int i=1; i<=total_criminal; i++){
                create_circle(i);   
    }
    
    display_circle();
    
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &skip);

    survived = find_survivor(skip);
    printf("The person to survive is at position : %d\n", survived);
    free(start_position);
    return 0;
}