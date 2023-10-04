#pragma once
#include <exception>
#include <iostream>
#include <string_view>

class ExceptionRessourceIntrouvable : public std::exception
{
public:
	ExceptionRessourceIntrouvable(std::string_view const& chemin);
	virtual const char* what() const noexcept override;


protected:

private:
	std::string messageErreur{};
};

