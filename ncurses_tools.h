#ifndef NCURSES_TOOLS_H
#define NCURSES_TOOLS_H

#include <vector>
#include <cmath>
#include <cstring>
#include <ncurses.h>

using std::round;
using std::strlen;

void init_ncurses();

int percentile_to_position(int max, float percent);


#endif
