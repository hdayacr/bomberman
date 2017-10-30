#include "Error.hpp"

End::End(std::string EndMessage) throw()
{
  this->_endMessage = EndMessage;
}

End::~End() throw()
{
}

char const	*End::what() const throw()
{
  return (this->_endMessage.c_str());
}
