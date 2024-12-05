#ifndef TARIF_H
#define TARIF_H

#include <string>

struct Call {
    std::string number;   
    std::string date;      
    std::string time;     
    int duration;          
    std::string tariff;    
    double cost;           
};

#endif 
