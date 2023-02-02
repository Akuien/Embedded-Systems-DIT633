// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdlib.h> 
#include <stdio.h> 
#include <strings.h>
 
// -----typedefs ------- 
//-----struct type of a person with firstname, familyname and socialsecuritynumber 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 



// Function declaration (to be extend)
//=========================================================================================================
// Reads a person’s record.
PERSON input_record(void){

PERSON new_person;

// Ask the user to type the deatils we need
printf("Enter first name: \n");
scanf("%s", &new_person.firstname);

printf("Enter family name: \n");
scanf("%s", &new_person.famname);

printf("Enter the person's social security number(ssn): \n");
scanf("%s", &new_person.pers_number);

return new_person;

}    

//====================================================================================================
// Creates a file and writes the first record 
 void write_new_file(PERSON *inrecord) {
    FILE *people; 

    people = fopen("people.bin", "wb");
  
    fwrite(inrecord, sizeof(PERSON), 1, people);
    // Close the file
    fclose(people);

}  

//====================================================================================================
// Prints out all persons in the file
void printfile(void) {

    FILE *peoples;

    PERSON person;

    peoples = fopen("people.bin", "rb");
    if (peoples == NULL) {
        printf("Error opening file.\n");
    }
    while (fread(&person, sizeof(PERSON), 1, peoples) == 1) {
        printf("First name: %s\n", person.firstname);
        printf("Family name: %s\n", person.famname);
        printf("Personal number: %s\n", person.pers_number);
        printf("\n");
    }
    fclose(peoples);
 
}

//=======================================================================================================
// Prints out the person if in list 
void search_by_firstname(char *name) {

    FILE *people;
    PERSON person;
    if((people=fopen("people.bin", "rb")) == NULL){ // checks if the file exists
        printf("The file doesn't exist!");
    }
    else{
        people = fopen("people.bin","rb"); // open the file

        while(fread(&person, sizeof(PERSON), 1, people) == 1 ) { // reading 1 person from the file handler(reading maximum one element)
            if (strcasecmp(name, person.firstname) == 0 || strcasecmp(name, person.famname) == 0) { // compare the input with the data in the file
                printf("%s %s %s \n", person.firstname, person.famname, person.pers_number); // print all the information of the user 
            }

        }

    }
 
    fclose(people); 

} 

//Search for a person using the second name
//============================================================================================================
void search_by_second(char *name) {

    FILE *people;
    PERSON person;
    if((people=fopen("people.bin", "rb")) == NULL){ // checks if the file exists
        printf("The file doesn't exist!");
    }
    else{
        people = fopen("people.bin","rb"); // open the file

        while(fread(&person, sizeof(PERSON), 1, people) == 1 ) { // reading 1 person from the file handler(reading maximum one element)
            if (strcasecmp(name, person.famname) == 0 || strcasecmp(name, person.famname) == 0) { // compare the input with the data in the file
                printf("%s %s %s \n", person.firstname, person.famname, person.pers_number); // print all the information of the user 
            }
        }

    }
 
    fclose(people);

}


//=========================================================================================================
// appends a new person to the file
void append_file(PERSON *inrecord) {
    FILE *people; 

    people = fopen("people.bin", "ab");
  
    fwrite(inrecord, sizeof(PERSON), 1, people);
    // Close the file
    fclose(people);

} 



//=====================================================M.A.I.N=======================================================
 
int main(void){ 
    PERSON ppost;
    int option;

        do { 
        printf("\nChoose the action you want to do: \n 1. Create a new and delete the old file.\n 2. Add a new person to the file.\n 3. Search for a person in the file. \n 4. Print out all in the file.\n 5. Exit the program. ");
        scanf("%d", &option); 

        switch(option) { 
            case 1: 
                //Create a new and delete the old file
                // Ask the user to type the deatils we need
                printf("Enter first name: \n");
                scanf("%s", &ppost.firstname);

                printf("Enter family name: \n");
                scanf("%s", &ppost.famname);

                printf("Enter the person's social security number(ssn): \n");
                scanf("%s", &ppost.pers_number);

                write_new_file(&ppost);

                break; 

            case 2:

                //Add a new person to the file. 
                //Gives an opportunity to put in one new person to a temp record and then add this record in 
                //the end of the file.
                ppost = input_record();
                append_file(&ppost);

                break; 
            case 3:
                //Search for  person in the file
                //Gives you an opportunity to search for all persons with either a specified first name or  
               //family name (by choice). The program prints out all persons with that name. 

               printf("Choose below through which option you would like to search for a person in the file\n");
               printf("1. Search by first name:\n");
               printf("2. Search by second name:\n");

               int choice;

               scanf("%d", &choice);

               if(choice == 1) {
                    char name[20];
                    printf("Enter the first name of the person you are seraching for: \n");
                    scanf("%s", &name);

                    search_by_firstname(name);
               } else if(choice == 2) {

                    char name[20];
                    printf("Enter the second name of the person you are seraching for: \n");
                    scanf("%s", &name);
                    
                    search_by_second(name);

               } else {
                printf("Invalid choice!! Please enter either 1 or 2.");
               }
    
                break; 
            case 4: 
                //Print out all in the file
                //Prints out the whole list
                printfile();  
                break; 
            default: 
                break;
        }
    } while (option <= 4 && option >= 1);

  
    
    return(0);     
}