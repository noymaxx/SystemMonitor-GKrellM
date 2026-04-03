/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** HostnameModule - Displays hostname and username
*/

#ifndef HOSTNAMEMODULE_HPP_
#define HOSTNAMEMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module displaying system hostname and current username
 */
class HostnameModule : public AModule {
public:
    /**
     * @brief Construct and initialize hostname module
     */
    HostnameModule();

    ~HostnameModule();

    /**
     * @brief Get module name
     * @return "Host"
     */
    std::string getName() const;

    /**
     * @brief Upd hostname and username from system
     */
    void update();

    /**
     * @brief Get hostname and username data
     * @return Vector with hostname and username entries
     */
    std::vector<ModuleData> getData() const;

    /**
     * @brief Get display height
     * @return Number of lines needed
     */
    int getHeight() const;

private:
    std::string hostname;   ///< System hostname
    std::string username;   ///< Current username
};

}

#endif /* !HOSTNAMEMODULE_HPP_ */
