#include "ecpch.h"
#include "ResourseManager.h"

std::unordered_map<std::string, Entropy::Graphics::GLShader> Entropy::Graphics::ResourceManager::_shaders;

Entropy::Graphics::GLShader& Entropy::Graphics::ResourceManager::LoadShader(std::string name, const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometaryShaderPath)
{
	_shaders[name] = Entropy::Graphics::GLShader(vertexShaderPath, fragmentShaderPath, geometaryShaderPath);
	return _shaders[name];
}

Entropy::Graphics::GLShader& Entropy::Graphics::ResourceManager::GetShader(std::string name)
{
	return _shaders[name];
}
