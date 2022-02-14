#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
//is it a letter?
{
    string text = get_string("Type some English text: ");
    printf("%s\n", text);

    int letters = 0;
    int spaces = 0;
    int endings = 0;

    for (int i = 0, n = strlen(text); i < n; i++) //для каждого символа из введенного текста
    {
        if (islower(text[i]) || isupper(text[i])) //этот символ — буква?
        {
            letters = letters + 1;              
        }
        if (isspace(text[i])) // если это не буква, это пробел? 
        {
            spaces = spaces + 1;
        }
        if ((text[i] == '!') || (text[i] == '?') || (text[i] == '.')) //это окончание предложения? 
        {
            endings = endings + 1;
        }
    }

    int words = spaces + 1;
    
    //количество слов, букв, предложений
    printf("Number of letters: %i\n", letters);
    printf("Number of words: %i\n", words);
    printf("Number of sentences: %i\n", endings); 

    //подставляем в формулу 

    float L = round((100 * letters) / words); //среднее количество букв на 100 слов
    float S = round((100 * endings) / words); //среднее кол-во предложений на 100 слов
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index >= 1 && index <= 16) //если от 1 до 16 
    {
        printf("Grade is %i\n", index);
    }
    if(index < 1) //если меньше 1
    {
        printf("Grade is less then 1\n");
    }
    if(index > 16) //если больше 16
    {
        printf("Grade is more then 16\n");
    }
}