#include <iostream>
#include <array>
#include <ncurses.h>
#include "ncurses_tools.h"

using std::vector;
using std::array;

constexpr size_t CHOICE_COUNT = 7;
constexpr size_t ENTRY_CAP = 100;

array <const char *, CHOICE_COUNT> choices  =
{
        "Character Name:",
        "Level:",
        "Class:",
        "Race:",
        "Background:",
        "Alignment:",
        "Experience Points:",
};

typedef struct Character
{
        char name[ENTRY_CAP];
        unsigned short lvl;
        char cls[ENTRY_CAP];
        char race[ENTRY_CAP];
        char background[ENTRY_CAP];
        char alignment[ENTRY_CAP];
        unsigned int xp;
} Character;

array <WINDOW *, CHOICE_COUNT> menu;
array <WINDOW *, CHOICE_COUNT> inputMenu;

size_t longest_string(array <const char *, CHOICE_COUNT> strArr);
void draw_menu(const int entryH, const int entryW);
void highlight_selection(int sel);

int main (int argc, char *argv[])
{
        const size_t LONGEST_ENTRY = longest_string(choices);
        const int ENTRY_WIDTH = (int)LONGEST_ENTRY + 2;
        const int ENTRY_HEIGHT = 3;

        int key;
        int selection = 0;

        Character newChar;

        init_ncurses();
        refresh();
        draw_menu(ENTRY_HEIGHT, ENTRY_WIDTH);

        highlight_selection(selection);

        do
        {
                key = getch();

                switch(key)
                {
                        case 'j':
                                if (selection < ((int)CHOICE_COUNT - 1))
                                {
                                        mvwprintw(menu[selection], 1, 1, choices[selection]);
                                        wrefresh(menu[selection]);
                                        highlight_selection(++selection); 
                                }
                                break;

                        case 'k':
                                if (selection > 0)
                                {
                                        mvwprintw(menu[selection], 1, 1, choices[selection]);
                                        wrefresh(menu[selection]);
                                        highlight_selection(--selection); 
                                }
                                break; 
                                
                                // Enter
                        case 10: 
                                echo();
                                switch(selection)
                                {
                                        case 0:
                                                mvwscanw(inputMenu[0], 1, 1, "%s", newChar.name);
                                                break;
                                        case 1:
                                                mvwscanw(inputMenu[1], 1, 1, "%hu", &newChar.lvl);
                                                break;
                                        case 2:
                                                mvwscanw(inputMenu[2], 1, 1, "%s", newChar.cls);
                                                break;
                                        case 3:
                                                mvwscanw(inputMenu[3], 1, 1, "%s", newChar.race);
                                                break;
                                        case 4:
                                                mvwscanw(inputMenu[4], 1, 1, "%s", newChar.background);
                                                break;
                                        case 5:
                                                mvwscanw(inputMenu[5], 1, 1, "%s", newChar.alignment);
                                                break;
                                        case 6:
                                                mvwscanw(inputMenu[6], 1, 1, "%u", &newChar.xp);
                                                break;
                                }
                                noecho();
                }
        } while ((key != 'q') && (key != 'Q'));

        getch();
        endwin();
}

size_t longest_string(array <const char *, CHOICE_COUNT> strArr)
{
        size_t longestStr = 0;

        for (size_t i = 0; i < strArr.size(); ++i) 
        {
                if (strlen(strArr[i]) > longestStr)
                        longestStr = strlen(strArr[i]);
        }

        return longestStr;
}

void draw_menu(const int entryH, const int entryW)
{
        int startX, startY;
        int i;

        // menu options
        startX = 0;
        for (i = 0; i < (int)CHOICE_COUNT; ++i) 
        {
                startY = i * entryH;
                menu[i] = newwin(entryH, entryW, startY, startX);
        }

        // input menu
        startX = entryW;
        for (i = 0; i < (int)CHOICE_COUNT; ++i)
        {
                startY = i * entryH;
                inputMenu[i] = newwin(entryH, entryW, startY, startX);
        }

        for (i = 0; i < (int)CHOICE_COUNT; ++i)
        {
                mvwprintw(menu[i], 1, 1, choices[i]);
                box(inputMenu[i], 0, 0); 
                wrefresh(menu[i]);
                wrefresh(inputMenu[i]);
        }
}

void highlight_selection(int sel)
{
        wattron(menu[sel], A_REVERSE);
        mvwprintw(menu[sel], 1, 1, choices[sel]);
        wrefresh(menu[sel]);
        wattroff(menu[sel], A_REVERSE);
}
