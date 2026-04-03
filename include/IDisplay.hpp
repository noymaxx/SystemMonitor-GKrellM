/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** IDisplay interface
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <vector>
#include "IModule.hpp"

namespace Krell {

/**
 * @brief Interface for all display backends (NCurses, SFML, etc.)
 */
class IDisplay {
public:
    virtual ~IDisplay() = default;

    /**
     * @brief Init the display
     * @return true on success, false on failure
     */
    virtual bool init() = 0;

    /**
     * @brief Close and cleanup the display
     */
    virtual void close() = 0;

    /**
     * @brief Clear the display buffer
     */
    virtual void clear() = 0;

    /**
     * @brief Render all modules to the display
     * @param modules List of active modules to render
     */
    virtual void render(const std::vector<IModule *> &modules) = 0;

    /**
     * @brief Poll and handle input events
     * @return 0=quit, 1-9=toggle module, 10=up, 11=down, 12=left, 13=right, -1=none
     */
    virtual int pollEvents() = 0;
};

}

#endif /* !IDISPLAY_HPP_ */
