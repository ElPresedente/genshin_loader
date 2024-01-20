#include <iostream>
#include <variant>
#include <filesystem>
#include <tao/config.hpp>
#include "tiny-process-library/process.hpp"

#ifdef NDEBUG
#define CFG "config.cfg"
#else
#define CFG "../config.cfg"
#endif

namespace fs = std::filesystem;

int main() try{
    tao::config::value config = tao::config::from_file(CFG);
    auto config_map = std::get<11>(config.variant()); //ГРЕШНО, НО ПОКА ВПАДЛУ
    for(auto [key, value] : config_map){
        auto&& cmd_str = value.get_string();
        fs::path current_file = cmd_str;
        auto parent_folder = current_file.parent_path();
        std::cout << "Item " << key << " starting..." << std::endl;
        TinyProcessLib::Process current{cmd_str, parent_folder.string()};
    }
    return 0;
}
catch(const std::exception& e){
    std::cerr << e.what();
    return 1;
}

