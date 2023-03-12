#include <iostream>
#include <memory>
#include <Core/Application.h>

class MyApp : public Engine::Application {
    virtual void on_update() override {
        //std::cout << "Update frame: " << frame++ << std::endl;
    }

    int frame = 0;
};

int main() {
    auto myApp = std::make_unique<MyApp>();

    int returnCode = myApp->start(1366, 768, "OpenGL 4.6");

    std::cin.get();

    return returnCode;
}
