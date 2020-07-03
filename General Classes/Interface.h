class Interface
{
	public:
		Interface()
		{
			line = "";
			style = 1;
		}
		void toggle(bool btoggle)
		{
			surpriseMe = btoggle;
		}
		void setStyle(int mstyle)
		{
			style = mstyle;
		}
		std::string messageBox(std::string lineArray[], int length)
		{
			for(int index = 0; index < length; index ++)
				line += lineArray[index] + " ";
			if(line != "")
			{
				displayMessage();
				return line;
			}
			else
				return "Error: Empty string supplied as argument";
		}
		std::string messageBox(std::string mline)
		{
			line = mline;
			if(line != "")
			{
				displayMessage();
				return line;
			}
			else
				return "Error: Empty string supplied as argument";
		}
		
	protected:
		std::string line;
		int style;
		bool surpriseMe;
		
		void displayMessage()
		{
			std::string styleLine = "";
			if(style == 1 || style != 2 && style != 3 && style != 4 && style != 5)
				styleLine = "----------------------------------------------------------------------";
			else if(style == 2)
				styleLine = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			else if(style == 3)
				styleLine = "**********************************************************************";
			else if(style == 4)
				styleLine = "=====================================================================";
			else if(style == 5)
				styleLine = "......................................................................";
			std::cout << "\n" << styleLine << "\n"						
			<< line 
			<< "\n" << styleLine << "\n";
			if(surpriseMe == true)
			{
				if(style == 5)
					style = 0;
				if(style < 6)
					style += 1;
			}
			return;
		}
};