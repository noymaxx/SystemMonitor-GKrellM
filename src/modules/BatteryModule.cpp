/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** BatteryModule (bonus)
*/

#include <fstream>
#include <sstream>
#include "BatteryModule.hpp"

namespace Krell {

BatteryModule::BatteryModule()
{
    status = "";
    capacity = 0;
    hasBattery = false;
    update();
}

BatteryModule::~BatteryModule()
{
}

std::string BatteryModule::getName() const
{
    return "Battery";
}

void BatteryModule::update()
{
    std::ifstream fileCapacity("/sys/class/power_supply/BAT0/capacity");
    std::ifstream fileStatus("/sys/class/power_supply/BAT0/status");

    if (fileCapacity.is_open() && fileStatus.is_open()) {
        hasBattery = true;
        fileCapacity >> capacity;
        std::getline(fileStatus, status);
    } else {
        hasBattery = false;
        status = "No battery";
        capacity = 0;
    }

    fileCapacity.close();
    fileStatus.close();
}

std::vector<ModuleData> BatteryModule::getData() const
{
    std::vector<ModuleData> dados;

    dados.push_back(ModuleData("Status", status));

    std::ostringstream oss;
    oss << capacity << "%";
    dados.push_back(ModuleData("Level", oss.str(), (float)capacity));

    return dados;
}

int BatteryModule::getHeight() const
{
    return 2;
}

}
