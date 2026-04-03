/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** DateTimeModule
*/

#include <ctime>
#include "DateTimeModule.hpp"

namespace Krell {

DateTimeModule::DateTimeModule()
{
    data = "";
    hora = "";
    update();
}

DateTimeModule::~DateTimeModule()
{
}

std::string DateTimeModule::getName() const
{
    return "DateTime";
}

void DateTimeModule::update()
{
    std::time_t now = std::time(nullptr);
    std::tm *time = std::localtime(&now);

    char bufferData[32];
    char bufferHora[32];

    std::strftime(bufferData, 32, "%d/%m/%Y", time);
    std::strftime(bufferHora, 32, "%H:%M:%S", time);

    data = bufferData;
    hora = bufferHora;
}

std::vector<ModuleData> DateTimeModule::getData() const
{
    std::vector<ModuleData> dados;

    dados.push_back(ModuleData("Date", data));
    dados.push_back(ModuleData("Time", hora));

    return dados;
}

int DateTimeModule::getHeight() const
{
    return 2;
}

}
