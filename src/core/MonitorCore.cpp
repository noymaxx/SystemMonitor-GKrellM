/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** MonitorCore implementation
*/

#include <algorithm>
#include "MonitorCore.hpp"

namespace Krell {

MonitorCore::MonitorCore()
    : _display(nullptr), _running(true), _selectedIndex(0)
{
}

MonitorCore::~MonitorCore()
{
}

void MonitorCore::addModule(std::unique_ptr<IModule> module)
{
    if (module != nullptr)
        _modules.push_back(std::move(module));
}

void MonitorCore::toggleModule(std::size_t index)
{
    if (index < _modules.size())
        _modules[index]->setEnabled(!_modules[index]->isEnabled());
}

std::vector<IModule*> MonitorCore::getActiveModules() const
{
    std::vector<IModule*> active;

    for (std::size_t i = 0; i < _modules.size(); i++) {
        if (_modules[i]->isEnabled())
            active.push_back(_modules[i].get());
    }
    return active;
}

void MonitorCore::setDisplay(std::unique_ptr<IDisplay> display)
{
    _display = std::move(display);
}

void MonitorCore::selectNext()
{
    if (_modules.size() > 0 && _selectedIndex < _modules.size() - 1)
        _selectedIndex++;
}

void MonitorCore::selectPrevious()
{
    if (_selectedIndex > 0)
        _selectedIndex--;
}

void MonitorCore::moveSelectedUp()
{
    if (_selectedIndex > 0) {
        std::swap(_modules[_selectedIndex], _modules[_selectedIndex - 1]);
        _selectedIndex--;
    }
}

void MonitorCore::moveSelectedDown()
{
    if (_modules.size() > 0 && _selectedIndex < _modules.size() - 1) {
        std::swap(_modules[_selectedIndex], _modules[_selectedIndex + 1]);
        _selectedIndex++;
    }
}

std::size_t MonitorCore::getSelectedIndex() const
{
    return _selectedIndex;
}

void MonitorCore::handleEvent(int key)
{
    std::map<int, std::function<void()>> actions = {
        {CORE_EVENT_SELECT_PREV, [this]() { selectPrevious(); }},
        {CORE_EVENT_SELECT_NEXT, [this]() { selectNext(); }},
        {CORE_EVENT_MOVE_UP, [this]() { moveSelectedUp(); }},
        {CORE_EVENT_MOVE_DOWN, [this]() { moveSelectedDown(); }}
    };
    auto it = actions.find(key);

    if (key == CORE_EVENT_QUIT) {
        _running = false;
        return;
    }
    if (key >= 1 && key <= 9) {
        toggleModule(key - 1);
        return;
    }
    if (it != actions.end())
        it->second();
}

void MonitorCore::run()
{
    std::vector<IModule*> active;
    int key = 0;

    if (_display == nullptr)
        return;
    if (!_display->init())
        return;
    while (_running) {
        active = getActiveModules();
        for (std::size_t i = 0; i < active.size(); i++)
            active[i]->update();
        _display->clear();
        _display->render(active);
        key = _display->pollEvents();
        handleEvent(key);
    }
    _display->close();
}

}
