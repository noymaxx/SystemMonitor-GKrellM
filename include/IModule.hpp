/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** IModule interface
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include <string>
#include <vector>

namespace Krell {

/**
 * @brief Data structure for module display information
 */
struct ModuleData {
    std::string label;      ///< Label displayed before value
    std::string value;      ///< Value to display
    float percentage;       ///< Progress bar value (0-100), -1 if not applicable

    /**
     * @brief Construct module data
     * @param l Label text
     * @param v Value text
     * @param p Percentage for progress bar (-1 to hide bar)
     */
    ModuleData(const std::string &l, const std::string &v, float p = -1.0f)
        : label(l), value(v), percentage(p) {}
};

/**
 * @brief Interface for all system monitoring modules
 */
class IModule {
public:
    virtual ~IModule() = default;

    /**
     * @brief Get module display name
     * @return Module name string
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Upd module data from system
     */
    virtual void update() = 0;

    /**
     * @brief Get module data for display
     * @return Vector of ModuleData entries
     */
    virtual std::vector<ModuleData> getData() const = 0;

    /**
     * @brief Get module height in display lines
     * @return Number of lines needed
     */
    virtual int getHeight() const = 0;

    /**
     * @brief Check if module is enabled
     * @return true if module should be displayed
     */
    virtual bool isEnabled() const = 0;

    /**
     * @brief Enable or disable module
     * @param enabled New enabled state
     */
    virtual void setEnabled(bool enabled) = 0;
};

}

#endif /* !IMODULE_HPP_ */
