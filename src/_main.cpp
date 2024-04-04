#include "pandaFramework.h"
#include "pandaSystem.h"

int main(int argc, char *argv[]) {
  // Open a new window framework
  PandaFramework framework;
  framework.open_framework(argc, argv);

  // Set the window title and open the window
  framework.set_window_title("My Panda3D Window");
  WindowFramework *window = framework.open_window();
  window->setup_trackball();

  // Here is room for your own code
  // Load the environment model.
  NodePath scene = window->load_model(framework.get_models(),
                                      "panda3d-1.10.14/models/environment.egg");
  // Reparent the model to render.
  scene.reparent_to(window->get_render());
  // Apply scale and position transforms to the model.
  scene.set_scale(0.25f, 0.25f, 0.25f);
  scene.set_pos(-8, 42, 0);

  // Do the main loop, equal to run() in python
  framework.main_loop();
  framework.close_framework();
  return (0);
}
