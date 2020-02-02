#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

class GameManager
{
public:
	static GameManager* GetInstance()
	{
		if (instance_ == nullptr)
		{
			instance_ = new GameManager();
		}

		return instance_;
	}

	void Restart();
	void GameOver();

	bool GetIsGameOver() const
	{
		return isGameOver_;
	}

private:
	GameManager() : isGameOver_(false)
	{

	}

	~GameManager()
	{

	}

	static GameManager* instance_;

	bool isGameOver_;
};

#endif