// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h> // used for standard output and input
#include <stdlib.h> // used for random number generation function.
#include <time.h> // used for generating random seed.
 
//#### Constants ##### 
#define MAX 5 // maximum size if 5
 
// ##### typedefs          #### 
typedef struct q{ // is a type struct, that creates an object. 
    int number; // number attribute of the struct q, stores a number value of the node.
    struct q *next; // is a pointer to the node after current node.
    struct q *prev; // is a pointer to the node before current node.
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(void); // functions that generates a linked list with random values.
REGTYPE* add_first(REGTYPE* temp, int data); // adds value entered by a user into the first position of the linked list.
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{
    int nr = 0, user_input; // integer nr is declared and initialized, it stands for the counter of number of records; user_input is used for storing input from a user in integer form.

    REGTYPE *act_post , *head; // we create act_post and head values which both will store the first node of the linked list

    srand(time(0)); // Random seed
    
    head=random_list(); // assign the first node of linked list to head value.

    act_post=head; // assign act_post to head.
    while( act_post!=NULL){  // while the node is not pointing at NULL

        printf("\n Post nr %d : %d", nr++, act_post->number); // print record number, and the random generated number.
        act_post=act_post->next; // keep pointing at the next node until NULL.
    }

    printf("\nEnter a new record: "); // print a statement which prompts the user to enter a new record.
    scanf("%d", &user_input); // take that input value from the user, and store it in user_input variable.

    head = add_first(head, user_input); // store the new record in head value.
    nr = 0; // set nr to 0 again.
    while( head !=NULL){  // while the node is not pointing at NULL

    printf("\n Post nr %d : %d", nr++, head->number);  // print record numbers and random generated numbers next to them.
    head=head->next; // keep pointing at next node until it points at NULL
    }


    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)
    {   
        head = act_post->next;          
        free(act_post); 
    } 
   
                    
 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(void){ 
    int nr, i=0; // integers nr and i are declared, where i is the counter of a for loop.
    REGTYPE *top, *old, *item; // declare REGTYPE variables and set them to NULL.
    // lines 75 through 79 are memory allocation for new nodes in the linkedlist, top is the first element in the linkedlist and n4 is the last element.
  

    srand(time(0)); // random seed generator to generate random numbers.

    for (i; i < MAX; i++) {
        item = malloc(sizeof(struct q));
        item->number = rand() % 100;

        if(i == 0) {
            top = old = item;
        } else {
            old->next = item;
            old = item;
        }
    }

    old->next = NULL;

    return (top); // return the first element of the linked list.
} 
 
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data){

    struct q* new_rec = (struct q*) malloc(sizeof(struct q)); // declaring and initializing new variable new_rec of type struct q, which will be the new record.

    new_rec->number = data; // assign the number of new_rec to data, which is a number entered by a user.

    new_rec->next = temp; // new_rec will be pointing at previous top node of the linkedlist.
    temp = new_rec; // the new top node of the linked list is assigned to new_rec. 
    return temp; // return the new top node of the linked list.
}