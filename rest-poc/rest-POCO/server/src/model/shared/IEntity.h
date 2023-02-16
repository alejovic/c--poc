//
// Created by avictoria on 1/02/23.
//

#ifndef SERVER_MODEL_IENTITY_H
#define SERVER_MODEL_IENTITY_H

#include <string>

namespace Model {
    namespace Shared {

        class IEntity {
        public:
            virtual std::string identity() const = 0;

            virtual bool operator==(const IEntity &other) = 0;

            virtual bool operator!=(const IEntity &other) = 0;

        };


    }
}

#endif //SERVER_MODEL_IENTITY_H
