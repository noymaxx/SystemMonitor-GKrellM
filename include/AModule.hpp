/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** AModule abstract class
*/

#ifndef AMODULE_HPP_
#define AMODULE_HPP_

#include "IModule.hpp"

namespace Krell {

/**
 * @brief Abstract base class for all modules
 */
class AModule : public IModule {
public:
    /**
     * @brief Construct module with enabled state
     */
    AModule() : _enabled(true) {}

    virtual ~AModule() = default;

    /**
     * @brief Check if module is enabled
     * @return true if module should be displayed
     */
    bool isEnabled() const override { return _enabled; }

    /**
     * @brief Enable or disable module
     * @param enabled New enabled state
     */
    void setEnabled(bool enabled) override { _enabled = enabled; }

protected:
    bool _enabled;
};

}

#endif /* !AMODULE_HPP_ */
