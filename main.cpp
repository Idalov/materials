#include <iostream>
#include "include/G4Element.h"
#include "include/G4Material.h"

int main() {
    G4NistManager* nist = G4NistManager::Instance();

    auto mat = new G4Material("H2O",2*g/cm3,2,kStateSolid);
    mat->AddElement(nist->FindOrBuildElement("H"),2);
    mat->AddElement(nist->FindOrBuildElement("O"),1);

    auto mat2 = new G4Material("BGO", 3*g/cm3,3,kStateSolid);
    mat2->AddElement(nist->FindOrBuildElement("Bi"),50*perCent);
    mat2->AddElement(nist->FindOrBuildElement("Ge"),40*perCent);
    mat2->AddElement(nist->FindOrBuildElement("O"),10*perCent);

    G4Material::Initialize();
    return 0;
}