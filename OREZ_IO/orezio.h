#ifndef OREZIO_H
#define OREZIO_H

#include "orez_io_global.h"
#include "../common.h"

/**
 * @brief The OREZ_io class:文件读取模块
 */

class OREZ_IOSHARED_EXPORT OrezIO
{

public:
    OrezIO();
    PointCloudT::Ptr ascToPCD(const std::string ascPath);
    PointCloudTRGB::Ptr loadPCDRGB(const std::string &str);
    PointCloudT::Ptr loadPCD(const std::string &str);
};

#endif // OREZIO_H
