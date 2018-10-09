//
// Created by Владимир on 09.10.2018.
//

#include "../include/G4Material.h"

std::vector<G4Material*>* G4Material::vector = nullptr;

int G4Material::getNComp() const {
    return nComp;
}

double G4Material::getFract() const {
    return fract;
}

const std::string &G4Material::getM_name() const {
    return m_name;
}
