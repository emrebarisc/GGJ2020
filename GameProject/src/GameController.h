#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

class GameController
{
public:
	static GameController* GetInstance()
	{
		if (instance_ == nullptr)
		{
			instance_ = new GameController();
		}

		return instance_;
	}

	void HandleRestartInput();

private:
	GameController();

	~GameController()
	{

	}

	static GameController* instance_;
};

#endif