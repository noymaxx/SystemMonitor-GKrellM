/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** HostnameModule
*/

#include <unistd.h>
#include <cstdlib>
#include "HostnameModule.hpp"

namespace Krell {

    HostnameModule::HostnameModule()
    {
        hostname = "";
        username = "";
        update();
    }

    HostnameModule::~HostnameModule()
    {
    }

    std::string HostnameModule::getName() const
    {
        return "Host";
    }

    void HostnameModule::update()
    {
        char buffer[256];

        if (gethostname(buffer, 256) == 0) {
            hostname = buffer;
        } else {
            hostname = "Unknown";
        }

        char *user = std::getenv("USER");
        if (user != nullptr) {
            username = user;
        } else {
            username = "Unknown";
        }
    }

    std::vector<ModuleData> HostnameModule::getData() const
    {
        std::vector<ModuleData> dados;

        dados.push_back(ModuleData("Hostname", hostname));
        dados.push_back(ModuleData("Username", username));

        return dados;
    }

    int HostnameModule::getHeight() const
    {
        return 2;
    }
}
