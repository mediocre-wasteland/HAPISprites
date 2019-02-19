#pragma once
#include "Entity.h"
class PlayerEntity :
	public Entity
{
public:
	PlayerEntity(std::string &filename);
	~PlayerEntity();

	virtual void Update() override;

	virtual eSide GetSide() const override { return mSide; } 
	virtual eDirection GetDirection() const override { return  mDirection; }

private:
	int mMaxJumpLength{ 80 }; // the max amount of updates the player can move vertically from a jump
	bool mIsJumping{ false }; // whether or not the space bar is held and player has not reached max jump height
	bool mIsOnGround{ false }; // whether or not the player has terrain directly below them
	float mHSpeed{ 3 }; // the horizontal speed, how fast the player will move along the x axis
	float mJumpSpeed{ 1.5f }; // the upwards speed, how fast the player will move positively along the y axis
	float mGravity{ 0.25 }; // how many pixels the player will fall per update
	int mTimeJumped{ 0 }; // how many updates the player has moved vertically since start of jump
	bool mHasSecondJump{ false }; // whether or not the player has a second jump they can deploy mid air
	int mTimeFallen{ 0 }; // how many updates have passed since the player has started falling
	int mFallingCooldown{ 25 }; // how many updates must pass before the second jump may be initiated
};

