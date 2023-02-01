#include <stdlib.h> 
#include <stdio.h> 
 
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
// Function declaration (to be extend) 
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
}    


// Creates a file and writes the first record 
void write_new_file(PERSON *inrecord) {
                PERSON inrecord = {
                .firstname = "Anton",
                .famname = "Aditya",
                .pers_number = "200201016598"
            };

            FILE *people;

            people = fopen("people.bin", "wb");

            if(people == NULL) {
                printf("Error occur while trying to open the file");
                return 1;
            }

            fwrite(&inrecord, sizeof(inrecord), 1, people);

            fread(&inrecord, sizeof(inrecord), 1, people);
            printf("firstname: %s\nfamname: %s\npers_number: %s",inrecord->firstname, inrecord->famname, inrecord->pers_number);

            fclose(people); 

}  

// Prints out all persons in the file
void printfile(void) {

 int n;

FILE *people;
if((people = fopen("people.bin", "wb") == NULL)) {
    printf("Error opening file");

} 

}

// Prints out the person if in list 
void search_by_firstname(char *name) {

} 

// appends a new person to the file
void append_file(PERSON *inrecord) {

}
 
int main(void){ 
    PERSON ppost;


        int option;

        do { 
        printf("\nChoose the action you want to do: \n 1. Create a new and delete the old file.\n 2. Add a new person to the file.\n 3. Search for a person in the file. \n 4. Print out all in the file.\n 5. Exit the program. ");
        scanf("%d", &option); 

        switch(option) { 
            case 1: 
                //Create a new and delete the old file
                printf("Create a new and delete the old file");

            PERSON p2 = {
                .firstname = "Anton",
                .famname = "Aditya",
                .pers_number = "200201016598"
            };

            FILE *people = fopen("people.bin", "wb");

            if(people == NULL) {
                printf("Error occur while trying to open the file");
                return 1;
            }

            fwrite(&p2, sizeof(p2), 1, people);

            fread(&p2, sizeof(p2), 1, people);
            printf("firstname: %s\nfamname: %s\npers_number: %s",p2.firstname, p2.famname, p2.pers_number);

            fclose(people);

                break; 
            case 2:
                //add a new person to the file
                printf("add a new person to the file");
                break; 
            case 3:
                //Search for  person in the file
                printf("Search for  person in the file");
                break; 
            case 4: 
                //Print out all in the file
                printf("Print out all in the file");
                break; 
            default: 
                break;
        }
    } while (option <= 4 && option >= 1);

  
    
    return(0);     
}