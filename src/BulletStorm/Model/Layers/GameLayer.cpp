#include "GameLayer.h"

#include <Entropy/Platform/OpenGL/ResourseManager.h>

GameLayer::GameLayer() : Layer("GAME_LAYER")
{
	Projection = Entropy::Math::Ortho(0.0f, 1280.0f, 720.0f, 0.0f, 0.0f, 1.0f);
}

void GameLayer::OnUpdate()
{
	//Entropy::log::message("GAME_LAYER", "Update");
}

void GameLayer::OnEvent(Entropy::Event& e)
{
	Entropy::log::trace("GAME_LAYER", e);
}
