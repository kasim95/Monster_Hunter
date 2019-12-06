#pragma once
#include <string>

namespace TechnicalServices::Payment
{
	class PaymentServiceHandler
	{
	public:
		PaymentServiceHandler() = default;
		virtual ~PaymentServiceHandler() noexcept = 0;
		virtual bool verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv);
	};

	inline PaymentServiceHandler::~PaymentServiceHandler() noexcept
	{}

	inline bool PaymentServiceHandler::verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv)
	{
		return false;
	}
}
