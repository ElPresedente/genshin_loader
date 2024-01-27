//
// Created by vova1 on 27.01.2024.
//

#ifndef GENSHIN_LOADER_MAIN_WINDOW_HPP
#define GENSHIN_LOADER_MAIN_WINDOW_HPP

#include <iostream>
#include <vector>

#include <gtkmm.h>
#include <process.hpp>

#include "config.hpp"

#ifdef NDEBUG
#define CFG "config.json"
#else
#define CFG "../config.json"
#endif


class main_window : public Gtk::Window {
public:
    explicit main_window();
    ~main_window() override = default;

protected:
    std::vector<Gtk::Button> buttons;
    Gtk::Box main_box;
    //Gtk::Column

    void on_button_clicked(int data);

private:
    std::vector<config> configs;

    void execute_config(config& config);

};


#endif //GENSHIN_LOADER_MAIN_WINDOW_HPP
