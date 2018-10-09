//
// Created by Владимир on 09.10.2018.
//

#ifndef UNTITLED_G4ELEMENT_H
#define UNTITLED_G4ELEMENT_H

#include <string>

class G4Element{

};

class G4NistManager{
    static G4NistManager* nist;
public:
    static G4NistManager* Instance(){
        if(nist == nullptr)
            nist = new G4NistManager;
        return nist;
    }
    G4Element* FindOrBuildElement(const std::string &name){}

};
#endif //UNTITLED_G4ELEMENT_H
