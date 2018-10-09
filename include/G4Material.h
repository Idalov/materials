//
// Created by Владимир on 09.10.2018.
//

#ifndef UNTITLED_G4MATERIAL_H
#define UNTITLED_G4MATERIAL_H

#include <string>
#include <vector>
#include <iostream>
#include "global.h"
#include "G4Element.h"

class G4Material{
    int nComp;
    double fract;
    std::string m_name;
public:
    int getNComp() const;

    double getFract() const;

    const std::string &getM_name() const;

private:
    static std::vector<G4Material*>* vector;
public:
    G4Material(const std::string &name,double desity, int nComponents, G4State state){
        nComp = nComponents;
        fract = 0;
        m_name = name;
        if(vector == nullptr)
            vector = new std::vector<G4Material*>();
        vector->push_back(this);
    }


    void AddElement(G4Element* element, double fraction){
        nComp--;
        fract+=fraction;
    }

    void AddElement(G4Element* element, int nAtoms){
        nComp--;
        fract=(fract==0 || fract == 1.0)?1.0:2.;
    }

    static void Initialize(){
        for(auto & item: *vector)
            try {
                if (item->getNComp()!=0) {
                    std::cout<<"Incorrect nComponent = " << item->getNComp()<<'\n';
                    throw 1;
                }
                    if (item->getFract()>=1.001 || item->getFract()<=0.999) {
                    std::cout<<"Incorrect fract = " << item->getFract()<<'\n';
                    throw 1;

                }delete item;

            }catch (int e){
                std::cout<<"Incorrect Material " << item->m_name<< " Abort()\n";
                abort();
            }
            delete vector;
        std::cout<<"All Correct!! Success!!\n";
    }


};
#endif //UNTITLED_G4MATERIAL_H
