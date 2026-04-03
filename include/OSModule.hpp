/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** OSModule - Displays OS and kernel information
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module displaying OS name and kernel version
 */
class OSModule : public AModule {
public:
    /**
     * @brief Construct and initialize OS module
     */
    OSModule();

    ~OSModule();

    /**
     * @brief Get module name
     * @return "System"
     */
    std::string getName() const;

    /**
     * @brief Upd OS info from /etc/os-release and uname
     */
    void update();

    /**
     * @brief Get OS and kernel data
     * @return Vector with OS name and kernel version
     */
    std::vector<ModuleData> getData() const;

    /**
     * @brief Get display height
     * @return Number of lines needed
     */
    int getHeight() const;

private:
    std::string osName;         ///< OS distribution name
    std::string kernelVersion;  ///< Kernel version string
};

}

#endif /* !OSMODULE_HPP_ */
