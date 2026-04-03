/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** NCursesDisplay
*/

#include "NCursesDisplay.hpp"

namespace Krell {

NCursesDisplay::NCursesDisplay()
    : ADisplay()
{
}

NCursesDisplay::~NCursesDisplay()
{
    if (_initialized)
        close();
}

bool NCursesDisplay::init()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(INPUT_TIMEOUT_MS);
    curs_set(0);
    if (has_colors()) {
        start_color();
        init_pair(COLOR_HEADER, COLOR_GREEN, COLOR_BLACK);
        init_pair(COLOR_TITLE, COLOR_CYAN, COLOR_BLACK);
        init_pair(COLOR_BAR_MID, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BAR_HIGH, COLOR_RED, COLOR_BLACK);
    }
    _initialized = true;
    return true;
}

void NCursesDisplay::close()
{
    if (_initialized) {
        endwin();
        _initialized = false;
    }
}

void NCursesDisplay::clear()
{
    ::clear();
}

void NCursesDisplay::drawProgressBar(int y, int x, int width, float percentage)
{
    int innerWidth = width - 2;
    int filled = static_cast<int>((percentage / 100.0f) * innerWidth);
    int colorPair = COLOR_BAR_LOW;

    if (filled < 0)
        filled = 0;
    if (filled > innerWidth)
        filled = innerWidth;
    if (percentage > NC_THRESHOLD_HIGH)
        colorPair = COLOR_BAR_HIGH;
    else if (percentage > NC_THRESHOLD_MID)
        colorPair = COLOR_BAR_MID;
    mvaddch(y, x, '[');
    attron(COLOR_PAIR(colorPair));
    for (int i = 0; i < filled; i++)
        mvaddch(y, x + 1 + i, '|');
    attroff(COLOR_PAIR(colorPair));
    for (int i = filled; i < innerWidth; i++)
        mvaddch(y, x + 1 + i, ' ');
    mvaddch(y, x + width - 1, ']');
}

void NCursesDisplay::drawModule(const IModule *module, int &y)
{
    std::vector<ModuleData> data = module->getData();
    int barWidth = COLS - BAR_PADDING;
    int line = y;

    attron(COLOR_PAIR(COLOR_TITLE) | A_BOLD);
    mvprintw(line, MARGIN_X, "[ %s ]", module->getName().c_str());
    attroff(COLOR_PAIR(COLOR_TITLE) | A_BOLD);
    line++;
    for (const auto &d : data) {
        mvprintw(line, CONTENT_INDENT, "%-*s: %s",
            LABEL_WIDTH, d.label.c_str(), d.value.c_str());
        line++;
        if (d.percentage >= 0) {
            drawProgressBar(line, CONTENT_INDENT, barWidth, d.percentage);
            line++;
        }
    }
    y = line + MODULE_SPACING;
}

void NCursesDisplay::render(const std::vector<IModule *> &modules)
{
    int y = MARGIN_Y;
    int helpX = COLS - 20;

    attron(COLOR_PAIR(COLOR_HEADER) | A_BOLD);
    mvprintw(0, MARGIN_X, "MyGKrellm - System Monitor");
    attroff(COLOR_PAIR(COLOR_HEADER) | A_BOLD);
    mvprintw(0, helpX, "Press 'q' to quit");
    for (const auto &module : modules) {
        if (y + module->getHeight() + MODULE_SPACING > LINES)
            break;
        drawModule(module, y);
    }
    refresh();
}

int NCursesDisplay::pollEvents()
{
    int ch = getch();
    auto it = NC_KEY_BINDINGS.find(ch);

    if (it != NC_KEY_BINDINGS.end())
        return it->second;
    return NC_EVENT_NONE;
}

}
