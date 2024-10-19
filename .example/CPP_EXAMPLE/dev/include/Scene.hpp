#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <list>

class Scene {
 private:
  bool isScene;

 public:
  void onScene();
  void offScene();
  void awake();
  int update();
};

class SceneObject {
 public:
  void awake();
  int update();
};

#endif