//
//  CCWProgram.hpp
//  LiveAppDemo
//
//  Created by ccwiner on 2020/6/1.
//  Copyright © 2020 com.LiveDemo. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <OpenGLES/ES2/gl.h>
#include <iostream>
#include <string>

class CCWProgram {
    std::string readFile(const char* fileLocation);
    void compileShader(const char* vertStr, const char* fragStr);
    void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
    void clearProgram();
    ~CCWProgram();
    
    GLuint programID;
public:
    CCWProgram();
    void compile(const char* vertStr, const char* fragStr);
    GLuint getProgram();
};
