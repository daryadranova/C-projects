#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

bool valid_argument(int a, int b, int c);

int main(void)
{
    int a = get_int("Give some number A:");
    int b = get_int("Give some number:");
    int c = get_int("Give some number:");

    bool validity = valid_argument(a,b,c);

}

bool valid_argument(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if (a+b<=c || a+c<=b || c+b<=c)
    {
        printf("the triangle is valid");
        return false;
    }
        return true;
}