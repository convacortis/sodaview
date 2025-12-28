#pragma once

extern sodaview::application* sodaview::createApplication();

int main(int argc, char** argv)
{
    
    auto app = sodaview::createApplication();
    app->run();
    delete app;

}