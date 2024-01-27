//
// Created by vova1 on 27.01.2024.
//

#include "config.hpp"

std::vector<config> config::read_file(const char *path) {
    std::vector<config> result;

    fs::path config_file{path};

    if(!fs::exists(config_file)){
        std::stringstream s;
        s << "Cant find config file at " << path;
        throw std::runtime_error{s.str()};
    }
    std::ifstream fin{path};
    Json::Value root;
    fin >> root;

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
