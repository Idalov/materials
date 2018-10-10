#include <iostream>
#include "include/G4Element.h"
#include "include/G4Material.h"

G4Material* sample_mat;
std::vector<G4Material*>* materials;
G4NistManager* nist;

void setMaterial(const std::string &m_name){
    for (auto& item: *materials)
        if(m_name==item->getM_name())
            sample_mat = item;
}

G4Material* addSiO2(){
    auto mat = new G4Material("SiO2",1*g/cm3,2,kStateSolid);
    mat->AddElement(nist->FindOrBuildElement("Si"),1);
    mat->AddElement(nist->FindOrBuildElement("O"),2);
    return mat;
}

int main() {
    nist = G4NistManager::Instance();

    materials = new std::vector<G4Material*>();

    materials->push_back(addSiO2());            //возвращаемое значение ваших функций передавать в качестве аргумента этой  функции
//    materials->push_back(...);
//    materials->push_back(...);
//    materials->push_back(...);
//    materials->push_back(...);
    G4Material::Initialize();
    return 0;
}