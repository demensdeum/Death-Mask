/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLCore.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 10:10 AM
 */

#ifndef FSEOGLCORE_H
#define FSEOGLCORE_H

#include <SDL2/SDL.h>

#include <memory>

#include "../Data/Model/FSGLModel.h"

#include <GLES3/gl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Data/Object/FSGLObject.h"

#include "../Data/Camera/FSGLCamera.h"

using namespace std;

class FSGLCore {
public:
    FSGLCore();
    FSGLCore(const FSGLCore& orig);
    virtual ~FSGLCore();
    
    void initialize();
    
    void addObject(shared_ptr<FSGLObject> object);
    
    void render();
    
    void stop();
    
    shared_ptr<FSGLCamera> camera;
    
private:
    
    void renderObject(shared_ptr<FSGLObject> object);
    
    GLint common_get_shader_program(const char *vertex_shader_source, const char *fragment_shader_source);

    SDL_GLContext context;
    GLuint shader_program;
    
    GLuint vbo, indexBuffer;
   
    SDL_Window *window;
    
    vector<shared_ptr<FSGLObject>> objects;    

};

#endif /* FSEOGLCORE_H */

