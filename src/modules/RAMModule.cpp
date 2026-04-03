/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** RAMModule
*/

#include <fstream>
#include <sstream>
#include "RAMModule.hpp"

namespace Krell {

RAMModule::RAMModule()
{
    total = 0;
    available = 0;
    used = 0;
    usage = 0.0f;
    update();
}

RAMModule::~RAMModule()
{
}

std::string RAMModule::getName() const
{
    return "RAM";
}

void RAMModule::update()
{
    std::ifstream file("/proc/meminfo");
    std::string line;

    while (std::getline(file, line)) {
        if (line.substr(0, 9) == "MemTotal:") {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> total;
        }
        if (line.substr(0, 13) == "MemAvailable:") {
            std::istringstream iss(line);
            std::string label;
            iss >> label >> available;
        }
    }
    file.close();

    used = total - available;
    if (total > 0) {
        usage = (float)used / (float)total * 100.0f;
    }
}

std::vector<ModuleData> RAMModule::getData() const
{
    std::vector<ModuleData> dados;

    std::ostringstream ossTotal;
    ossTotal << (total / 1024) << " MB";
    dados.push_back(ModuleData("Total", ossTotal.str()));

    std::ostringstream ossUsed;
    ossUsed << (used / 1024) << " MB";
    dados.push_back(ModuleData("Used", ossUsed.str()));

    std::ostringstream ossAvailable;
    ossAvailable << (available / 1024) << " MB";
    dados.push_back(ModuleData("Available", ossAvailable.str()));

    std::ostringstream ossUsage;
    ossUsage << (int)usage << "%";
    dados.push_back(ModuleData("Usage", ossUsage.str(), usage));

    return dados;
}

int RAMModule::getHeight() const
{
    return 4;
}

}
