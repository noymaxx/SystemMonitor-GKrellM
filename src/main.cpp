/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** main
*/

#include <iostream>
#include <string>
#include <memory>
#include "Args.hpp"
#include "MonitorCore.hpp"
#include "NCursesDisplay.hpp"
#include "SFMLDisplay.hpp"
#include "HostnameModule.hpp"
#include "OSModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "BatteryModule.hpp"
#include "NetworkModule.hpp"

/**
 * @brief Disp the help message
 * @param progName programme
 */
static void printHelp(const std::string &progName)
{
    std::cout << "Usage: " << progName << " [OPTIONS]" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -t, --text      Launch in text mode (nCurses)" << std::endl;
    std::cout << "  -g, --graphical Launch in graphical mode" << std::endl;
    std::cout << "  -h, --help      Display this help message" << std::endl;
}

/**
 * @brief parse command line args
 * @param argc args nb
 * @param argv args values
 * @param textMode ref to text flag
 * @param graphicalMode ref to graphical flag
 * @return 0 on success / 1 for help / 84 on error
 */
static int parseArgs(int argc, char **argv, bool &textMode, bool &graphicalMode)
{
    std::string arg;

    for (int i = 1; i < argc; i++) {
        arg = argv[i];
        auto it = ARG_MAP.find(arg);
        if (it == ARG_MAP.end()) {
            std::cerr << "Unknown option: " << arg << std::endl;
            printHelp(argv[0]);
            return 84;
        }
        switch (it->second) {
            case ARG_HELP:
                printHelp(argv[0]);
                return 1;
            case ARG_TEXT:
                textMode = true;
                break;
            case ARG_GRAPHICAL:
                graphicalMode = true;
                break;
        }
    }
    if (textMode && graphicalMode) {
        std::cerr << "Error: Cannot use both text and graphical mode" << std::endl;
        return 84;
    }
    return 0;
}

/**
 * @brief main
 * @param argc args nb
 * @param argv args values
 * @return 0 on success / 84 on error
 */
int main(int argc, char **argv)
{
    bool textMode = false;
    bool graphicalMode = false;
    int ret = parseArgs(argc, argv, textMode, graphicalMode);
    Krell::MonitorCore core;

    if (ret != 0)
        return ret == 1 ? 0 : ret;
    if (!textMode && !graphicalMode)
        textMode = true;
    core.addModule(std::make_unique<Krell::HostnameModule>());
    core.addModule(std::make_unique<Krell::OSModule>());
    core.addModule(std::make_unique<Krell::DateTimeModule>());
    core.addModule(std::make_unique<Krell::CPUModule>());
    core.addModule(std::make_unique<Krell::RAMModule>());
    core.addModule(std::make_unique<Krell::BatteryModule>());
    core.addModule(std::make_unique<Krell::NetworkModule>());
    if (textMode)
        core.setDisplay(std::make_unique<Krell::NCursesDisplay>());
    else
        core.setDisplay(std::make_unique<Krell::SFMLDisplay>());
    core.run();
    return 0;
}
