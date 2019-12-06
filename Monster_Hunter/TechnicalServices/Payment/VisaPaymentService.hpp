#pragma once
#include <string>
#include "PaymentServiceHandler.hpp"

namespace TechnicalServices::Payment
{

	class VisaPaymentService : public PaymentServiceHandler
	{
	public:
		VisaPaymentService();
		~VisaPaymentService() noexcept override;
		bool verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv) override;
	};

	inline VisaPaymentService::VisaPaymentService()
	{}

	inline VisaPaymentService::~VisaPaymentService() noexcept
	{}

	inline bool VisaPaymentService::verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv)
	{
		if (creditcardno.length() == 10 && cvv.length() == 3 && creditcardno[0] == '4')
		{
			return true;
		}
		return false;
	}

}
