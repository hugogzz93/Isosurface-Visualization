#include <stdlib.h> 
#include <math.h>
#include <vector>
#include "Vector2f.hpp"
#include "Vector3f.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

char title[] = "Homework";

class Node {
public:
  Node(Vector3f _pos) : position(_pos) {}
  Vector3f position;
  int vertexIndex;
};

class ControlNode : Node {
public:
  bool active;
  Node above, right;

  ControlNode(Vector3f _pos, bool _active, float squareSize) : Node(_pos) {
    active = _active;
    above = *new Node(position + Vector3f::FORWARD * squareSize/2.0f);
    right = *new Node(position + Vector3f::RIGHT * squareSize/2.0f);
  }
    
};

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    Vector3f v;
    
    return 0;
}
