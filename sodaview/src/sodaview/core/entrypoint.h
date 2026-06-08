#pragma once

extern Core::Application* Core::createApplication();

int main(int argc, char** argv)
{
    
    auto app = Core::createApplication();
    // app->createTriangle();
    app->run();
    delete app;

}