#include <iostream>
#include <variant>
#include <filesystem>
#include <fstream>

#include <process.hpp>
#include <json/json.h>

#include "main_window.hpp"


int main(int argc, char** argv){

    auto app = Gtk::Application::create("org.arhebs.lispkit_compiler");

    return app->make_window_and_run<main_window>(argc, argv);

//    tao::config::value config = tao::config::from_file(CFG);
//    auto config_map = std::get<11>(config.variant()); //ГРЕШНО, НО ПОКА ВПАДЛУ
//    for(auto [key, value] : config_map){
//        auto&& cmd_str = value.get_string();
//        fs::path current_file = cmd_str;
//        auto parent_folder = current_file.parent_path();
//        std::cout << "Item " << key << " starting...." << std::endl;
//        TinyProcessLib::Process current{cmd_str, parent_folder.string()};
//    }
//    return 0;
}

