#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."

int main(){
    setlocale (LC_ALL, "");
#ifdef LOCALEDIR
	bindtextdomain ("num_guess", LOCALEDIR);
#else
    bindtextdomain ("num_guess", LOCALE_PATH);
#endif
	textdomain ("num_guess");

    int lower = 0;
    int upper = 100;

    int is_guess = 0;

    printf(_("Guess a number from %d to %d\n"), lower, upper);

    do {
        printf(_("Is your number greater than %d?\n"), (upper + lower) / 2);
        char answer[100];
        fgets(answer, sizeof(answer), stdin);

        if(strcasecmp(answer, _("yes\n")) == 0){
            lower = (upper + lower) / 2 + 1;
        } else if (strcasecmp(answer, _("no\n")) == 0){
            upper = (upper + lower) / 2;
        } 
    } while(lower < upper);
    printf(_("Your number is %d\n"), lower);

    return 0;
}