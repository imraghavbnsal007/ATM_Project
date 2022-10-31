/*---Program Description---

This program will show an ATM machine with a menu option in which when user enter a pin it will verify it.
When user will try to change the default Pin and run the code with new pin. This Program will show how many time that pin user entered is correct and incorrect. 
This program will run in loop and it will terminate when user want.

Author : Raghav Bansal

Compiler Used for making this code : Visual Studio Code
Date : 21/11/2020
*/

#include <stdio.h>

//The <string.h> header defines one variable type, one macro, and various functions for manipulating arrays of characters.
#include <string.h>

//This is header file for function especially for isdigit()
#include <ctype.h>

//this is the header file of function especially for strcpy()
#include <stdlib.h>

int main(void)
{ //start main

    //Declaration of Variables

    //initializing pin as char and this is the deafult pin
    char pin[] = {'1', '2', '3', '4', '\0'}; // we have a zero at the end to indicate that the pin has ended

    //Taking menu for making a menu which contains menu of program
    int menu;

    // variable to count the number of times pin was entered and it will show correctly entered and incorrectly entered.
    int correct_counter = 0;
    int incorrect_counter = 0;

    //variable userinput set to four digit
    char userinput[4];

    //variable for collecting the pin input
    char pinput[4] = "";

    // variable for collecting the validation pin input
    char validate[4];

    // we use this variable for copying the pin input.
    char interim_pin[6];

    //initializing flag variable to zero. it is used as  Boolean Variable where the result toggles between 0(False) and 1(True)
    int flag = 0;

    //using do-while loop, because do will execute the statement atleast once
    do
    { //start do loop

        /* This is menu option in which we have four option
         if user enter 1, enter your pin will pop-up, if user enter 2 it will ask for changing the pin, if user enter 3, it will display
         no of times pin entered correct and incorrect.
        */
        printf("\nSelect a menu option \n");

        printf("1. Enter Pin \n 2. Change Pin \n 3. Display no of times pin was entered \n 4. Exit program \n");
        scanf("%d", &menu);

        // Clear the buffer to ignore the "Enter" key used to select the menu option
        fflush(stdin);

        //using if statement because program will run in loop if user wnat to terminate the loop user must press 4
        if (menu == 4)
        { //Start if

            printf("\nThe program has to terminate\n");
            break;

        } //end if

        //using switch statement for different cases that will allow to do diffrent things
        switch (menu)
        { //start Switch

            /*
            case- 1 will take the pin from the user. the default pin is 1234. Also using if-else because if he enter pin write that will show pin is correct else wrong 
            */
        case 1:
            printf("\nEnter your pin\n");

            //this will clear the buffer
            fflush(stdin);

            //this is will take string userinput from user
            scanf("%s", userinput);

            //printf("This is the pin you entered %s ", userinput);

            //The strcmp() function compares two strings and returns 0 if both strings are identical.
            if (strcmp(userinput, pin) == 0)
            {
                printf("\nPin you entered is Correct and Verified\n");

                /*Using counter here because that will count for me how many times pin I entered is correct or not for menu option number 3*/
                correct_counter++;
            }

            //when user entered wrong pin this will pop-up
            else
            {
                printf("\nThe pin you entered is not correct\n");

                /*Using counter here because that will count for me how many times pin I entered is correct or not for menu option number 3 */
                incorrect_counter++;
            }

            break; //break statement for terminating this loop

            /*In case-2 it is basically a pin change option if user want   to change the pin or not
         if user wants to change the pin, user press 2 when menu option showed up in output then it will ask for new pin and ask it again for confirmation.*/

            //In the case 2 many functions are used for some error validation like strlen() , isdigit() , strcpy() and strcmp()
            //error validation like if user enter 0000 as the pin or 0004 because system don;t count zero
            //also if user enter non-interger value like a character so I used function for solving these problems

        case 2:
            printf("This is your pin %s\n", pin);

            printf("\nYou want to change your pin,\n please enter new pin\n");

            scanf("%s", pinput);

            //using if statement
            /*The strlen() function calculates the length of a given string.*/

            //if user tries to change the pin to 5-digits, user can't change it
            if (strlen(pinput) > 4)
            { //start if

                printf("\nYou have entered more than 4 characters\n");

                break;
            } //end if

            /*Function isdigit() takes a single argument in the form of an integer and returns the value of type int.*/

            //using if statement again that will execute that pin is always an integer value!!
            if (!isdigit(pinput[0]) | !isdigit(pinput[1]) | !isdigit(pinput[2]) | !isdigit(pinput[3]))
            { //start if

                //if user enter a character or any non-interger value while changing the pin, this will pop-up
                printf("\nYou put an invalid digit or character!!\nPlease enter value in integers\n");

                // /*Flag variables is usually given two values 0 and 1
                // It will give result in numbers always. It acts as a signal for a function  process.*/
                // flag = 1;

                break;

            } //end if

            //Here else will make sure that if user enter the null pin this will take only 4 digits not less than example 0000 and 0004 this will not change to 0 and 4 respectively.
            else
            { //start else

                //The strcpy() function copies the string pointed by source (including the null character) to the destination.
                strcpy(interim_pin, pinput);
                interim_pin[5] = 0;

            } //end else

            //This part will re-confirm the pin for verification
            printf("please enter new pin again\n");
            scanf("%s", validate);

            /*The strcmp() function compares two strings and returns 0 if both strings are identical.*/
            if (strcmp(interim_pin, validate) == 0)
            { //start if

                //new pin has been validated
                printf("\nPin you entered has been validated \n");
                strcpy(pin, validate);
                pin[5] = 0; //pin must be 4 digit

                //New pin
                printf("This is your new pin %s", pin);
            } //end if
            
            //if user enter wrong pin when changing it or re-confirming it 
            else 
            { //start else
                printf("The pins you have entered do not match\n");
                break;
            }//end else 

            break; //using break for terminating this loop

            /*In Case-3 we have to show how many time pin user enter is correct or not
            For that counter statement is used in case-1 that is counting the pin is wrong or correct
            */
        case 3:
            printf("The number of times you correctly entered your pin is %d \n\n", correct_counter);

            printf("The number of times you incorrectly entered your pin is %d\n", incorrect_counter);
            break;

            //if user enter a invalid integer value in menu option so using default for that
        default:
            printf("\nYou have entered an invalid value for the menu option\n");

            break; //break statement for termination this loop

        } //end switch

    } //end do

    //while statement declaring menu is not 4
    while (menu != 4);

    return 0;

} //end main