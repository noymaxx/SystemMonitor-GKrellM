/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** NetworkModule - Displays network statistics (bonus)
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module displaying network interface statistics
 */
class NetworkModule : public AModule {
public:
    /**
     * @brief Construct and initialize network module
     */
    NetworkModule();

    ~NetworkModule();

    /**
     * @brief Get module name
     * @return "Network"
     */
    std::string getName() const;

    /**
     * @brief Upd network stats from /sys/class/net
     */
    void update();

    /**
     * @brief Get network interface and transfer data
     * @return Vector with interface name, downloaded and uploaded bytes
     */
    std::vector<ModuleData> getData() const;

    /**
     * @brief Get display height
     * @return Number of lines needed
     */
    int getHeight() const;

private:
    std::string interface;  ///< Active network interface name
    long rxBytes;           ///< Total received bytes
    long txBytes;           ///< Total transmitted bytes
};

}

#endif /* !NETWORKMODULE_HPP_ */
