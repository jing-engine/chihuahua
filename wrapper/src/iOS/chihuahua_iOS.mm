#include "chihuahua_iOS.h"
#include "irrlicht.h"
#include "../source/irrlicht/os.h"
#include "../source/irrlicht/CLogger.h"

#import <UIKit/UIKit.h>

using namespace irr;
using namespace core;

extern video::IVideoDriver* driver;
extern scene::ISceneManager* smgr;
extern scene::ISceneNode* arRootNode; // arRootNode's parent = dummy node
extern scene::ICameraSceneNode* camera;
extern io::IFileSystem* fs;
extern int screenWidth, sceenHeight;

void Scene_initializeFileSystem()
{
    os::Printer::Logger = new CLogger(NULL);
    
    printf("initializeFileSystem()");
    
    NSBundle* Bundle = [NSBundle mainBundle];
    NSString* BundlePath = [Bundle bundlePath];
    
    core::stringc NewPath = [BundlePath cStringUsingEncoding:NSASCIIStringEncoding];
    
    fs->changeWorkingDirectoryTo(NewPath);
}


