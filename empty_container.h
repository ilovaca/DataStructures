/* 
 * File:   Exists.h
 * Author: austin
 *
 * Created on August 16, 2015, 10:46 PM
 */

#ifndef EXISTS_H
#define	EXISTS_H

class empty_container : public std::runtime_error {
public:
    empty_container();

    empty_container(const std::string& s) : runtime_error(s) {
        std::cout << "bar foo" << std::endl;
    }
    virtual ~empty_container();
private:

};

#endif	/* EXISTS_H */

