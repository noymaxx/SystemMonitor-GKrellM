/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** RAMModule - Displays memory usage
*/

#ifndef RAMMODULE_HPP_
#define RAMMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module displaying RAM usage from /proc/meminfo
 */
class RAMModule : public AModule {
public:
    /**
     * @brief Construct and initialize RAM module
     */
    RAMModule();

    ~RAMModule();

    /**
     * @brief Get module name
     * @return "RAM"
     */
    std::string getName() const;

    /**
     * @brief Upd memory info from /proc/meminfo
     */
    void update();

    /**
     * @brief Get memory usage data with progress bar
     * @return Vector with total, used, available and usage percentage
     */
    std::vector<ModuleData> getData() const;

    /**
     * @brief Get display height
     * @return Number of lines needed
     */
    int getHeight() const;

private:
    long total;         ///< Total RAM in KB
    long available;     ///< Available RAM in KB
    long used;          ///< Used RAM in KB
    float usage;        ///< Usage percentage (0-100)
};

}

#endif /* !RAMMODULE_HPP_ */
