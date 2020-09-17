#include <string>

using namespace std;

/****************************************************************
*   STRUCTURE NAME: paper
*
*   builds paper object that inherits from tool
*
*
****************************************************************/

class Paper : public Tool
{
        public:
                Paper();
                int fight(Tool* opponent);
};

/****************************************************************
*   FUNCTION NAME: Paper
*  Description: constructor for paper object
*
*   PARAMETERS: none
*
*   RETURN VALUES: none
*
****************************************************************/

Paper::Paper()
{
        type = "PAPER";
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

int Paper::fight(Tool* opponent)
{
        if(opponent->getType() == "PAPER")
        {
                return 0;
        } else
        if(opponent->getType() == "ROCK")
        {
                return 1;
        } else
        if(opponent->getType() == "SCISSORS")
        {
                return 2;
        }
}

