/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** NetworkModule (bonus)
*/

#include <fstream>
#include <sstream>
#include "NetworkModule.hpp"

namespace Krell {

NetworkModule::NetworkModule()
{
    interface = "";
    rxBytes = 0;
    txBytes = 0;
    update();
}

NetworkModule::~NetworkModule()
{
}

std::string NetworkModule::getName() const
{
    return "Network";
}

void NetworkModule::update()
{
    std::ifstream file("/proc/net/dev");
    std::string line;

    std::getline(file, line);
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string iface;
        long rx;

        iss >> iface >> rx;

        if (iface != "lo:" && rx > 0) {
            interface = iface;
            if (interface[interface.size() - 1] == ':') {
                interface = interface.substr(0, interface.size() - 1);
            }
            rxBytes = rx;

            long skip;
            for (int i = 0; i < 7; i++) {
                iss >> skip;
            }
            iss >> txBytes;
            break;
        }
    }
    file.close();
}

std::vector<ModuleData> NetworkModule::getData() const
{
    std::vector<ModuleData> dados;

    dados.push_back(ModuleData("Interface", interface));

    std::ostringstream ossRx;
    ossRx << (rxBytes / 1024 / 1024) << " MB";
    dados.push_back(ModuleData("Downloaded", ossRx.str()));

    std::ostringstream ossTx;
    ossTx << (txBytes / 1024 / 1024) << " MB";
    dados.push_back(ModuleData("Uploaded", ossTx.str()));

    return dados;
}

int NetworkModule::getHeight() const
{
    return 3;
}

}
