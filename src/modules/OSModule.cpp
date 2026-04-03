/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** OSModule
*/

#include <sys/utsname.h>
#include <fstream>
#include "OSModule.hpp"

namespace Krell {

OSModule::OSModule()
{
    osName = "";
    kernelVersion = "";
    update();
}

OSModule::~OSModule()
{
}

std::string OSModule::getName() const
{
    return "System";
}

void OSModule::update()
{
    struct utsname buffer;

    if (uname(&buffer) == 0) {
        kernelVersion = buffer.release;
    } else {
        kernelVersion = "Unknown";
    }

    std::ifstream file("/etc/os-release");
    std::string line;

    osName = "Unknown";
    while (std::getline(file, line)) {
        if (line.substr(0, 12) == "PRETTY_NAME=") {
            osName = line.substr(13);
            if (osName.size() > 0 && osName[osName.size() - 1] == '"') {
                osName = osName.substr(0, osName.size() - 1);
            }
            break;
        }
    }
    file.close();
}

std::vector<ModuleData> OSModule::getData() const
{
    std::vector<ModuleData> dados;

    dados.push_back(ModuleData("OS", osName));
    dados.push_back(ModuleData("Kernel", kernelVersion));

    return dados;
}

int OSModule::getHeight() const
{
    return 2;
}

}
