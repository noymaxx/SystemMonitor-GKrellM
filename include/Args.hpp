/*
** EPITECH PROJECT, 2025
** rush-04
** File description:
** args
*/

#ifndef ARGS_HPP_
#define ARGS_HPP_

#include <map>
#include <string>

enum ArgType {
    ARG_HELP,
    ARG_TEXT,
    ARG_GRAPHICAL
};

static const std::map<std::string, ArgType> ARG_MAP = {
    {"-h", ARG_HELP}, {"--help", ARG_HELP},
    {"-t", ARG_TEXT}, {"--text", ARG_TEXT},
    {"-g", ARG_GRAPHICAL}, {"--graphical", ARG_GRAPHICAL}
};

#endif /* !ARGS_HPP_ */
