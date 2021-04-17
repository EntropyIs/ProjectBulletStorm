#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>
#include <Entropy/Platform/OpenGL/ResourseManager.h>

#include "Model/Layers/GameLayer.h"

class Sandbox : public Entropy::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox(){}

	void Init(bool _debug) override
	{
		Entropy::log::init(_debug);
		Entropy::log::header("APP", "Entropy Engine: Default Initalization.");

		Entropy::Graphics::ResourceManager::LoadShader("ColorShader", "Assets/Shaders/v2DBaseShader.glsl", "Assets/Shaders/f2DColorShader.glsl");

		_running = true;
	}
};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}