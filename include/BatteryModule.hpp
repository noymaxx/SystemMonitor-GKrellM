/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** BatteryModule - Displays battery status (bonus)
*/

#ifndef BATTERYMODULE_HPP_
#define BATTERYMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module displaying battery status from /sys/class/power_supply
 */
class BatteryModule : public AModule {
public:
    /**
     * @brief Construct and initialize battery module
     */
    BatteryModule();

    ~BatteryModule();

    /**
     * @brief Get module name
     * @return "Battery"
     */
    std::string getName() const;

    /**
     * @brief Upd battery info from /sys/class/power_supply
     */
    void update();

    /**
     * @brief Get battery status and level with progress bar
     * @return Vector with status and capacity percentage
     */
    std::vector<ModuleData> getData() const;

    /**
     * @brief Get display height
     * @return Number of lines needed
     */
    int getHeight() const;

private:
    std::string status;     ///< Charging/Discharging/Full
    int capacity;           ///< Battery percentage (0-100)
    bool hasBattery;        ///< True if battery is present
};

}

#endif /* !BATTERYMODULE_HPP_ */
