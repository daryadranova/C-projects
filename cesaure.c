#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string encryption(string plaintext, int key);

int main(int argc, string argv[])
{
    //getting the key from the command-line

    //fitting the condition of the command-line argument
    int key = atoi(argv[1]);
    if (argc != 2 || key <= 0) 
    {
        printf("Error. There should to one command-line argument, positive integer\n");
        return 1;
    }
    
    //getting plain text from the user 
    string text = get_string("Type some English text: ");
    printf("%s\n", text);
    
    //making text encrypted
    string encryptedtext = encryption(text, key);

    //showing the the encrypted text 
    printf("the encrypted text: %s\n", encryptedtext);

    return 0;
}
    
string encryption(string plaintext, int key)
{
    string encrypted;
        
    for (int i = 0, n = strlen(plaintext); i < n; i++) //для каждого символа в строке
    {
        if(isalpha(plaintext[i])) //этот символ - буква алфавита?
        {
                if (islower(plaintext[i])) //этот символ — маленькая буква?
                {
                    //если это буква, то какой у нее номер? в ASCII, а потом в алфавите
                    int number = plaintext[i] - 97;
                    //какой получится буква после шифра?
                    encrypted[i] = (number + key) % 26 + 97;
                }
            if (isupper(plaintext[i])) //is it upper case letter? 
            {
                //если это буква, то какой у нее номер? в ASCII, а потом в алфавите
                int number = plaintext[i] - 65;
                //какой получится буква после шифра?
                    encrypted[i] = (number + key) % 26 + 65;
            }
        }
        if(ispunct(plaintext[i]) || plaintext[i] == ' ') //этот символ - знак препинания или пробел?
        {
            encrypted[i] = plaintext[i];
        }  
    }
    return encrypted;
}