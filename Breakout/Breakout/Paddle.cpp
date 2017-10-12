#include "Paddle.h"
#include "SingleImageController.h"
#include "Vector2.h"

Paddle::Paddle(float x, float y) : Entity(x, y)//, int width, int height, float collXOffset, float collYOffset) : Entity(x, y, width, height, collXOffset, collYOffset, false)
{
	velocity = new Vector2(0.0f, 0.0f);
	speed = 10.0f;
	visualComponent = new SingleImageController();
}


Paddle::~Paddle()
{
	delete velocity;
	velocity = nullptr;
}

/*
void Player::AddVelocity(float x, float y)
{
	velocity->Add(x, y);
	if (velocity->GetX() > maxSpeed)
	{
		velocity->SetX(maxSpeed);
	}
	else if (velocity->GetX() < -maxSpeed)
	{
		velocity->SetX(-maxSpeed);
	}
	if (velocity->GetY() > terminalVelocity)
	{
		velocity->SetY(terminalVelocity);
	}
	else if (velocity->GetY() < -maxJumpSpeed)
	{
		velocity->SetY(-maxJumpSpeed);
	}
}
void Player::AddNewVelocity(float x, float y)
{
	newVelocity->Add(x, y);
}
void Player::SetVelocityX(float x)
{
	velocity->SetX(x);
}

void Player::SetVelocityY(float y)
{
	velocity->SetY(y);
}
*/
void Paddle::Update(std::vector<Entity*> entityList)
{
	//update logic here
}

/*
PlayerState::Direction Player::MoveHorizontal(std::vector<Entity*> entityList)
{
	float movementX = velocity->GetX() * deltaTime;
	SetPosX(GetPosX() + movementX);
	return HandleHorizontalCollisions(entityList);
}

bool Player::CheckCollisions(Collider* other)
{
	if ((GetCollider()->GetPosX() + GetCollider()->GetWidth() < other->GetPosX()) || (GetCollider()->GetPosX() > (other->GetPosX() + other->GetWidth())) ||
		(GetCollider()->GetPosY() + GetCollider()->GetHeight() < other->GetPosY()) || (GetCollider()->GetPosY() > (other->GetPosY() + other->GetHeight())))
	{
		return false;
	}
	return true;
}
*/

SingleImageController* Paddle::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}

/*
void Player::GetInput(PlayerActions action, InputType type)
{
	PlayerState* newState = currentState->GetInput(*this, action, type);
	if (newState != nullptr)
	{
		delete currentState;
		currentState = newState;
	}
}
*/