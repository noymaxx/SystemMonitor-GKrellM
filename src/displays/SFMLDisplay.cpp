/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** SFMLDisplay
*/

#include "SFMLDisplay.hpp"

namespace Krell {

SFMLDisplay::SFMLDisplay()
    : ADisplay()
{
}

SFMLDisplay::~SFMLDisplay()
{
    if (_initialized)
        close();
}

bool SFMLDisplay::init()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    _window.create(desktop, "MyGKrellm", sf::Style::Default);
    _window.setFramerateLimit(FPS_LIMIT);
    for (const auto &path : FONT_PATHS) {
        if (_font.loadFromFile(path)) {
            _initialized = true;
            return true;
        }
    }
    return false;
}

void SFMLDisplay::close()
{
    if (_initialized) {
        _window.close();
        _initialized = false;
    }
}

void SFMLDisplay::clear()
{
    _window.clear(BG_COLOR);
}

void SFMLDisplay::drawProgressBar(float x, float y, float width, float height, float percentage)
{
    sf::RectangleShape bg(sf::Vector2f(width, height));
    float fillWidth = (percentage / 100.0f) * width;
    sf::RectangleShape fill(sf::Vector2f(fillWidth, height));
    sf::Color fillColor = BAR_LOW;

    if (percentage > THRESHOLD_HIGH)
        fillColor = BAR_HIGH;
    else if (percentage > THRESHOLD_MID)
        fillColor = BAR_MID;
    bg.setPosition(x, y);
    bg.setFillColor(BAR_BG_COLOR);
    fill.setPosition(x, y);
    fill.setFillColor(fillColor);
    _window.draw(bg);
    _window.draw(fill);
}

void SFMLDisplay::drawModule(const IModule *module, float &y,
    float viewHeight, float viewWidth)
{
    std::vector<ModuleData> data = module->getData();
    float margin = viewHeight * MARGIN_RATIO;
    float indent = viewHeight * CONTENT_INDENT_RATIO;
    float lineHeight = viewHeight * LINE_HEIGHT_RATIO;
    float barSpacing = viewHeight * BAR_SPACING_RATIO;
    float moduleSpacing = viewHeight * MODULE_SPACING_RATIO;
    float barWidth = viewWidth * BAR_WIDTH_RATIO;
    float barHeight = viewHeight * BAR_HEIGHT_RATIO;
    int titleSize = std::max(static_cast<int>(viewHeight * TITLE_SIZE_RATIO),
        MIN_FONT_SIZE);
    int textSize = std::max(static_cast<int>(viewHeight * TEXT_SIZE_RATIO),
        MIN_FONT_SIZE);
    sf::Text title(module->getName(), _font, titleSize);
    sf::Text line("", _font, textSize);

    title.setPosition(margin, y);
    title.setFillColor(TITLE_COLOR);
    _window.draw(title);
    y += titleSize + lineHeight * 0.3f;
    for (const auto &d : data) {
        line.setString(d.label + ": " + d.value);
        line.setPosition(indent, y);
        line.setFillColor(TEXT_COLOR);
        _window.draw(line);
        y += lineHeight;
        if (d.percentage >= 0) {
            drawProgressBar(indent, y, barWidth, barHeight, d.percentage);
            y += barSpacing;
        }
    }
    y += moduleSpacing;
}

void SFMLDisplay::render(const std::vector<IModule *> &modules)
{
    sf::Vector2f viewSize = _window.getView().getSize();
    float viewHeight = viewSize.y;
    float viewWidth = viewSize.x;
    float margin = viewHeight * MARGIN_RATIO;
    float headerSpacing = viewHeight * HEADER_SPACING_RATIO;
    int headerSize = std::max(static_cast<int>(viewHeight * HEADER_SIZE_RATIO),
        MIN_FONT_SIZE);
    float y = margin;
    sf::Text header("MyGKrellm - System Monitor", _font, headerSize);

    header.setPosition(margin, y);
    header.setFillColor(HEADER_COLOR);
    header.setStyle(sf::Text::Bold);
    _window.draw(header);
    y += headerSpacing;
    for (const auto &module : modules)
        drawModule(module, y, viewHeight, viewWidth);
    _window.display();
}

int SFMLDisplay::pollEvents()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return EVENT_QUIT;
        if (event.type == sf::Event::Resized) {
            sf::FloatRect view(0, 0, event.size.width, event.size.height);
            _window.setView(sf::View(view));
        }
        if (event.type == sf::Event::KeyPressed) {
            auto it = KEY_BINDINGS.find(event.key.code);
            if (it != KEY_BINDINGS.end())
                return it->second;
        }
    }
    return EVENT_NONE;
}

}
