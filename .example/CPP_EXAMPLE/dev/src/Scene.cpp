#include "../include/Scene.hpp"

class Scene {
 private:
  bool isScene;
  std::list<SceneObject> soList;

  void offScene() { 
    isScene = false; 
  }

  void awake() { 
    for (SceneObject so : soList) { so.awake(); }
    return; 
  }
  int update() {
    for (SceneObject so : soList) { so.update(); }
    return 0; 
  }

 public:
  Scene() {
    isScene = true;
  }

  Scene(const std::list<SceneObject> sl) {
    isScene = true;
    soList = sl;
  }

  void onScene() {
    awake();

    while (isScene) {
      if (!update()) break;

    }

    return;
  }
};
