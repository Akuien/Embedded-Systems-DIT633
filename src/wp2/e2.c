// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5   
 
// ##### typedefs          #### 
typedef struct q{  
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(void); 
REGTYPE* add_first(REGTYPE* temp, int data); 
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0, user_input;


    REGTYPE *act_post , *head=NULL;
    
    srand(time(0)); // Random seed
    head=random_list(); 

    act_post=head; 
    while( act_post!=NULL){ 

        printf("\n Post nr %d : %d", nr++, act_post->number); 
        act_post=act_post->next; 
    }

    printf("\nEnter a new record: ");
    scanf("%d", &user_input);

    head = add_first(head, user_input);
    nr = 0;
    while( head !=NULL){ 

    printf("\n Post nr %d : %d", nr++, head->number);  
    head=head->next; 
    }


    add_first(head, user_input);


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
    int nr, i=0; 
    REGTYPE *top, *old, *item, *n1 = NULL, *n2 = NULL, *n3 = NULL, *n4 = NULL;
    
    top = malloc(sizeof(struct q));
    // item = malloc(sizeof(struct q));
    // old = malloc(sizeof(struct q));
    n1 = malloc(sizeof(struct q));
    n2 = malloc(sizeof(struct q));
    n3 = malloc(sizeof(struct q)); 
    n4 = malloc(sizeof(struct q)); 
    srand(time(0));

    
    
    // for (i; i < MAX; i++)
    // {
    //     top = item;
    //     if(i <= 4) {
    //         item->number = rand() % 100;
    //     }
    //     item = item->next;

    //     if(i == 4) {
    //         item->next = NULL;
    //     }
        
    // }

    top->number = rand() % 100; 
    n1->number = rand() % 100;  
    n2->number = rand() % 100;  
    n3->number = rand() % 100;  
    n4->number = rand() % 100; 

    top->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

   return (top); 
} 
 
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data){

    struct q* new_rec = (struct q*) malloc(sizeof(struct q));

    new_rec->number = data;

    new_rec->next = temp;
    temp = new_rec;
    return temp;
}