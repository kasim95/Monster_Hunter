#include "PaymentService.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

namespace TechnicalServices::Payment
{
	bool PaymentService::verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv)
	{
		if (creditcardno.length() == 10 && cvv.length() == 3)
		{
			return true;
		}
		return false;
	}
}
