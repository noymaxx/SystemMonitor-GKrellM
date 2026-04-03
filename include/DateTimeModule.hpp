/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** DateTimeModule - Displays current date and time
*/

#ifndef DATETIMEMODULE_HPP_
#define DATETIMEMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module displaying current date and time
 */
class DateTimeModule : public AModule {
public:
    /**
     * @brief Construct datetime module
     */
    DateTimeModule();

    ~DateTimeModule();

    /**
     * @brief Get module name
     * @return "DateTime"
     */
    std::string getName() const;

    /**
     * @brief Upd date and time from system clock
     */
    void update();

    /**
     * @brief Get date and time data
     * @return Vector with date and time entries
     */
    std::vector<ModuleData> getData() const;

    /**
     * @brief Get display height
     * @return Number of lines needed
     */
    int getHeight() const;

private:
    std::string data;   ///< Current date string
    std::string hora;   ///< Current time string
};

}

#endif /* !DATETIMEMODULE_HPP_ */
