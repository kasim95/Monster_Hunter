#pragma once
#include <iostream>
#include <string>

namespace TechnicalServices::Logging
{
	class LoggerHandler
	{
	public:
		LoggerHandler(std::ostream & loggingStream = std::clog);
		LoggerHandler(const LoggerHandler & original) = default;
		LoggerHandler(LoggerHandler && original) = default;
	
		virtual LoggerHandler & operator<< (const std::string & message) = 0;
		virtual ~LoggerHandler() noexcept = 0;

	protected:
		LoggerHandler & operator=(const LoggerHandler & rhs) = default;
		LoggerHandler & operator=(LoggerHandler && rhs) = default;
		std::ostream & _loggingStream;
	};

	inline LoggerHandler::~LoggerHandler() noexcept
	{}

	inline LoggerHandler::LoggerHandler(std::ostream & loggingStream)
		: _loggingStream(loggingStream)
	{}
}