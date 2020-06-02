//
//  CCWProgram.hpp
//  LiveAppDemo
//
//  Created by ccwiner on 2020/6/1.
//  Copyright © 2020 com.LiveDemo. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <GLKit/GLKit.h>
#include <iostream>
#include <string>

class CCWProgram {
    std::string readFile(const char* fileLocation);
    void compileShader(const char* vertStr, const char* fragStr);
    void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType, GLuint *shaderID);
    void clearProgram();
    
    GLuint programID;
    GLuint vertShader, fragShader;
public:
    CCWProgram();
    ~CCWProgram();

    void compile(const char* vertPath, const char* fragPath);
    int getUniformLocation(const char* uniformName);
    int getAttributeIndex(const char* attributeName);
    GLuint getProgram();
};
