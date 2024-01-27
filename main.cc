#include <variant>

#include "main_window.hpp"

#ifdef WINDOWS
int WinMain (void * hInstance, void * hPrevInstance, char ** argv, int nCmdShow){
#else
int main(int __argc, char** __argv){
#endif
    auto app = Gtk::Application::create("org.elpresedente.custom_launcher");

    return app->make_window_and_run<main_window>(__argc, __argv);
}

