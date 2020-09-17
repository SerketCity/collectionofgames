#include <string>

using namespace std;

/****************************************************************
*   STRUCTURE NAME: rock
*
*   builds rock object that inherits from tool
*
*
****************************************************************/

class Rock : public Tool
{
	public:
		Rock();
		int fight(Tool* opponent);
};

/****************************************************************
*   FUNCTION NAME: Rock
*  Description: constructor for rock object
*
*   PARAMETERS: none
*
*   RETURN VALUES: none
*
****************************************************************/

Rock::Rock()
{
	type = "ROCK";
}

/****************************************************************
*   FUNCTION NAME: fight
*  Description: fights opponent object and determines if This 
*               object wins
*
*   PARAMETERS: Tool pointer 
*
*   RETURN VALUES: int
*
****************************************************************/

int Rock::fight(Tool* opponent)
{
	if(opponent->getType() == "ROCK")
	{
		return 0;
	} else
	if(opponent->getType() == "SCISSORS")
	{
		return 1;
	} else
	if(opponent->getType() == "PAPER")
	{
		return 2;
	} 	
}
