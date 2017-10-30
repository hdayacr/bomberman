#ifndef ERROR_HPP__
# define ERROR_HPP__

# include <iostream>
# include <exception>
# include <string>

class End: public std::exception
{
public:
  End(std::string const endMessage = "") throw();
  virtual ~End() throw();

  virtual char const	*what() const throw();
private:
  std::string	_endMessage;
};

#endif
