#include "GameLayer.h"

#include <Entropy/Platform/OpenGL/ResourseManager.h>

#include "../Player.h"

GameLayer::GameLayer() : Layer("GAME_LAYER")
{
	_projection = Entropy::Math::Ortho(0.0f, 1280.0f, 720.0f, 0.0f, 0.0f, 1.0f);

	_gameObjects.push_back(new Player(640.0f, 100.0f, 0.0f, 0.0f, 1, -2.0f, -2.0f, 4.0f, 4.0f));
}

GameLayer::~GameLayer()
{
	for (GameObject* object : _gameObjects)
		delete object;
}

void GameLayer::OnUpdate()
{
	//Entropy::log::message("GAME_LAYER", "Update");
	for (GameObject* object : _gameObjects)
	{
		object->OnUpdate();
		object->OnRender();
	}
}

void GameLayer::OnEvent(Entropy::Event& e)
{
	//Entropy::log::trace("GAME_LAYER", e);

	if (!e.isHandled())
	{
		for (GameObject* object : _gameObjects)
		{
			object->OnEvent(e);
			if (e.isHandled())
				break;
		}
	}
}
