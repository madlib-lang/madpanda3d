#include "gc.h"
#include "maybe.hpp"
#include "pandaFramework.h"
#include "pandaSystem.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct madpanda__NodePath {
  NodePath data;
} madpanda__NodePath_t;

PandaFramework *madpanda__framework__make() { return new PandaFramework(); }

PandaFramework *madpanda__framework__open(PandaFramework *framework) {
  framework->open_framework();
  return framework;
}

PandaFramework *madpanda__framework__setWindowTitle(char *title,
                                                    PandaFramework *framework) {
  framework->set_window_title(title);
  return framework;
}

WindowFramework *madpanda__framework__openWindow(PandaFramework *framework) {
  return framework->open_window();
}

madpanda__NodePath_t *madpanda__windowframework__loadModel(
    madlib__maybe__Maybe_t *maybeParent, char *path,
    WindowFramework *windowFramework) {
  NodePath *parent = NULL;
  if (maybeParent->index == madlib__maybe__Maybe_JUST_INDEX) {
    parent = (NodePath *)maybeParent->data;
  }

  madpanda__NodePath_t *nodePath =
      (madpanda__NodePath_t *)GC_MALLOC(sizeof(madpanda__NodePath_t));
  nodePath->data = windowFramework->load_model(
      windowFramework->get_panda_framework()->get_models(), path);

  return nodePath;
}

void runIt(PandaFramework *framework, WindowFramework *window,
           madpanda__NodePath_t *scene) {
  // // Open a new window framework
  // PandaFramework framework;
  // framework.open_framework();

  // // Set the window title and open the window
  // framework.set_window_title("My Panda3D Window");
  // WindowFramework *window = framework.open_window();
  window->setup_trackball();

  // Here is room for your own code
  // Load the environment model.
  // window->get_render().reparent_to();
  // NodePath scene = window->load_model(framework->get_models(),
  //                                     "panda3d-1.10.14/models/environment.egg");
  // Reparent the model to render.
  scene->data.reparent_to(window->get_render());
  // Apply scale and position transforms to the model.
  scene->data.set_scale(0.25f, 0.25f, 0.25f);
  scene->data.set_pos(-8, 42, 0);

  // Do the main loop, equal to run() in python
  framework->main_loop();
  framework->close_framework();
}

#ifdef __cplusplus
}
#endif
