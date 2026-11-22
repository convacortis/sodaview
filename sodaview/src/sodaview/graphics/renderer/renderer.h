#pragma once

#include "../../core/vksetup/vksetup.h"

namespace Graphics {

    class Renderer 
    {

    public:
        
        Renderer(Core::vksetup::VkContext& cxt);

        void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
        void recreateSwapChain();
        void drawFrame();
        void onResize();
        void frameSync();

    private:

        Core::vksetup::VkContext& m_cxt;

    };
}