#ifndef OREZ_IO_GLOBAL_H
#define OREZ_IO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OREZ_IO_LIBRARY)
#  define OREZ_IOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define OREZ_IOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // OREZ_IO_GLOBAL_H
