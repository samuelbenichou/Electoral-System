//
// Created by samuel Benichou on 2020-01-19.
//

#ifndef HW5_EXCEPTION_H
#define HW5_EXCEPTION_H

#include <iostream>
#include <exception>

/*class Exception {
public:
    Exception() throw();
    Exception(const Exception& right) throw();
    Exception& operator=(const Exception& right) throw();
    virtual const char *what() const throw();
    virtual ~Exception() throw();
};*/

class idException : public exception{
public:
    virtual const char* what() const throw(){
        return "Please enter valid id";
    }
};

class nameError : public exception{
public:
    virtual const char* what() const throw(){
        return "Please enter valid name";
    }
};

class dataError : public exception{
public:
    virtual const char* what() const throw(){
        return "Please enter valid details";
    }
};

#endif //HW5_EXCEPTION_H
