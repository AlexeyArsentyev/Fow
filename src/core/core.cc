#include "core.h"

#include <memory>

#include "screen/screen.h"
#include "screen/screen_controller.h"

namespace fow {
    Core& Core::Get() {
        static Core instance;
        return instance;
    }

    void Core::Start() {
        // Initialization 
        InitWindow(1920, 1080, false);
        screen_controller_ = std::make_unique<ScreenController>(ScreenType::kMenu, window_);
        // Main cycle
        Loop();

    }

    void Core::InitWindow(int width, int height, bool fullscreen) {
        window_.Init(width, height, "Fow");
        window_.SetFullscreen(fullscreen);
        window_.SetExitKey(KEY_NULL);
        window_.SetTargetFPS(60);

    }

    void Core::Loop() {
        while (!window_.ShouldClose()) {
            
            screen_controller_->ProcessScreen();
        }

        window_.Close();
    }
}