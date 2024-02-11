#include "ncurses_tools.h"

void init_ncurses()
{
        initscr();
        noecho();
        cbreak();
}

int percentile_to_position(int max, float percent)
{
        float position = ((float)max / 100.00) * percent;

        return (int)round(position);
}

