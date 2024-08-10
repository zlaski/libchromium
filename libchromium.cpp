// libchromium.cpp

#include "ui/base/resource/data_pack.h"
#include "base/files/file_path.h"

#include "libchromium.h"

struct PakFile {
    base::FilePath filePath;
    ui::DataPack dataPack;
    bool opened;

    PakFile(const char *pathSpec): opened(false), dataPack(ui::kScaleFactorNone)
    {
        filePath = filePath.AppendASCII(pathSpec);
        opened = dataPack.LoadFromPath(filePath);
    }
};

extern "C" struct PakFile *PakFileOpen(const char* name)
{
    struct PakFile *pf = new PakFile(name);
    if (pf->opened) {
        return pf;
    }

    delete pf;
    return nullptr;
}

extern "C" void PakFileClose(struct PakFile* pf)
{
    delete pf;
}

/// FUNCTION/CLASS DEFINITIONS ///

