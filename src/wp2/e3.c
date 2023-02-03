// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 3 
// Submission code: 6PQVO9T (provided by your TA-s) 

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
//The funtion returns a person and takes in no value(void)
PERSON input_record(void){

//declaration of a PERSON person for the details to be inserted my the users
//The inserted persons details will be assigned to this new_person
PERSON new_person;

// Ask the user to type the details we need

//print out a statement to ask the user to input the first name
printf("Enter first name: \n");

//We scan the the entered first name and assign it to new_person's first name
scanf("%s", &new_person.firstname);

//print out a statement to ask the user to enter the familyname(Lastname)
printf("Enter family name: \n");

//Scan the inserted family name then assign it to new_persons family name attribute
scanf("%s", &new_person.famname);

//Print out a statement to ask for the social security number 
printf("Enter the person's social security number(ssn): \n");

//We assign the inserted social security number to the new_persons pers_number
scanf("%s", &new_person.pers_number);

//we return a person
return new_person;

}    

//====================================================================================================
// Creates a file and writes the first record
//The function returns nothing(void) but takes in a person struct pointer(*inrecord) 
 void write_new_file(PERSON *inrecord) {

    //We initialize a file pointer (people)
    FILE *people; 

    //Open the file with a file name (people.bin) in binary form using (wb)
    people = fopen("people.bin", "wb");
  
    //We write the earlier initialized person to the new file we opened above in line 71
    //we write inrecord to people.bin, once(1)
    fwrite(inrecord, sizeof(PERSON), 1, people);

    // Close the file
    fclose(people);

}  

//====================================================================================================
// Prints out all persons in the file
void printfile(void) {
    //Create a file pointer (people)
    FILE *people;

    //Creating a PERSON pointer(person)
    PERSON person;

    //Opening the people.bin file in reading mode only using (rb)
    people = fopen("people.bin", "rb");

    //Checking if the file was succesfully opened otherwise print an error message
    if (people != NULL) {
        //printf("Error opening file.\n");
        fseek(people, 0, SEEK_END);
                // Check if the position of the last character is 0 to know if the file is empty
        if (ftell(people) == 0)
        {
            // Print the message that the file is still empty
            printf("The file you are searching in is empty.\n");
        }
    }

        // Going back to the beginning of the file to allow it to be read if not empty
        fseek(people, 0, SEEK_SET);

    //while the file exists
    while (fread(&person, sizeof(PERSON), 1, people) == 1) {
        printf("\nFirst name: %s\n", person.firstname);
        printf("Family name: %s\n", person.famname);
        printf("Personal number: %s\n", person.pers_number);
        printf("\n");
    }
    //close the file
    fclose(people);
 
}

//=======================================================================================================
//search for a person using their first name from the file
// Prints out the person if in list 
void search_by_firstname(char *name) {

    //we declare a file pointer (people)
    FILE *people;

    //initializing a PERSON pointer
    PERSON person;

    if((people=fopen("people.bin", "rb")) == NULL){ // checks if the file exists
        printf("The file doesn't exist!"); // print an error message if the file does not exist
    }
    else{
        //else we open the file if it exists
        people = fopen("people.bin","rb"); // open the file

        while(fread(&person, sizeof(PERSON), 1, people) == 1 ) { // reading 1 person from the file handler(reading maximum one element)
            if (strcasecmp(name, person.firstname) == 0) { // compare the input with the data in the file
                printf("\nSuccessfully found.\n First name: %s \n family name: %s \n personnal number: %s \n", person.firstname, person.famname, person.pers_number); // print all the information of the user 
            }
        }

    }
    //close the file
    fclose(people); 

} 

//Search for a person using the second name from the file
//============================================================================================================
void search_by_second(char *name) {

    //initialize the file pointer
    FILE *people;
    //Initialize a person pointer
    PERSON person;

    if((people=fopen("people.bin", "rb")) == NULL){ // checks if the file exists
        printf("The file doesn't exist!"); //prints an error message if the file doesn't exist
    }
    else{ //else we open the file
        people = fopen("people.bin","rb"); // open the file

        while(fread(&person, sizeof(PERSON), 1, people) == 1 ) { // reading 1 person from the file handler(reading maximum one element)
            if (strcasecmp(name, person.famname) == 0) { // compare the input with the data in the file
                printf("\nSuccessfully found.\n First name: %s \n family name: %s \n personnal number: %s \n", person.firstname, person.famname, person.pers_number); // print all the information of the user 
            }
        }

    }
    //close the file
    fclose(people);

}


