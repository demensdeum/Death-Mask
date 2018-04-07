/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEGTIOFSGLInputController.cpp
 * Author: demensdeum
 * 
 * Created on August 12, 2017, 8:06 PM
 */

#include "FSEGTIOFSGLInputController.h"

#include <SDL2/SDL.h>

FSEGTIOFSGLInputController::FSEGTIOFSGLInputController() {
    
    FSEGTInputController::clearKeys();
    
}

FSEGTIOFSGLInputController::FSEGTIOFSGLInputController(const FSEGTIOFSGLInputController& ) {
}

void FSEGTIOFSGLInputController::pollKey() {
    
    SDL_Event event;

    while (SDL_PollEvent(&event)) {

        switch (event.type) {

            case SDL_QUIT:
                this->exitKeyPressed = true;
                break;

            case SDL_MOUSEBUTTONDOWN:
                shootKeyPressed = true;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {

			case SDLK_RSHIFT:
				this->rotateRightKeyPressed = true;
				break;

			case SDLK_LSHIFT:
				this->rotateLeftKeyPressed = true;
				break;

                    case SDLK_LEFT:
                        this->leftKeyPressed = true;
                        break;

                    case SDLK_RIGHT:
                        this->rightKeyPressed = true;
                        break;

                    case SDLK_UP:
                        this->upKeyPressed = true;
                        break;

                    case SDLK_DOWN:
                        this->downKeyPressed = true;
                        break;

                    case SDLK_SPACE:
                        this->shootKeyPressed = true;
                        break;

                    case SDLK_ESCAPE:
                        this->exitKeyPressed = true;
                        break;

                    default:
                        break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym) {

			case SDLK_RSHIFT:
				this->rotateRightKeyPressed = false;
				break;

			case SDLK_LSHIFT:
				this->rotateLeftKeyPressed = false;
				break;

                    case SDLK_LEFT:
                        this->leftKeyPressed = false;
                        break;

                    case SDLK_RIGHT:
                        this->rightKeyPressed = false;
                        break;

                    case SDLK_UP:
                        this->upKeyPressed = false;
                        break;

                    case SDLK_DOWN:
                        this->downKeyPressed = false;
                        break;

                    case SDLK_SPACE:
                        this->shootKeyPressed = false;
                        break;

                    default:
                        break;
                }
                break;
        }
    }
}

FSEGTIOFSGLInputController::~FSEGTIOFSGLInputController() {
}
