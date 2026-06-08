#pragma once

extern Sodaview::Application* Sodaview::createApplication();

int main(int argc, char** argv)
{
    
    auto app = Sodaview::createApplication();
    // app->createTriangle();
    app->run();
    delete app;

}