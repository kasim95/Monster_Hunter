#pragma once
#include <string>
#include "PaymentServiceHandler.hpp"

namespace TechnicalServices::Payment
{

	class MastercardPaymentService : public PaymentServiceHandler
	{
	public:
		MastercardPaymentService();
		~MastercardPaymentService() noexcept override;
		bool verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv) override;
	};

	inline MastercardPaymentService::MastercardPaymentService()
	{}

	inline MastercardPaymentService::~MastercardPaymentService() noexcept
	{}

	bool MastercardPaymentService::verifypaymentdetails(std::string username, std::string creditcardno, std::string cvv)
	{
		if (creditcardno.length() == 10 && cvv.length() == 3 && creditcardno[0] == '5')
		{
			return true;
		}
		return false;
	}
}
