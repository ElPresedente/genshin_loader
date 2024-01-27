//
// Created by vova1 on 27.01.2024.
//

#ifndef GENSHIN_LOADER_CONFIG_HPP
#define GENSHIN_LOADER_CONFIG_HPP

#include <fstream>
#include <vector>
#include <filesystem>
#include <sstream>

#include <json/json.h>

namespace fs = std::filesystem;

struct command{
    std::string name;
    std::string command;
};

struct config {
    static std::vector<config> read_file(const char* path);

    std::string name;
    std::vector<command> commands;
};


#endif //GENSHIN_LOADER_CONFIG_HPP
