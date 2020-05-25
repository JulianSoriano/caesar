//include files from these libraries
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Create an array of lower and uppercase alphabets because their ASCII values don't make sense with the formula
char alpharay1[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char alpharay2[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

//main body of code (./caesar 1)
int main(int argc, string argv[])
{
    //variables////////////////////////////////////////

    int key = 0;
    int correctedvalue = 0;

    //Key//////////////////////////////////////////////

    //check if command-line argument is blank
    if (argc == 1)
    {
        printf("Command-line argument is blank\n");
        return 1;
    }

    //Convert command-line argument vector from string to an int called key, using "atoi"
    key = atoi(argv[1]);

    //For loop to scan through the command-line argument vector
    for (int i = 0; i < argv[1][i]; i++)
    {
        //If user inputs a character that isn't a number
        if ((argv[1][i] < '0') || (argv[1][i] > '9'))
        {
            printf("Character is not a number\n");
            return 1;
        }
        //if user inputs a negative number
        else if (key < 1)
        {
            printf("Character is negative\n");
            return 1;
        }
        //if command-line argument counter isn't 2.
        else if (argc != 2)
        {
            printf("Command-line argument counter isn't 2\n");
            return 1;
        }
    }

    //promt user for plaintext/////////////////////////

    string plaintext = get_string("plaintext: ");

    //Encryption///////////////////////////////////////

    //Duplicate plaintext into a new string called ciphertext
    string ciphertext = plaintext;

    //use strlen to find the length of the plaintext input and make it an integer called textlength
    int textlength = strlen(plaintext);

    //For loop to scan through the plaintext
    for (int j = 0; j < textlength; j++)

        //if character value is between (a to z)
        if (plaintext[j] >= 'a' && plaintext[j] <= 'z')
        {
            //scan the lower case alphabet array
            for (int k = 0; k < 26; k++)
            {
                //if the scanned plaintext character matches the letter in alpharay1, assign new value
                if (plaintext[j] == alpharay1[k])
                    //new value is called correctedvalue
                {
                    correctedvalue = k;
                }
            }

            //Encryption formula
            ciphertext[j] = alpharay1[(correctedvalue + key) % 26];
        }

    //if character value is between (A to Z)
        else if (plaintext[j] >= 'A' && plaintext[j] <= 'Z')
        {
            //scan the upper case alphabet array
            for (int l = 0; l < 26; l++)
            {
                //if the scanned plaintext character matches the letter in alpharay2, assign new value
                if (plaintext[j] == alpharay2[l])
                    //new value is called correctedvalue
                {
                    correctedvalue = l;
                }
            }

            //Encryption formula
            ciphertext[j] = alpharay2[(correctedvalue + key) % 26];
        }

    //Print a output///////////////////////////////////
    printf("ciphertext: %s\n", ciphertext);
}
