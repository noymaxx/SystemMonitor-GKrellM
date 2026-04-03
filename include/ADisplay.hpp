/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** ADisplay abstract class
*/

#ifndef ADISPLAY_HPP_
#define ADISPLAY_HPP_

#include "IDisplay.hpp"

namespace Krell {

/**
 * @brief Abstract base class for all displays
 */
class ADisplay : public IDisplay {
public:
    /**
     * @brief Construct display in uninit state
     */
    ADisplay();

    virtual ~ADisplay();

    /**
     * @brief Init the display
     * @return true on success, false on failure
     */
    bool init() override = 0;

    /**
     * @brief Close and cleanup the display
     */
    void close() override = 0;

    /**
     * @brief Clear the display buffer
     */
    void clear() override = 0;

    /**
     * @brief Render all modules to the display
     * @param modules List of active modules to render
     */
    void render(const std::vector<IModule *> &modules) override = 0;

    /**
     * @brief Poll and handle input events
     * @return 0=quit, 1-9=toggle module, 10=up, 11=down, 12=left, 13=right, -1=none
     */
    int pollEvents() override = 0;

protected:
    bool _initialized;  ///< Display initialization state
};

}

#endif /* !ADISPLAY_HPP_ */
