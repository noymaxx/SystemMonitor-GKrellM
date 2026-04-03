/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** MonitorCore - Main orchestrator
*/

#ifndef MONITORCORE_HPP_
#define MONITORCORE_HPP_

#include <vector>
#include <map>
#include <functional>
#include <memory>
#include "IModule.hpp"
#include "IDisplay.hpp"

namespace Krell {

// Event codes
static const int CORE_EVENT_QUIT = 0;
static const int CORE_EVENT_SELECT_PREV = 10;
static const int CORE_EVENT_SELECT_NEXT = 11;
static const int CORE_EVENT_MOVE_UP = 12;
static const int CORE_EVENT_MOVE_DOWN = 13;

/**
 * @brief Main orchestrator for the system monitor
 * Manages modules, display, and the main loop
 */
class MonitorCore {
public:
    /**
     * @brief Construct the monitor core
     */
    MonitorCore();

    /**
     * @brief Destructor
     */
    ~MonitorCore();

    /**
     * @brief Add a module to the monitor
     * @param module Module to add (takes ownership)
     */
    void addModule(std::unique_ptr<IModule> module);

    /**
     * @brief Toggle module enabled state
     * @param index Module index (0-based)
     */
    void toggleModule(std::size_t index);

    /**
     * @brief Get list of enabled modules
     * @return Vector of active module pointers
     */
    std::vector<IModule*> getActiveModules() const;

    /**
     * @brief Set the display backend
     * @param display Display to use (takes ownership)
     */
    void setDisplay(std::unique_ptr<IDisplay> display);

    /**
     * @brief Select next module in list
     */
    void selectNext();

    /**
     * @brief Select previous module in list
     */
    void selectPrevious();

    /**
     * @brief Move selected module up in list
     */
    void moveSelectedUp();

    /**
     * @brief Move selected module down in list
     */
    void moveSelectedDown();

    /**
     * @brief Get currently selected module index
     * @return Selected index
     */
    std::size_t getSelectedIndex() const;

    /**
     * @brief Run the main monitor loop
     */
    void run();

    /**
     * @brief Handle a single event from display
     * @param key Event code
     */
    void handleEvent(int key);

private:
    std::vector<std::unique_ptr<IModule>> _modules;  ///< List of all modules
    std::unique_ptr<IDisplay> _display;              ///< Current display backend
    bool _running;                                   ///< Main loop running state
    std::size_t _selectedIndex;                      ///< Current selected module
};

}

#endif /* !MONITORCORE_HPP_ */
