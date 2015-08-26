/* 
 * File:   ElementExistsException.h
 * Author: austin
 *
 * Created on August 8, 2015, 8:34 PM
 */

#ifndef ELEMENTEXISTSEXCEPTION_H
#define	ELEMENTEXISTSEXCEPTION_H
#include <stdexcept>
#include <string>
#include <iostream>
class ElementExistsException : public std::logic_error{
public:
    ElementExistsException(const std::string& s ): logic_error(s){
        std::cout<<s<<std::endl;
    }
    ElementExistsException(const ElementExistsException& orig) = default;
    virtual ~ElementExistsException() = default;
private:
    
};

#endif	/* ELEMENTEXISTSEXCEPTION_H */

