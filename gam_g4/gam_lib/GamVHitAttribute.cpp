/* --------------------------------------------------
   Copyright (C): OpenGATE Collaboration
   This software is distributed under the terms
   of the GNU Lesser General  Public Licence (LGPL)
   See LICENSE.md for further details
   -------------------------------------------------- */

#include "GamVHitAttribute.h"
#include "GamTBranch.h"

GamVHitAttribute::GamVHitAttribute(std::string vname, char vtype) {
    fHitAttributeName = vname;
    fHitAttributeType = vtype;
}

GamVHitAttribute::~GamVHitAttribute() {
}

void GamVHitAttribute::ProcessHits(G4Step *step, G4TouchableHistory *history) {
    fProcessHitsFunction(this, step, history);
}

std::vector<double> &GamVHitAttribute::GetDValues() {
    Fatal("NOT HERE");
}

std::vector<int> &GamVHitAttribute::GetIValues() {
    Fatal("NOT HERE");
}

std::vector<std::string> &GamVHitAttribute::GetSValues() {
    Fatal("NOT HERE");
}

std::vector<G4ThreeVector> &GamVHitAttribute::Get3Values() {
    Fatal("NOT HERE");
}