//=========================================================================================================
// appends a new person to the file
// function returns nothing(void) but takes in a PERSON pointer
void append_file(PERSON *inrecord) {

    //initializing a file pointer
    FILE *people; 

    //opening the file only for appending a new record using (ab). Adds a file to the end of the file
    people = fopen("people.bin", "ab");
    
    //wrinting the new record (inrecord) to the file people only once
    fwrite(inrecord, sizeof(PERSON), 1, people);

    // Close the file
    fclose(people);

} 



//=====================================================M.A.I.N=======================================================
 
 //Main function
int main(void){ 

    //creates a PERSON pointer
    PERSON ppost;

    //declaring a int option for the choice from the menu for the switch case
    int option;

        do { 
        //do the below code as long as the while condition is met

        //printing the menu with the choices from 1-5    
        printf("\nChoose the action you want to do: \n 1. Create a new and delete the old file.\n 2. Add a new person to the file.\n 3. Search for a person in the file. \n 4. Print out all in the file.\n 5. Exit the program. ");

        //taking the user input(choice/option number)
        scanf("%d", &option); 

        //passing the int option to the switch case
        switch(option) {

            // If the users chose option 1 
            case 1: 
                //Create a new and delete the old file
                // Ask the user to type the deatils we need

                //Ask for the user first name
                printf("Enter first name: \n");

                //scan the input first name and pass it to our person pointer value(ppost) at ppost firstname
                scanf("%s", &ppost.firstname);

                //Ask for the family name/last name
                printf("Enter family name: \n");

                //take the input fmily name inserted by the user and pass it to our person pointer(ppost) at ppost famname
                scanf("%s", &ppost.famname);

                //Ask the user for the social security number/pers_number then 
                printf("Enter the person's social security number(ssn): \n");

                //pass it to the respective ppost value attribute
                scanf("%s", &ppost.pers_number);

                //write our person pointer ppost and the values to our file
                write_new_file(&ppost);

                //break out
                break; 

            case 2:

                //Add a new person to the file. 
                //Gives an opportunity to put in one new person to a temp record and then add this record in 
                //the end of the file.
                // assign the value of our ppost pointer to the input record function which will return a new person with the inserted values
                ppost = input_record();

                //Append/add our ppost (person pointer) to the file using our append_file function
                //This will add the new person at the end of the file
                append_file(&ppost);

                break; 
            case 3:
                //Search for  person in the file
                //Gives you an opportunity to search for all persons with either a specified first name or  
               //family name (by choice). The program prints out all persons with that name. 
               //printing out the menu to allow the user to make a choice of how they want to search for the person in the file
               printf("Choose below through which option you would like to search for a person in the file\n");

               printf("1. Search by first name:\n"); // if the user choose 1, they will be alloed to search using the first name
               printf("2. Search by second name:\n"); // if the user choose 2, they will be alloed to search using the last name/family name

               //Assign the choice to a char 
               char choice[2];

               //Scan the value of the choice by the user 
               scanf("%s", &choice);

               // if the choice value by the user is equal to 1==ASCII value 49 
               if(*choice == 49) {

                    //declare a name pointer of char
                    char name[20];

                    //Ask the user to enter the first name of the person they want to search for in the file
                    printf("Enter the first name of the person you are searching for: \n");

                    //Scan to get the name inserted by the user
                    scanf("%s", &name);

                    //pass the inserted name(name to our fuynction search_by_firstname() )
                    search_by_firstname(name);
                //else if the value of users choice is equal to 2==ASCII value 50
               } else if(*choice == 50) {

                    //declare a char of name
                    char name[20];

                    //ask the user to provide the last name of the person they want to search for in the file
                    printf("Enter the second name of the person you are searching for: \n");

                    //scan the user input to get the last name
                    scanf("%s", &name);
                    
                    //pass the newly entered last name to our function ---> search_by_second() which searches for a person using the second name in our file
                    search_by_second(name);

               } else {
                //else throw an error message for any other invalid input
                    printf("Invalid choice!! Please enter either 1 or 2.");

                    //then end the program
                    return 1;
                }
                break; 
            case 4: 
                //Print out all in the file
                //Prints out the whole list
                //call the printfile function to print all the people in our file
                printfile();  
                break;

            default: 
                break;
        }
        //all the above is to be done as =long as the user chooses between 1-4 from the menu and terminates when they choose 5 or any other number
    } while (option <= 4 && option >= 1);

  
    
    return(0);     
}