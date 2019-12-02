#pragma once
#include <vector>
#include <iostream>
#include <string>

namespace TechnicalServices::Payment
{
	class PaymentService
	{
	public:
		PaymentService() = default;
		~PaymentService() = default;
		bool verifypaymentdetails(std::string username, std::string credicardno, std::string cvv);
	};
}
