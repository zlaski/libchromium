#pragma once
// Public interface

#ifdef __cplusplus
extern "C" {
#endif

struct PakFile *PakFileOpen(const char *name);

void PakFileClose(struct PakFile *pf);

#ifdef __cplusplus
}
#endif
