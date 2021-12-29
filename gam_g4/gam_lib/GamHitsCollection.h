/* --------------------------------------------------
   Copyright (C): OpenGATE Collaboration
   This software is distributed under the terms
   of the GNU Lesser General  Public Licence (LGPL)
   See LICENSE.md for further details
   -------------------------------------------------- */

#ifndef GamHitsCollection_h
#define GamHitsCollection_h

#include <pybind11/stl.h>
#include "G4TouchableHistory.hh"
#include "GamVHitAttribute.h"

class GamHitsCollectionManager;

class GamHitsCollection : public G4VHitsCollection {
public:

    friend GamHitsCollectionManager;

    ~GamHitsCollection() override;

    void StartInitialization();

    void InitializeHitAttribute(std::string name);

    void InitializeHitAttributes(std::vector<std::string> names);

    void FinishInitialization();

    void CreateRootTupleForMaster();

    void CreateRootTupleForWorker();

    void FillToRoot();

    void Write();

    void Close();

    void SetFilename(std::string filename);

    std::string GetFilename() const { return fFilename; }

    std::string GetTitle() const { return fHitsCollectionTitle; }

    void SetTupleId(G4int id) { fTupleId = id; }

    G4int GetTupleId() const { return fTupleId; }

    virtual size_t GetSize() const override;

    std::vector<GamVHitAttribute *> &GetHitAttributes() { return fHitAttributes; }

    GamVHitAttribute *GetHitAttribute(std::string name);

    void ProcessHits(G4Step *step, G4TouchableHistory *touchable);

protected:

    // Can only be created by GamHitsCollectionManager
    GamHitsCollection(std::string collName);

    std::string fFilename;
    std::string fHitsCollectionName;
    std::string fHitsCollectionTitle;
    std::map<std::string, GamVHitAttribute *> fHitAttributeMap;
    std::vector<GamVHitAttribute *> fHitAttributes;
    G4int fTupleId;
    int fCurrentHitAttributeId;

};

#endif // GamHitsCollection_h
