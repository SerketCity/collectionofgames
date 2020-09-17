#include <string>

using namespace std;

/****************************************************************
*   STRUCTURE NAME: tool
*
*   builds a tool object to be used in rock, paper, scissors
*
*
****************************************************************/

class Tool
{
	protected:
		string type;

	public:
		Tool();
		string getType();
		virtual int fight(Tool* opponent) = 0;
};

/****************************************************************
*   FUNCTION NAME: Tool
*  Description: constructor for tool object
*
*   PARAMETERS: none
*
*   RETURN VALUES: none
*
****************************************************************/

Tool::Tool()
{
	type = "NULL";
}

/****************************************************************
*   FUNCTION NAME: getType
*  Description: returns the type of tool it is
*
*   PARAMETERS: none
*
*   RETURN VALUES: string
*
****************************************************************/

string Tool::getType()
{
	return type;
}
