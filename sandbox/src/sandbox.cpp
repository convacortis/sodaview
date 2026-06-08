#include "../../sodaview/src/sodaview.h"

class Sandbox : public Core::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {


    }

};

Core::Application* Core::createApplication()
{
    return new Sandbox;
}