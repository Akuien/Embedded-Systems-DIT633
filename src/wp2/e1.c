// (C) Anton Golubenko, Aditya Khadkikar, Akuien Deng - Group: 27 
// Work package 2 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

/* Importing libraries for input/output operations, string/number comparisons and checking purposes + more */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Fixed enum values for directions North (N), East (E), South (S) and West (W) */
enum DIRECTION {N,E,S,W};
 
/* A structure definition for a robot, with attributes of its position on the x-y axis, 
as well as its present direction (dir) which is one of the values from the DIRECTION enum (default is N) */
typedef struct {
  int xpos;
  int ypos;
  enum DIRECTION dir;
} ROBOT;

/* Function to move the robot ahead based on what direction the robot is facing towards */
void move(ROBOT* robotptr) {
  /* The switch cases only increase/decrease */
  switch (robotptr->dir) {
    case N: // if the robot is facing north, increase its y-pos by 1
      if (robotptr->ypos < 99) {
        (robotptr->ypos)++;
      }
      break;
    case E: // if the robot is facing east (right), increase its x-pos by 1
      if (robotptr->xpos < 99) {
        (robotptr->xpos)++;
      }
      break;
    case S: // if the robot is facing south, decrease y-pos by 1
      if (robotptr->ypos > 0) {
        (robotptr->ypos)--;
      }
      break;
    case W: // if the robot is facing west (left), decrease x-pos by 1
      if (robotptr->xpos > 0) {
        (robotptr->xpos)--;
      }
      break;
  }
}

/* Function to make the robot change its orientation based on the number of t chars received in the user's request */
void turn(ROBOT *robotptr) {
  /* Every t in the user's request string corresponds to a 90 degree turn clockwise. */
  switch (robotptr->dir) {
    case N: // If the robot faces north, and is told to turn, it will now face east
      robotptr->dir = E;
      break;
    case E: // If the robot faces east, and is told to turn, it will now face south
      robotptr->dir = S;
      break;
    case S: // If the robot faces south, and is told to turn, it will now face west
      robotptr->dir = W;
      break;
    case W: // If the robot faces west, and is told to turn, it will face back to north
      robotptr->dir = N;
      break;
  }
}

/* Main function of the robot control program */
int main(int argc, char * argv[]) {
  /* Variables for storing string input for x, y, and 'mt' string by user, that is processed later */
  char x[3]; 
  char y[3];
  char input[30];

  /* Declaring a pointer variable to a robot, and allocating space in the heap memory of the size of the struct */
  ROBOT* robot = malloc(sizeof(ROBOT));

  /* Run the program as a do-while loop (run at least once) */
  do {
    /* Initialise the robot's starting direction (N), x-pos (0) and y-pos (0) */
    robot->dir = N, robot->xpos = 0, robot->ypos = 0;

    /* Asks the user to put in the x-position that the robot should start with */
    printf("Please enter the initial x-position, or '-q' to quit: ");
    scanf("%s", x);

    /* Detecting whether escape string is provided ('-q'), then the program returns 2 and quits */
    if (strcmp(x, "-q") == 0) {
      free(robot);
      return 0;
    }

    /* Asks the user for where on the y-axis the robot is starting at */
    printf("Please enter the initial y-position, or '-q' to quit: ");
    scanf("%s", y);
    
    /* Also detecting whether the escape key is provided. With these checks, if -q is given, that
    escape key is used directly to exit out of the program regardless of which stage the user is in. */
    if (strcmp(y, "-q") == 0) {
      /* Free the allocated memory when the program is finished running */
      free(robot);
      return 0;
    }

    /* If the length of the characters is greater than 2, which is one of the ways to check if the
    provided number is not a >2 digit number. */
    if ((strlen(x) > 2) || (strlen(y) > 2)) {
      printf("\nX and Y coordinates must be a number between 0-99.\n\n");
      continue;
    }

    for (int i=0; i<strlen(x); i++) {
      /* Second part of the coordinates validation, as it now checks whether out of max. 2 digits, they are valid integers between 0-9 */
      if ((isdigit(x[i]) == 0) || (isdigit(y[i]) == 0)) {
        printf("\nThe coordinates are invalid. Please enter valid numbers as input.\n");
        /* Here it differs as it would quit the program. */
        /* Free the allocated memory when the program is finished running */
        free(robot);
        return 0;
      } else {
        robot->xpos = atoi(x);
        robot->ypos = atoi(y);
      }
    }

    /* Last stage, asking for a string of m's and t's that will dictate how the robot moves */
    printf("Please enter a string (consisting of m's and t's), or '-q' to quit: ");
    scanf("%s", input);

    /* Processing of the request string of m's and t's */
    for (int i=0; i<strlen(input); i++) {
      /* If escape key provided, then quit */
      if (strcmp(input, "-q") == 0) {
        free(robot);
        return 0;
      } else if (!(input[i] == 109 /* 'm' in ASCII code */ || input[i] == 116 /* 't' in ASCII code */)) {
        /* If the received string has any other characters than 'm' or 't' */
        printf("\nPlease enter a string containing only 'm's or 't's in your request.\n");
        return 0;
      } else if (input[i] == 116){
        /* If the current char in the string is a 't', then make the robot turn by calling the function turn() --> */
        turn(robot);  
      } else if (input[i] == 109) {
        /* If the current char in the string is a 'm', then move the robot by calling the function move() --> */
        move(robot);
      } else {
        /* If the string could not be processed, or does not get accepted */
        printf("\nPlease enter a valid coordinate between 0-99, or write -q to close the program.\n\n");
      }
    }

    /* Print the coordinates the robot moved, based on the passed requests */
    printf("\nCurrent pos: X: %d Y: %d\n\n", robot->xpos, robot->ypos);
  } while (strcmp(input, "-q") != 0);

  /* Close the program by returning 0 */
  return 0;
}