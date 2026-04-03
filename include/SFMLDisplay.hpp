/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** SFMLDisplay class
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include "ADisplay.hpp"

namespace Krell {

// Window
static const int FPS_LIMIT = 60;

// Layout ratios (percentage of window height)
static const float MARGIN_RATIO = 0.015f;
static const float CONTENT_INDENT_RATIO = 0.025f;
static const float HEADER_SPACING_RATIO = 0.05f;
static const float MODULE_SPACING_RATIO = 0.02f;
static const float LINE_HEIGHT_RATIO = 0.028f;
static const float BAR_SPACING_RATIO = 0.035f;

// Size ratios
static const float HEADER_SIZE_RATIO = 0.035f;
static const float TITLE_SIZE_RATIO = 0.028f;
static const float TEXT_SIZE_RATIO = 0.022f;
static const float BAR_WIDTH_RATIO = 0.6f;
static const float BAR_HEIGHT_RATIO = 0.025f;

// Colors
static const sf::Color BG_COLOR(30, 30, 30);
static const sf::Color BAR_BG_COLOR(60, 60, 60);
static const sf::Color HEADER_COLOR = sf::Color::Green;
static const sf::Color TITLE_COLOR = sf::Color::Cyan;
static const sf::Color TEXT_COLOR = sf::Color::White;
static const sf::Color BAR_LOW = sf::Color::Green;
static const sf::Color BAR_MID = sf::Color::Yellow;
static const sf::Color BAR_HIGH = sf::Color::Red;

// Thresholds
static const float THRESHOLD_HIGH = 80.0f;
static const float THRESHOLD_MID = 50.0f;

// Event codes
static const int EVENT_QUIT = 0;
static const int EVENT_NONE = -1;
static const int EVENT_SELECT_PREV = 10;
static const int EVENT_SELECT_NEXT = 11;
static const int EVENT_MOVE_UP = 12;
static const int EVENT_MOVE_DOWN = 13;

// Min sizes
static const int MIN_FONT_SIZE = 12;

// Font paths
static const std::vector<std::string> FONT_PATHS = {
    "/usr/share/fonts/liberation-mono-fonts/LiberationMono-Regular.ttf",
    "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf",
    "/usr/share/fonts/TTF/DejaVuSansMono.ttf",
    "/usr/share/fonts/dejavu-sans-mono-fonts/DejaVuSansMono.ttf"
};

// Keys
static const std::map<sf::Keyboard::Key, int> KEY_BINDINGS = {
    {sf::Keyboard::Q, EVENT_QUIT},
    {sf::Keyboard::Escape, EVENT_QUIT},
    {sf::Keyboard::Up, EVENT_SELECT_PREV},
    {sf::Keyboard::Down, EVENT_SELECT_NEXT},
    {sf::Keyboard::Left, EVENT_MOVE_UP},
    {sf::Keyboard::Right, EVENT_MOVE_DOWN},
    {sf::Keyboard::Num1, 1}, {sf::Keyboard::Num2, 2}, {sf::Keyboard::Num3, 3},
    {sf::Keyboard::Num4, 4}, {sf::Keyboard::Num5, 5}, {sf::Keyboard::Num6, 6},
    {sf::Keyboard::Num7, 7}, {sf::Keyboard::Num8, 8}, {sf::Keyboard::Num9, 9}
};

/**
 * @brief Graphical display using SFML with dynamic scaling
 */
class SFMLDisplay : public ADisplay {
public:
    SFMLDisplay();
    ~SFMLDisplay() override;

    /**
     * @brief Init SFML window at desktop resolution
     * @return true on success, false if font loading fails
     */
    bool init() override;

    /**
     * @brief Close SFML window
     */
    void close() override;

    /**
     * @brief Clear the window with background color
     */
    void clear() override;

    /**
     * @brief Render all modules to window with dynamic scaling
     * @param modules List of modules to display
     */
    void render(const std::vector<IModule *> &modules) override;

    /**
     * @brief Handle window events and keyboard input
     * @return 0=quit, 1-9=toggle module, 10=up, 11=down, 12=left, 13=right, -1=none
     */
    int pollEvents() override;

private:
    sf::RenderWindow _window;
    sf::Font _font;

    /**
     * @brief Draw a single module with scaled elements
     */
    void drawModule(const IModule *module, float &y, float viewHeight, float viewWidth);

    /**
     * @brief Draw a colored progress bar
     */
    void drawProgressBar(float x, float y, float width, float height, float percentage);
};

}

#endif /* !SFMLDISPLAY_HPP_ */
