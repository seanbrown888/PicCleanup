// PicCleanup.cpp :
//

#include <iostream>

#include "../PicCleanupLib/RecursiveFileListingProvider.h"
#include "../PicCleanupLib/FileOnDiskMover.h"
#include "../PicCleanupLib/PicCleanupBL.h"

int main()
{   
    RecursiveFileListingProvider fileProvider;
    FileOnDiskMover fileMover;

    PicCleanupBL bl(fileProvider, fileMover);

    bl.cleaner().cleanup("C:\\PictureDir", {".JPG", ".PNG"} );
}

