#pragma once

#include <Entropy/Layers/Layer.h>
#include <Entropy/Math/Transform3D.h>
#include <Entropy/Tools/Log.h>

#include "../GameObject.h"

class GameLayer : public Entropy::Layer
{
public:
	GameLayer();
	~GameLayer();

	void OnUpdate() override;
	void OnEvent(Entropy::Event& e) override;

private:
	Entropy::Math::Mat4 _projection;

	std::vector<GameObject*> _gameObjects;
};
