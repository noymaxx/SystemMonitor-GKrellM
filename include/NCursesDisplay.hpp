/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** NCursesDisplay class
*/

#ifndef NCURSESDISPLAY_HPP_
#define NCURSESDISPLAY_HPP_

#include <ncurses.h>
#include <map>
#include "ADisplay.hpp"

namespace Krell {

// Timing
static const int INPUT_TIMEOUT_MS = 100;

// Layout
static const int MARGIN_X = 2;
static const int MARGIN_Y = 1;
static const int CONTENT_INDENT = 4;
static const int LABEL_WIDTH = 15;
static const int BAR_PADDING = 8;
static const int MODULE_SPACING = 1;

// Color pairs
static const int COLOR_HEADER = 1;
static const int COLOR_TITLE = 2;
static const int COLOR_BAR_LOW = 1;
static const int COLOR_BAR_MID = 3;
static const int COLOR_BAR_HIGH = 4;

// Thresholds
static const float NC_THRESHOLD_HIGH = 80.0f;
static const float NC_THRESHOLD_MID = 50.0f;

// Event codes
static const int NC_EVENT_QUIT = 0;
static const int NC_EVENT_NONE = -1;
static const int NC_EVENT_SELECT_PREV = 10;
static const int NC_EVENT_SELECT_NEXT = 11;
static const int NC_EVENT_MOVE_UP = 12;
static const int NC_EVENT_MOVE_DOWN = 13;

// Key bindings
static const std::map<int, int> NC_KEY_BINDINGS = {
    {'q', NC_EVENT_QUIT}, {'Q', NC_EVENT_QUIT}, {27, NC_EVENT_QUIT},
    {KEY_UP, NC_EVENT_SELECT_PREV}, {KEY_DOWN, NC_EVENT_SELECT_NEXT},
    {KEY_LEFT, NC_EVENT_MOVE_UP}, {KEY_RIGHT, NC_EVENT_MOVE_DOWN},
    {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}
};

/**
 * @brief Terminal display using NCurses
 */
class NCursesDisplay : public ADisplay {
public:
    NCursesDisplay();
    ~NCursesDisplay() override;

    /**
     * @brief Init ncurses mode with colors
     * @return true on success
     */
    bool init() override;

    /**
     * @brief Close ncurses mode
     */
    void close() override;

    /**
     * @brief Clear the terminal screen
     */
    void clear() override;

    /**
     * @brief Render all modules to terminal
     * @param modules List of modules to display
     */
    void render(const std::vector<IModule *> &modules) override;

    /**
     * @brief Handle keyboard input
     * @return 0=quit, 1-9=toggle module, 10=up, 11=down, 12=left, 13=right, -1=none
     */
    int pollEvents() override;

private:
    /**
     * @brief Draw a single module with title and data
     */
    void drawModule(const IModule *module, int &y);

    /**
     * @brief Draw a colored progress bar
     */
    void drawProgressBar(int y, int x, int width, float percentage);
};

}

#endif /* !NCURSESDISPLAY_HPP_ */
