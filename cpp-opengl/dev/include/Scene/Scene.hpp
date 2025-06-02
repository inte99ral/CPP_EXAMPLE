#ifndef SCENE_HPP
#define SCENE_HPP

#include <conio.h>
#include <iostream>
#include <list>
#include <Windows.h>

using namespace std;

// # Prototype Declaration ==================================================

// ## Scene Object

class SceneObject {
 public:
  void awake();
  void start();
  int update();
};

// ## Scene

class Scene {

// ### Scene > Private

 private:

  // #### Scene > Private > Variable

  string title;
  int width;
  int height;
  bool isScene;
  list<SceneObject> soList;

  // #### Scene > Private > Method

  void awake();
  void start();
  int update();

// ### Scene > Public

 public:

 // #### Scene > Public > Constructor & Destructor

  Scene();
  Scene(string _title, int _width, int _height);
  ~Scene();
  // Scene(const std::list<SceneObject> sl);
  // void onScene();
  // void offScene();

  // #### Scene > Public > Variable

  void setTitle(string title);
  string getTitle();

  void setWidth(int width);
  int getWidth();

  void setHeight(int height);
  int getHeight();

  // #### Scene > Public > Method

  void setScene();
  
};


#endif