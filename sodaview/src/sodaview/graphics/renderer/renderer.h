#pragma once

#include "../../core/vksetup/vksetup.h"

namespace Graphics {

    class Renderer 
    {

    public:
        Renderer(Core::vksetup::VkContext& cxt);


        
        void drawFrame();
        
        
        void onResize();

        
        void frameSync();




        


    private:

        
        Core::vksetup::VkContext& m_cxt;

    };
}