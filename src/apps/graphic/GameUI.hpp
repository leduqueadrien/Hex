
class GameUI
{
private:
	/* data */
public:
	GameUI(/* args */);
	virtual ~GameUI() = 0;

	virtual void displayBoard() = 0;
	virtual void getMove() = 0;
	//
};
