/* COMMENT:: Number Guess, VERSION:: 0.0.0, DATE:: Mon Dec 14 00:32:01 MSK 2020 */

#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include "num_guess.h"

#include "config.h"

/** Help string */
#define HELPSTR "Program guess your number from %d to %d\n\
\n\
Usage: num_guess [OPTIONS]\n\
\n\
\t--help\t\tprint this help\n\
\t--version\tprint version\n\
\t-r\t\tRoman mode\n\
\n\
"




int main(int argc, char **argv)
{
    

    int lower = 0;
    int upper = 100;

    int roman_flag = 0;

    if (argc > 1 && !strcmp(argv[1], "--help"))
    {
        printf(HELPSTR, lower, upper);
        return 0;
    }
    else if (argc > 1 && !strcmp(argv[1], "--version"))
    {
        printf("%s\n", VERSION);
        return 0;
    }
    else if (argc > 1 && !strcmp(argv[1], "-r"))
    {
        roman_flag = 1;
    }

    int is_guess = 0;

    if (roman_flag)
    {
        printf("Guess a number from %s to %s\n", toRoman(lower), toRoman(upper));
    }
    else
    {
        printf("Guess a number from %d to %d\n", lower, upper);
    }

    do
    {
        if (roman_flag)
        {
            printf("Is your number greater than %s\n", toRoman((upper + lower) / 2));
        }
        else
        {
            printf("Is your number greater than %d?\n", (upper + lower) / 2);
        }

        char answer[100];
        fgets(answer, sizeof(answer), stdin);

        if (strcasecmp(answer, "yes\n") == 0)
        {
            lower = (upper + lower) / 2 + 1;
        }
        else if (strcasecmp(answer, "no\n") == 0)
        {
            upper = (upper + lower) / 2;
        }
    } while (lower < upper);

    if (roman_flag)
    {
        printf("Your number is %s\n", toRoman(lower));
    }
    else
    {
        printf("Your number is %d\n", lower);
    }

    return 0;
}