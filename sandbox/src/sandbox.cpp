#include "../../sodaview/src/sodaview.h"

class Sandbox : public Sodaview::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {


    }

};

Sodaview::Application* Sodaview::createApplication()
{
    return new Sandbox;
}