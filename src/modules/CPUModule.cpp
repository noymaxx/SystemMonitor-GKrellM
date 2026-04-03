/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** CPUModule
*/

#include <fstream>
#include <sstream>
#include "CPUModule.hpp"

namespace Krell {

CPUModule::CPUModule()
    : _model("Unknown"), _frequency("Unknown"), _cores(0), _usage(0.0f),
      _prevTotal(0), _prevIdle(0)
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::size_t pos = 0;
    std::string mhz;
    float freq = 0;
    std::ostringstream oss;
    int coreCount = 0;

    while (std::getline(file, line)) {
        if (line.find("model name") != std::string::npos) {
            pos = line.find(':');
            if (pos != std::string::npos)
                _model = line.substr(pos + 2);
        }
        if (line.find("cpu MHz") != std::string::npos) {
            pos = line.find(':');
            if (pos != std::string::npos) {
                mhz = line.substr(pos + 2);
                freq = std::stof(mhz);
                oss.str("");
                oss << static_cast<int>(freq) << " MHz";
                _frequency = oss.str();
            }
        }
        if (line.find("processor") != std::string::npos)
            coreCount++;
    }
    _cores = coreCount;
    update();
}

CPUModule::~CPUModule()
{
}

std::string CPUModule::getName() const
{
    return "CPU";
}

void CPUModule::update()
{
    std::ifstream file("/proc/stat");
    std::string line;
    std::string cpu;
    long user = 0;
    long nice = 0;
    long system = 0;
    long idle = 0;
    long iowait = 0;
    long irq = 0;
    long softirq = 0;
    long total = 0;
    long idleTime = 0;
    long deltaTotal = 0;
    long deltaIdle = 0;

    if (!std::getline(file, line))
        return;
    std::istringstream iss(line);
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq;
    total = user + nice + system + idle + iowait + irq + softirq;
    idleTime = idle + iowait;
    if (_prevTotal > 0) {
        deltaTotal = total - _prevTotal;
        deltaIdle = idleTime - _prevIdle;
        if (deltaTotal > 0)
            _usage = 100.0f * (1.0f - static_cast<float>(deltaIdle)
                / static_cast<float>(deltaTotal));
    }
    _prevTotal = total;
    _prevIdle = idleTime;
}

std::vector<ModuleData> CPUModule::getData() const
{
    std::vector<ModuleData> data;
    std::ostringstream oss;

    data.push_back(ModuleData("Model", _model));
    data.push_back(ModuleData("Frequency", _frequency));
    oss << _cores;
    data.push_back(ModuleData("Cores", oss.str()));
    oss.str("");
    oss << static_cast<int>(_usage) << "%";
    data.push_back(ModuleData("Usage", oss.str(), _usage));
    return data;
}

int CPUModule::getHeight() const
{
    return 6;
}

}
