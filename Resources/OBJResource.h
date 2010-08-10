// OBJ Model resource.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// Modified by Anders Bach Nielsen <abachn@daimi.au.dk> - 21. Nov 2007
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OBJ_MODEL_RESOURCE_H_
#define _OBJ_MODEL_RESOURCE_H_

#include <Resources/IModelResource.h>
#include <Resources/IResourcePlugin.h>
#include <Geometry/Material.h>
#include <Geometry/Mesh.h>

#include <string>
#include <vector>
#include <map>

namespace OpenEngine {
namespace Resources {

using namespace OpenEngine::Geometry;
using namespace std;

/**
 * OBJ-model resource.
 *
 * @class OBJResource OBJResource.h "OBJResource.h"
 */
class OBJResource : public IModelResource {
private:

    // inner material structure

    string file;                      //!< obj file path
    MeshPtr mesh;                       //!< the mesh
    ISceneNode* node;                 //!< the scene node
    map<string, MaterialPtr> materials; //!< resources material map

    // helper methods
    void Error(int line, string msg);
    void LoadMaterialFile(string file);

public:
    OBJResource(string file);
    virtual ~OBJResource();
    void Load();
    void Unload();
    //FaceSet* GetFaceSet();
    ISceneNode* GetSceneNode();
};

/**
 * OBJ-model resource plug-in.
 *
 * @class OBJPlugin OBJResource.h "OBJResource.h"
 */
class OBJPlugin : public IResourcePlugin<IModelResource> {
public:
	OBJPlugin();
    IModelResourcePtr CreateResource(string file);
};

} // NS Resources
} // NS OpenEngine

#endif // _OBJ_MODEL_RESOURCE_H_
