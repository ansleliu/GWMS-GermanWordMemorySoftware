#include <qglobal.h>


class CoreLibInitializer
{
public:
    CoreLibInitializer()
    {
        Q_INIT_RESOURCE(CommonIcons);
    }
};

CoreLibInitializer coreInitializer;



