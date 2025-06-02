#include "../../include/Scene/Scene.hpp"

// # Implements Definition ==================================================

// ## Scene

// ### Scene > Private

// #### Scene > Private > Method

void Scene::awake() {}
void Scene::start() {}
int Scene::update() { return 99; }

// ### Scene > Public

// #### Scene > Public > Constructor & Destructor

Scene::Scene() : Scene("DEFAULT TITLE", 10, 10) {};
Scene::Scene(string _title, int _width, int _height) : title(_title), width(_width), height(_height) {
    cout << "scene on" << this->title << " - " << this->width << " - " << this->height << endl;
}
Scene::~Scene() { 
    cout << "scene over" << this->width << " - " << this->height << endl; 
};

// #### Scene > Public > Method

void Scene::setTitle(string title) { this->title = title; }
string Scene::getTitle() { return this->title; }

void Scene::setWidth(int width) { this->width = width; }
int Scene::getWidth() { return this->width; }

void Scene::setHeight(int height) { this->height = height; }
int Scene::getHeight() { return this->height; }

// #### Scene > Public > Method

void Scene::setScene() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ), &csbi)) {
        // * Don't Over Screen Size
        if (this->height > csbi.dwSize.Y) this->height = csbi.dwSize.Y;
        if (this->width > csbi.dwSize.X) this->width  = csbi.dwSize.X;

        // Adjust window origin if necessary
        if ((csbi.srWindow.Top + this->height) > csbi.dwSize.Y) csbi.srWindow.Top  = csbi.dwSize.Y - this->height - 1;
        if ((csbi.srWindow.Left + this->width) > csbi.dwSize.Y) csbi.srWindow.Left = csbi.dwSize.X - this->width - 1;
    }





    // CONSOLE_SCREEN_BUFFER_INFO csbi;
    // if (GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ), &csbi))
    // {
    //     // Make sure the new size isn't too big
    //     if(height > csbi.dwSize.Y) height = csbi.dwSize.Y;
    //     if(width  > csbi.dwSize.X) width  = csbi.dwSize.X;

    //     // Adjust window origin if necessary
    //     if((csbi.srWindow.Top  +height) > csbi.dwSize.Y) csbi.srWindow.Top  = csbi.dwSize.Y -height -1;
    //     if((csbi.srWindow.Left +width)  > csbi.dwSize.Y) csbi.srWindow.Left = csbi.dwSize.X -width  -1;

    //     // Calculate new size
    //     csbi.srWindow.Bottom = csbi.srWindow.Top  +height -1;
    //     csbi.srWindow.Right  = csbi.srWindow.Left +width  -1;

    //     SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &csbi.srWindow);
    // }
};