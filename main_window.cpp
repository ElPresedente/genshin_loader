//
// Created by vova1 on 27.01.2024.
//

#include "main_window.hpp"

main_window::main_window() : main_box(Gtk::Orientation::VERTICAL, 0) {
    set_title("Genshin loader");

    this->configs = config::read_file(CFG);

    main_box.set_vexpand();

    for(int i = 0 ; i < configs.size(); i++){
        Gtk::Box current_box{Gtk::Orientation::HORIZONTAL};
        current_box.set_hexpand();
        for(int j = 0; j < 3 && i < configs.size(); j++, i++){
            auto&& config = configs.at(i);
            auto&& current_button = buttons.emplace_back(config.name);
            current_button.signal_clicked().connect(
                    sigc::bind(
                            sigc::mem_fun(*this, &main_window::on_button_clicked),
                            i
                    )
            );
            current_box.append(current_button);
        }
        main_box.append(current_box);
    }

    set_child(main_box);
}

void main_window::on_button_clicked(int data) {
    execute_config(configs.at(data));
    std::exit(0);
}

void main_window::execute_config(config &config) {
#ifndef NDEBUG
    std::cout << "Executing " << config.name << " config" << std::endl;
#endif
    for(auto&& command : config.commands){
#ifndef NDEBUG
        std::cout << "Executing " << command.name << " command" << std::endl;
#endif
        fs::path command_destination{command.command};
        if(!fs::exists(command_destination))
        {
#ifndef NDEBUG
            std::cout << "Command not found" << std::endl;
#endif
            continue;
        }
        auto parent_folder = command_destination.parent_path();
        std::cout << "Command starting...." << std::endl;
        TinyProcessLib::Process current{command.command, parent_folder.string()};
    }
}
