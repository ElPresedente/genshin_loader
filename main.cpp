#include <iostream>
#include <map>
#include <variant>
#include <vector>
#include <windowsx.h>
#include "include/tao/config.hpp"

#ifdef NDEBUG
#define CFG "config.cfg"
#else
#define CFG "../config.cfg"
#endif

int main() try{
    tao::config::value config = tao::config::from_file(CFG);
    auto config_map = std::get<11>(config.variant()); //ГРЕШНО, НО ПОКА ВПАДЛУ
    for(auto [key, value] : config_map){
        auto&& cmd_str = value.get_string();
        std::cout << "Item " << key << " starting..." << std::endl;
        std::vector<char> cmd;
        cmd.reserve(1000);
        std::copy(cmd_str.begin(), cmd_str.end(), cmd.begin());
        CreateProcessA(
                key.c_str(),
                cmd.data(),
                NULL,
                NULL,
                FALSE,
                NULL,
                NULL,
                NULL,
                NULL,
                NULL);
    }
    return 0;
}
catch(const std::exception& e){
    std::cerr << e.what();
    return 1;
}

