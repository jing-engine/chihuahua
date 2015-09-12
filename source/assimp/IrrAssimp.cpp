#include "IrrAssimp.h"

#include <iostream>

using namespace irr;

IrrAssimp::IrrAssimp(irr::scene::ISceneManager* smgr) : Smgr(smgr), Cache(smgr->getMeshCache()), FileSystem(smgr->getFileSystem()), Importer(smgr)
{

}

IrrAssimp::~IrrAssimp()
{

}

irr::scene::IAnimatedMesh* IrrAssimp::getMesh(const io::path& path)
{
	scene::IAnimatedMesh* msh = Cache->getMeshByName(path);
	if (msh)
		return msh;

	io::IReadFile* file = FileSystem->createAndOpenFile(path);
	if (!file)
	{
		//os::Printer::log("Could not load mesh, because file could not be opened: ", path, ELL_ERROR);
		return 0;
	}

	if (isLoadable(path))
    {
        msh = Importer.createMesh(file);

        if (msh)
        {
            Cache->addMesh(path, msh);
            msh->drop();
        }
    }

	file->drop();

    /*
        if (!msh)
            os::Printer::log("Could not load mesh, file format seems to be unsupported", filename, ELL_ERROR);
        else
            os::Printer::log("Loaded mesh", filename, ELL_INFORMATION);
    */

	return msh;
}

irr::core::stringc IrrAssimp::getError()
{
    return Importer.Error;
}


bool IrrAssimp::isLoadable(irr::io::path path)
{
    return Importer.isALoadableFileExtension(path);
}