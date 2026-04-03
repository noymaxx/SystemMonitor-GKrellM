/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include <string>
#include "AModule.hpp"

namespace Krell {

/**
 * @brief Module CPU
 */
class CPUModule : public AModule {
public:
    /**
     * @brief Construct and iit CPU module
     */
    CPUModule();

    ~CPUModule();

    /**
     * @brief Get module name
     * @return "CPU"
     */
    std::string getName() const override;

    /**
     * @brief Upd CPU usage from /proc/stat
     */
    void update() override;

    /**
     * @brief Get CPU data with usage progress bar
     * @return Vector with model, frequency, cores and usage
     */
    std::vector<ModuleData> getData() const override;

    /**
     * @brief Get display height
     * @return Nb of lines needed
     */
    int getHeight() const override;

private:
    std::string _model;      ///< CPU model name
    std::string _frequency;  ///< CPU frequency
    int _cores;              ///< Nb of cores
    float _usage;            ///< CPU usage %
    long _prevTotal;         ///< Prev total CPU time
    long _prevIdle;          ///< Prev idle CPU time
};

}

#endif /* !CPUMODULE_HPP_ */
