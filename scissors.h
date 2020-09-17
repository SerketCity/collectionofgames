#include <string>

using namespace std;

/****************************************************************
*   STRUCTURE NAME: scissors
*
*   builds scissors object that inherits from tool
*
*
****************************************************************/

class Scissors : public Tool
{
        public:
                Scissors();
                int fight(Tool* opponent);
};

/****************************************************************
*   FUNCTION NAME: Scissors
*  Description: constructor for scissors object
*
*   PARAMETERS: none
*
*   RETURN VALUES: none
*
****************************************************************/

Scissors::Scissors()
{
        type = "SCISSORS";
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

int Scissors::fight(Tool* opponent)
{
        if(opponent->getType() == "SCISSORS")
        {
                return 0;
        } else
        if(opponent->getType() == "PAPER")
        {
                return 1;
        } else
        if(opponent->getType() == "ROCK")
        {
                return 2;
        }
}
