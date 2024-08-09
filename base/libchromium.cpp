// libchromium.cpp

#include "ui/base/resource/data_pack.h"
#include "base/files/file_path.h"
#include "base/strings/string_util.h"
#include "base/strings/string_util_impl_helpers.h"
#include "base/win/scoped_handle.h"
#include "base/threading/scoped_blocking_call.h"
#include "base/synchronization/lock_impl.h"

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

extern "C" BOOL CloseHandle(HANDLE hObject);

/// FUNCTION/CLASS DEFINITIONS ///

namespace std {
    ostream& operator<<(ostream& o, const u16string& p) {
        o << "TEST" << endl;  // TODO
        return o;
    }

    ostream& operator<<(ostream& o, const wstring& p) {
        o << "TEST" << endl;  // TODO
        return o;
    }

    ostream& operator<<(ostream& o, wstring_view p) {
        o << "TEST" << endl;  // TODO
        return o;
    }

    errno_t rand_s(unsigned int* randomValue);
}

namespace base {

    namespace win {
        bool HandleTraits::CloseHandle(HANDLE h) {
            return ::CloseHandle(h);
        }
    }

    Location FROM_HERE;

    ScopedBlockingCall::ScopedBlockingCall(const Location& from_here,
                                           BlockingType blocking_type) {}
    ScopedBlockingCall::~ScopedBlockingCall() {}

    int RandInt(int min, int max) {
        unsigned int r;
        rand_s(&r);
        return r;
    }

    namespace internal {
        LockImpl::LockImpl(void) {}
        void LockImpl::Lock(void) {}
    }

}  // namespace base
