#include "PaymentService.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

namespace TechnicalServices::Payment
{
	PaymentService::PaymentService()
	{
		purchase_history = {
			{"Kasim", "100A"},
			{}
		};
		//enter code to check if PURCHASE_HISTORY.txt file exists,
		//if not initialize with admin having all purchases and write the vector of structs to a text file named PURCHASE_HISTORY.txt
		//can also use a csv instead of a txt file

		//after finishing this, discard Shop and Items from Domain layer and interface UI directly to Technical Services

	}

	bool PaymentService::purchaseItem(std::string _itemid)
	{
		try
		{
			std::string _username = "_";
			char creditcardno[11];
			char cvv[4];
			while (!(_username == "Kasim" || _username == "Mark" || _username == "Shawn"))
			{
				std::cout << "\n\nEnter your correct username: \n";
				std::getline(std::cin, _username);
			}
			bool alreadypurchased = false;
			for (int i = 0; i < purchase_history.size(); ++i)
			{
				if (purchase_history[i].username == _username)
				{
					return true;
				}
			}
			std::cout << "\nEnter your credit card no: \n";
			std::cin.getline(creditcardno, 11);
			std::string _creditcardno(creditcardno);
			std::cout << "\nEnter CVV code: \n";
			std::cin.getline(cvv, 4);
			std::string _cvv(cvv);
			if (verifypaymentdetails(_username, _creditcardno, _cvv))
			{
				purchase_history.push_back({ _username, _itemid });
				std::ofstream output_file("./PURCHASE_HISTORY.txt");
				std::ostream_iterator<std::string> output_iterator(output_file, "\n");
				std::copy(purchase_history.begin(), purchase_history.end(), output_iterator);
				//enter code to save the purchase history to text file
				//done. save purchased items in the text file
				return true;
			}
			return false;
		}
		catch (int e)
		{
			return false;
		}
	}

	bool PaymentService::findPurchaseByName(std::string _username)
	{
		//enter code to update purchase_history vector from text file
		//done
		std::vector<std::string> tem_purchase_history;
		bool result = getFileContent("PURCHASE_HISTORY.txt", tem_purchase_history);
		if (result)
		{
			int n = 0;
			while (n < tem_purchase_history.size())
			{
				purchase_history.push_back({ tem_purchase_history[n],tem_purchase_history[n + 1] });
				n = n + 2;
				//group every two elements which username and itemid into purchase_history to update 
			}
		}

		for (int i = 0; i < purchase_history.size(); ++i)
		{
			if (purchase_history[i].username == _username)
			{
				return true;
			}
		}
		return false;
	}

	bool PaymentService::verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv)
	{
		if (creditcardno.length() == 10 && cvv.length() == 3)
		{
			return true;
		}
		return false;
	}

	bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
	{

		// Open the File
		std::ifstream in(fileName.c_str());

		// Check if object is valid
		if (!in)
		{
			std::cerr << "Cannot open the File : " << fileName << std::endl;
			return false;
		}

		std::string str;
		// Read the next line from File untill it reaches the end.
		while (std::getline(in, str))
		{
			// Line contains string of length > 0 then save it in vector
			if (str.size() > 0)
				vecOfStrs.push_back(str);
		}
		//Close The File
		in.close();
		return true;
	}
}
