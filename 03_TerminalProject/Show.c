#include <ncurses.h>
#include <locale.h>
#include <string.h>

#define DX 3

void from_f_to_term(FILE *f, WINDOW *win, int width) {
    char str[width];
    if (fgets(str, width, f)){
        if(str[strlen(str) - 1] == '\n')
            wprintw(win, " %s", str);
        else
            wprintw(win, " %s\n", str);
        
    }
}

void main(int argc, char** argv) {
    WINDOW *win;
    int c = 0;

    char* filename = argv[1];
    
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    printw("File: %s", filename);
    refresh();

    int height = LINES-2*DX;
    int width = COLS-2*DX;

    win = newwin(height, width, DX, DX);

    height -= 2;
    width -= 2;

    keypad(win, TRUE);
    scrollok (win, TRUE);

    FILE *f = fopen(filename, "r");

    wprintw(win, "\n");
    for (int i = 0; i < height; i++)
        from_f_to_term(f, win, width);
    box(win, 0, 0);
    wrefresh(win);
    
    while((c = wgetch(win)) != 27){
        if (c == ' '){
            from_f_to_term(f, win, width);
            box(win, 0, 0);
            wrefresh(win);
        }
    } 

    endwin();

}
