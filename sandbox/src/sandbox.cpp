#include "../../sodaview/src/sodaview.h"

class Sandbox : public sodaview::application
{
public:
    Sandbox(){

    }

    ~Sandbox(){


    }

};

sodaview::application* sodaview::createApplication()
{
    return new Sandbox;
}