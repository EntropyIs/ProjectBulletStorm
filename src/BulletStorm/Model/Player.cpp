#include "Player.h"

#include "Entropy/Tools/API.h"
#include "Entropy/Tools/Log.h"

void Player::OnEvent(Entropy::Event& e)
{
	Entropy::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Entropy::KeyPressedEvent>(BIND_EVENT_FUNCTION(Player::OnKeyPressed));
	dispatcher.Dispatch<Entropy::KeyReleasedEvent>(BIND_EVENT_FUNCTION(Player::OnKeyReleased));
}

bool Player::OnKeyPressed(Entropy::KeyPressedEvent& e)
{
	Entropy::log::trace("PLAYER", e);
	return false;
}

bool Player::OnKeyReleased(Entropy::KeyReleasedEvent& e)
{
	Entropy::log::trace("PLAYER", e);
	return false;
}
