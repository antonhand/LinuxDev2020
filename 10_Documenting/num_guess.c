/**
 * @file num_guess.c
 * @author Anton Khandzhyan
 * @brief Program guess your number
 * @version 0.0.0
 * @date 2020-11-23
 * 
 * Usage: num_guess [OPTIONS]
 * - -\-help -- print this help
 * - -\-version -- print version
 * - -r -- Roman mode
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#include "config.h"

/** gettext() wrapper */
#define _(STRING) gettext(STRING)

/** Path to locale folder */
#define LOCALE_PATH "."

/** Help string */
#define HELPSTR _("Program guess your number from %d to %d\n\
\n\
Usage: num_guess [OPTIONS]\n\
\n\
\t--help\t\tprint this help\n\
\t--version\tprint version\n\
\t-r\t\tRoman mode\n\
\n\
")

/** Roman number table */
static char *romans[] = {"N", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII",
                         "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI", "XXII", "XXIII", "XXIV", "XXV",
                         "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI",
                         "XXXVII", "XXXVIII", "XXXIX", "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII",
                         "XLIX", "L", "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", "LXI", "LXII", "LXIII",
                         "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI",
                         "LXXVII", "LXXVIII", "LXXIX", "LXXX", "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII",
                         "LXXXIX", "XC", "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"};

/**
 * @brief Converts the number @p num from Arabic to Roman notation
 * 
 * @param num Number in Arabic notation
 * @return Number in Roman notation
 */
char *toRoman(int num)
{
    return romans[num];
}

/**
 * @brief Converts the number @p num from Roman to Arabic notation
 * 
 * @param num Number in Roman notation
 * @return Number in Arabic notation
 */
int fromRomans(char *num)
{
    for (int i = 0; i < sizeof(romans) / sizeof(romans[0]); i++)
    {
        if (!strcasecmp(romans[i], num))
        {
            return i;
        }
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    bindtextdomain("num_guess", LOCALE_PATH);
    textdomain("num_guess");

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
        printf(_("Guess a number from %s to %s\n"), toRoman(lower), toRoman(upper));
    }
    else
    {
        printf(_("Guess a number from %d to %d\n"), lower, upper);
    }

    do
    {
        if (roman_flag)
        {
            printf(_("Is your number greater than %s\n"), toRoman((upper + lower) / 2));
        }
        else
        {
            printf(_("Is your number greater than %d?\n"), (upper + lower) / 2);
        }

        char answer[100];
        fgets(answer, sizeof(answer), stdin);

        if (strcasecmp(answer, _("yes\n")) == 0)
        {
            lower = (upper + lower) / 2 + 1;
        }
        else if (strcasecmp(answer, _("no\n")) == 0)
        {
            upper = (upper + lower) / 2;
        }
    } while (lower < upper);

    if (roman_flag)
    {
        printf(_("Your number is %s\n"), toRoman(lower));
    }
    else
    {
        printf(_("Your number is %d\n"), lower);
    }

    return 0;
}