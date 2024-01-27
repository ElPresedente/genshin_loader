//
// Created by vova1 on 27.01.2024.
//

#include <iostream>
#include "config.hpp"

std::vector<config> config::read_file(const char *path) {
    std::vector<config> result;

    fs::path config_file{path};

    if(!fs::exists(config_file)){
        throw std::runtime_error{"cant find config file"};
    }
    std::ifstream fin{path};
    Json::Value root;
    try{
        fin >> root;
    }
    catch(std::exception e){
        std::cerr << e.what();
    }

    for(auto&& current_json : root){
        config current;
        current.name = current_json.get("name", "no_name").asString();
        auto&& commands_array = current_json["commands"];
        for(auto&& current_command : commands_array){
            command com;
            com.command = current_command["command"].asString();
            com.name = current_json.get("name", "no_name").asString();
            current.commands.push_back(std::move(com));
        }
        result.push_back(std::move(current));
    }
    return result;
}
