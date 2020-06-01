//
//  CCWProgram.cpp
//  LiveAppDemo
//
//  Created by ccwiner on 2020/6/1.
//  Copyright © 2020 com.LiveDemo. All rights reserved.
//

#include "CCWProgram.hpp"
#include <fstream>

using std::string;
using std::ifstream;

CCWProgram::CCWProgram(void) {
    programID = 0;
}

string CCWProgram::readFile(const char* fileLocation) {
    string content;
    ifstream fileStream(fileLocation, std::ios::in);

    if (!fileStream.is_open()) {
        printf("Failed to read %s! File doesn't exist.", fileLocation);
        return "";
    }

    string line = "";
    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

void CCWProgram::compile(const char* vertShaderPath, const char* fragShaderPath) {
    auto vertStr = readFile(vertShaderPath);
    auto fragStr = readFile(fragShaderPath);
    
    compileShader(vertStr.c_str(), fragStr.c_str());
}

void CCWProgram::compileShader(const char *vertStr, const char *fragStr) {
    programID = glCreateProgram();

    if (!programID)
    {
        printf("Error creating shader program!\n");
        return;
    }

    addShader(programID, vertStr, GL_VERTEX_SHADER);
    addShader(programID, fragStr, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glLinkProgram(programID);
    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(programID, sizeof(eLog), NULL, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }
}


void CCWProgram::addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
    GLuint theShader = glCreateShader(shaderType);

    const GLchar* theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
        printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
        return;
    }

    glAttachShader(theProgram, theShader);
}

void CCWProgram::clearProgram() {
    if (programID != 0)
    {
        glDeleteProgram(programID);
        programID = 0;
    }
}

CCWProgram::~CCWProgram()
{
    clearProgram();
}


GLuint CCWProgram::getProgram() {
    return programID;
}
